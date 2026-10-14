import time
import spotipy
from spotipy.oauth2 import SpotifyOAuth
from pypresence import Presence
import os
from dotenv import load_dotenv
import re
from bisect import bisect_right
from spotipy.exceptions import SpotifyException

load_dotenv()

SPOTIFY_CLIENT_ID = os.getenv("SPOTIFY_CLIENT_ID")
SPOTIFY_CLIENT_SECRET = os.getenv("SPOTIFY_CLIENT_SECRET")
SPOTIFY_REDIRECT_URI = os.getenv("SPOTIFY_REDIRECT_URI")
DISCORD_CLIENT_ID = os.getenv("DISCORD_CLIENT_ID")

# Songname -> LRC-Datei
LYRICS_FILES = {
    "Blind": r"C:\Users\Leon\HoMe\Leons_Privates_Zeug\Spotify_Discord_Lyrics\Musik\Blind.lrc",
    "Impostor Syndrome" : r"C:\Users\Leon\HoMe\Leons_Privates_Zeug\Spotify_Discord_Lyrics\Musik\Impostor_Syndrom.lrc",
    "Nur ein Wort": r"C:\Users\Leon\HoMe\Leons_Privates_Zeug\Spotify_Discord_Lyrics\Musik\Von_hier_an_Blind.lrc", 
    "Kaftan": r"C:\Users\Leon\HoMe\Leons_Privates_Zeug\Spotify_Discord_Lyrics\Musik\Kaftan.lrc",
}

lyrics_cache = {}
TIMESTAMP_PATTERN = re.compile(r"\[(\d+):(\d+(?:\.\d+)?)\]")
META_PATTERN = re.compile(r"^\[[a-zA-Z]+:.*\]$")
LYRIC_SYNC_OFFSET_MS = 350
POLL_INTERVAL_SECONDS = 0.5

def parse_lrc_file(path):
    lyrics = []

    with open(path, "r", encoding="utf-8") as file:
        for line in file:
            line = line.strip()

            if not line or META_PATTERN.match(line):
                continue

            timestamps = TIMESTAMP_PATTERN.findall(line)
            if not timestamps:
                continue

            text = TIMESTAMP_PATTERN.sub("", line).strip()
            if text:
                for minutes, seconds in timestamps:
                    progress_ms = int((int(minutes) * 60 + float(seconds)) * 1000)
                    lyrics.append((progress_ms, text))

    lyrics.sort(key=lambda item: item[0])

    return lyrics


def get_current_lyric(progress_ms, lyrics):
    if not lyrics:
        return ""

    timestamps = [timestamp_ms for timestamp_ms, _ in lyrics]
    index = bisect_right(timestamps, progress_ms) - 1
    return "" if index < 0 else lyrics[index][1]


sp = spotipy.Spotify(
    auth_manager=SpotifyOAuth(
        client_id=SPOTIFY_CLIENT_ID,
        client_secret=SPOTIFY_CLIENT_SECRET,
        redirect_uri=SPOTIFY_REDIRECT_URI,
        scope="user-read-playback-state user-read-currently-playing"
    )
)

rpc = Presence(DISCORD_CLIENT_ID)
rpc.connect()

last_rpc_text = None
last_track_id = None

while True:
    try:
        playback = sp.current_playback()
    except SpotifyException as exc:
        if exc.http_status == 429:
            retry_after = 60
            if getattr(exc, "headers", None):
                retry_after = int(exc.headers.get("Retry-After", retry_after))

            print(f"Spotify-Rate-Limit erreicht. Erneuter Versuch in {retry_after} s.")
            time.sleep(retry_after)
            continue

        print(f"Spotify-Abfrage fehlgeschlagen: {exc}")
        time.sleep(POLL_INTERVAL_SECONDS)
        continue
    except Exception as exc:
        print(f"Spotify-Abfrage fehlgeschlagen: {exc}")
        time.sleep(POLL_INTERVAL_SECONDS)
        continue

    if not playback or not playback.get("item"):
        print("Nichts läuft gerade.")

        try:
            rpc.update(
                details="Spotify läuft gerade nicht",
                state="Keine Lyrics"
            )
        except Exception as exc:
            print(f"Discord-RPC-Update fehlgeschlagen: {exc}")

        time.sleep(POLL_INTERVAL_SECONDS)
        continue

    track = playback["item"]

    track_id = track["id"]
    track_name = track["name"]
    artists = ", ".join(artist["name"] for artist in track["artists"])
    progress_ms = playback["progress_ms"]
    duration_ms = track["duration_ms"]
    is_playing = playback["is_playing"]


    if track_id != last_track_id:
        discord_start = time.time() - (progress_ms / 1000)
        print("Song:", track_name)
        print("Künstler:", artists)
        print("Dauer:", duration_ms, "ms")
        print("-" * 40)

        last_track_id = track_id

    if not is_playing:
        try:
            rpc.update(
                details="Spotify pausiert",
                state=f"{track_name} - {artists}"[:128]
            )
        except Exception as exc:
            print(f"Discord-RPC-Update fehlgeschlagen: {exc}")

        time.sleep(POLL_INTERVAL_SECONDS)
        continue

    if track_name not in LYRICS_FILES:
        print("Keine Lyrics-Datei für diesen Song gefunden.")

        try:
            rpc.update(
                details="Keine Lyrics-Datei gefunden",
                state=f"{track_name} - {artists}"[:128]
            )
        except Exception as exc:
            print(f"Discord-RPC-Update fehlgeschlagen: {exc}")

        time.sleep(10)
        continue

    # Lyrics nur einmal laden und dann im Cache speichern
    if track_name not in lyrics_cache:
        path = LYRICS_FILES[track_name]
        lyrics_cache[track_name] = parse_lrc_file(path)

    lyrics = lyrics_cache[track_name]

    adjusted_progress_ms = min(duration_ms, progress_ms + LYRIC_SYNC_OFFSET_MS)
    line = get_current_lyric(adjusted_progress_ms, lyrics)

    #print("Lyric:", line)

    

    rpc_text = f"{line} | {track_name} - {artists}"
    rpc_details = line.strip() or "Keine Lyrics"

    # Nur aktualisieren, wenn sich die Zeile geändert hat
    if rpc_text != last_rpc_text:
        try:
            rpc.update(
                details=rpc_details[:128],
                state=f"{track_name} - {artists}"[:128],
                start=discord_start,
            )
        except Exception as exc:
            print(f"Discord-RPC-Update fehlgeschlagen: {exc}")
        else:
            last_rpc_text = rpc_text

    time.sleep(POLL_INTERVAL_SECONDS)