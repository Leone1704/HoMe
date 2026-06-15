#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int nummer;
    float wert;
} Messwert;

long anzahl_datensaetze(FILE *datei) {
    long dateigroesse;
    fseek(datei, 0, SEEK_END);
    dateigroesse = ftell(datei);

    return dateigroesse / sizeof(Messwert);
}

void sortiert_einfuegen(FILE *bin, Messwert neu) {
    Messwert temp;
    long pos = 0;
    long anzahl;


    rewind(bin);

    while (fread(&temp, sizeof(Messwert), 1, bin) == 1) {
        if (temp.nummer > neu.nummer) {
            break;
        }

        pos++;
    }

    anzahl = anzahl_datensaetze(bin);

    
    for (long i = anzahl - 1; i >= pos; i--) {
        fseek(bin, i * sizeof(Messwert), SEEK_SET);
        fread(&temp, sizeof(Messwert), 1, bin);

        fseek(bin, (i + 1) * sizeof(Messwert), SEEK_SET);
        fwrite(&temp, sizeof(Messwert), 1, bin);
    }

    fseek(bin, pos * sizeof(Messwert), SEEK_SET);
    fwrite(&neu, sizeof(Messwert), 1, bin);

    fflush(bin);
}

int main(void) {
    FILE *txt;
    FILE *bin;
    Messwert neu;

    txt = fopen("prak6_messwerte.txt", "r");
    if (txt == NULL) {
        printf("Fehler: Textdatei konnte nicht geoeffnet werden.\n");
        return 1;
    }


    bin = fopen("prak6_messwerte.bin", "w+b");
    if (bin == NULL) {
        printf("Fehler: Binaerdatei konnte nicht geoeffnet werden.\n");
        fclose(txt);
        return 1;
    }

    while (fscanf(txt, "%d %f", &neu.nummer, &neu.wert) == 2) {
        sortiert_einfuegen(bin, neu);
    }

    fclose(txt);
    fclose(bin);

    printf("Datei wurde erfolgreich sortiert in prak6_messwerte.bin geschrieben.\n");

    return 0;
}