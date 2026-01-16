#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


typedef enum {
    FORWARD,
    BACKWARD
} Ausgabereihenfolge;

void sum() {
    int a, b;
    printf("Geben Sie zwei ganze Zahlen ein: ");
    if (scanf("%d %d", &a, &b) == 2) {
        printf("Summe: %d\n", a + b);
    } else {
        printf("Ungültige Eingabe. Bitte geben Sie zwei ganze Zahlen ein.\n");
    }
}


void variadicFunction() {
    int anzahl;
    printf("Wie viele Zahlen möchten Sie addieren? ");
    scanf("%d", &anzahl);
    
    printf("Geben Sie die Zahlen ein: ");
    int zahlen[anzahl];
    for (int i = 0; i < anzahl; i++) {
        scanf("%d", &zahlen[i]);
    }
    int ergebnis =  0;
    for (int i = 0; i < anzahl; i++) {
        ergebnis += zahlen[i];
    }
    printf("Summe: %d\n", ergebnis);
}

void variadicFunction_Args(int anzahl, ...) {
    va_list args;
    va_start(args, anzahl);

    int ergebnis = 0;

    for (int i = 0; i < anzahl; i++) {
        int zahl = va_arg(args, int);
        ergebnis += zahl;
    }

    va_end(args);

    printf("Summe: %d\n", ergebnis);
}

void AufzaehlungBisN(Ausgabereihenfolge richtung) {
    int n;
    printf("Geben Sie eine positive ganze Zahl ein: ");
    if (scanf("%d", &n) != 1) {
        printf("Ungültige Eingabe. Bitte geben Sie eine ganze Zahl ein.\n");
        return;
    }
    /*if (n <= 0) {
        printf("Parameter muss eine positive ganze Zahl sein.\n"); // Überprüfung auf positive Zahl falls nötig
        return;
    }*/
    
    if (richtung == FORWARD && n > 0) {
        for (int i = 1; i <= n; i++) {
            printf("%d ", i);
        }
    } else if (richtung == BACKWARD && n > 0) {
        for (int i = n; i >= 1; i--) {
            printf("%d ", i);
        }
    } else if (richtung == FORWARD && n < 0) {
        for (int i = 1; i >= n; i--) {
            printf("%d ", i);
        }
    } else if (richtung == BACKWARD && n < 0) {
        for (int i = n; i <= 1; i++) {
            printf("%d ", i);
        }
    } else {
        printf("Die Zahl ist null, keine Ausgabe.\n");
        return;
    }
    printf("\n");
}

void Aufsummieren() {
    int n;
    printf("Geben Sie eine positive ganze Zahl ein: ");
    if (scanf("%d", &n) != 1) {
        printf("Ungültige Eingabe. Bitte geben Sie eine positive ganze Zahl ein.\n");
        return;
    }
    if (n <= 0) {
        printf("Aufgrund der Aufgabenstellung ist die Summe 0.\n");
        return;
    }
    
    int summe = 0;
    for (int i = 1; i <= n; i++) {
        summe += i;
    }
    printf("Die Summe der Zahlen von 1 bis %d ist: %d\n", n, summe);
}

void CharErkenner() {
    char eingabe;
    printf("Geben Sie ein einzelnes Zeichen ein: ");
    scanf(" %c", &eingabe);
    
    if (eingabe >= 'A' && eingabe <= 'Z') {
        for (char c = 'A'; c <= eingabe; c++) {
            printf("%c ", c);
        }
    } else if (eingabe >= 'a' && eingabe <= 'z') {
        for (char c = 'a'; c <= eingabe; c++) {
            printf("%c ", c);
        }
    }
    else {
        printf("Das eingegebene Zeichen ist kein Buchstabe\n");
    }
}

void readString() {
    static int Count = 0;
    char character; 
    char String[200];
    printf("Geben Sie einen String ein (max. 199 Zeichen): ");
    scanf(" %199s", String);
    if (String[0] == '\0' || String[0] >= 200) {
        printf("Fehler: Ungültige Eingabe.\n");
        return;
    }
    printf("Der eingegebene String ist: %s\n", String);
    printf("Welches Zeichen soll gezählt werden? \n");
    scanf(" %c", &character);
    for (int i = 0; i < strlen(String); i++) {
        if (String[i] == character){ 
            Count++;
        }
    }
    printf("Der String hat %d-mal das Zeichen %c.\n", Count, character);
    return;
}

bool istPrimzahl(int zahl) {
    if (zahl < 2) {
        return false;
    }
    if (zahl == 2) {
        return true;
    }
    if (zahl % 2 == 0) {
        return false;
    }
    for (int i = 3; i * i <= zahl; i += 2) {
        if (zahl % i == 0) {
            return false;
        }
    }
    return true;
}

void PrimzahlErkenner(int grenzwert) {

    
    
    printf("Geben Sie den Grenzwert ein: ");
    if (scanf("%d", &grenzwert) != 1 || grenzwert < 2) {
        printf("Ungültige Eingabe. Bitte geben Sie eine Zahl größer oder gleich 2 ein.\n");
        return;
    }
    
    printf("Primzahlen zwischen 2 und %d:\n", grenzwert);
    
    int count = 0;
    for (int i = 2; i <= grenzwert; i++) {
        if (istPrimzahl(i)) {
            printf("%d ", i);
            count++;
        }
    }
    printf("\nAnzahl der gefundenen Primzahlen: %d\n", count);
}


void SiebDesEratosthenes(int grenzwert) {
    bool *istPrim = malloc((grenzwert + 1) * sizeof(bool));

    if (istPrim == NULL) {
        printf("Speicher konnte nicht reserviert werden.\n");
        return;
    }

    // Initialisierung
    for (int i = 0; i <= grenzwert; i++) {
        istPrim[i] = true;
    }

    istPrim[0] = istPrim[1] = false;

    // Sieb
    for (int i = 2; i * i <= grenzwert; i++) {
        if (istPrim[i]) {
            for (int j = i * i; j <= grenzwert; j += i) {
                istPrim[j] = false;
            }
        }
    }

    // Ausgabe
    int count = 0;
    printf("Primzahlen zwischen 1 und %d:\n", grenzwert);
    for (int i = 2; i <= grenzwert; i++) {
        if (istPrim[i]) {
            printf("%d ", i);
            count++;
        }
    }
    printf("\nAnzahl der Primzahlen: %d\n", count);

    free(istPrim);
}

int main() {
    return 0;
}


