#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int nummer;
    float wert;
} Messwert;

int main(void) {
    FILE *bin;
    Messwert mw;

    bin = fopen("prak6_messwerte.bin", "rb");
    if (bin == NULL) {
        printf("Fehler: Binaerdatei konnte nicht geoeffnet werden.\n");
        return 1;
    }

    while (fread(&mw, sizeof(Messwert), 1, bin) == 1) {
        printf("%d %.2f\n", mw.nummer, mw.wert);
    }

    fclose(bin);

    return 0;
}