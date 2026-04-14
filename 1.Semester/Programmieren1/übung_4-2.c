#include <stdio.h>
#include <math.h>

int main(void) {
    /* a, b, c: Koeffizienten der quadratischen Gleichung */
    double a, b, c;

    printf("Quadratische Gleichung: a*x^2 + b*x + c = 0\n");
    printf("Geben Sie die Koeffizienten a, b und c ein (z. B. '1, 0, -4'):\n");

    /* scanf liest drei double-Werte; Rückgabewert prüfen */
    if (scanf("%lf, %lf, %lf", &a, &b, &c) != 3) {
        printf("Fehlerhafte Eingabe. Bitte drei Zahlen eingeben.\n");
        return 1; /* Fehlercode */
    }



    /* Fall: a == 0 -> die Gleichung ist nicht quadratisch */
    if (a == 0) {
        /* Dann ist die Gleichung linear oder konstant */
        if (b == 0) {
            if (c == 0) {
                /* 0 = 0 */
                printf("Ergebnis: Unendlich viele Lösungen.\n");
            } else {
                /* c != 0 -> keine Lösung */
                printf("Ergebnis: Keine Lösung (konstante falsche Gleichung).\n");
            }
        } else {
            /* Lineare Gleichung: b*x + c = 0  -> x = -c/b */
            double x = -c / b;
            printf("Ergebnis (linear): eine Lösung: x = %.2f\n", x);
        }
        return 0; /* Programm beendet nach Behandlung des linearen Falls */
    }

    /* a != 0 -> Quadratische Gleichung */
    double D = b * b - 4.0 * a
     * c; /* Diskriminante */

    if (D > 0) {
        /* Zwei verschiedene reelle Lösungen */
        double s = sqrt(D);                 /* positive Quadratwurzel von D */
        double x1 = (-b + s) / (2.0 * a);   /* Formel 1 */
        double x2 = (-b - s) / (2.0 * a);   /* Formel 2 */
        printf("Ergebnis: Zwei verschiedene reelle Lösungen:\n");
        printf("  x1 = %.4g\n", x1);
        printf("  x2 = %.4g\n", x2);
    } else if (D == 0) {
        double x = -b / (2.0 * a);
        printf("x = %.2f\n", x);
    } else if (D < 0){
        printf("Ergebnis: Keine reellen Lösungen.\n");
    } 

    return 0;
}