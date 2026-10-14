import pyautogui
from pynput import mouse, keyboard
import threading
import time

jitter_active = False      # Ob linke Maustaste gedrückt wird
jitter_enabled = False     # Ob Jitter per Hotkey aktiviert ist
running = True

def jitter():
    global jitter_active, jitter_enabled, running
    while running:
        if jitter_enabled and jitter_active:
            pyautogui.moveRel(5, 0, duration=0)
            pyautogui.moveRel(-5, 0, duration=0)
        time.sleep(0.0000001)

def on_click(x, y, button, pressed):
    global jitter_active
    if button == mouse.Button.left:
        jitter_active = pressed

def on_press(key):
    global jitter_enabled, running
    if key == keyboard.Key.f8:
        jitter_enabled = not jitter_enabled
        print(f"Jitter {'AKTIVIERT' if jitter_enabled else 'DEAKTIVIERT'}")
    elif key == keyboard.Key.esc:
        print("Beende Programm...")
        running = False
        return False  # Stoppt Listener

# Jitter-Thread starten
thread = threading.Thread(target=jitter, daemon=True)
thread.start()

# Listener starten
mouse_listener = mouse.Listener(on_click=on_click)
keyboard_listener = keyboard.Listener(on_press=on_press)

mouse_listener.start()
keyboard_listener.start()

keyboard_listener.join()