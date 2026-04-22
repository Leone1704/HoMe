#include <stdio.h>
 
/* ------------------------------------------------------------------ */
/*  Bitmaskendefinitionen                                               */
/* ------------------------------------------------------------------ */
#define MASK_M1  (1 << 0)   /* 0b00000001 */
#define MASK_M2  (1 << 1)   /* 0b00000010 */
#define MASK_V1  (1 << 3)   /* 0b00001000 */
#define MASK_V2  (1 << 5)   /* 0b00100000 */
#define MASK_V3  (1 << 7)   /* 0b10000000 */
 
/* ------------------------------------------------------------------ */
/*  a) Binärdarstellung ausgeben (Big-Endian, MSB zuerst)              */
/* ------------------------------------------------------------------ */
void printBin(char word)
{
    /*
     * printf gibt char als vorzeichenbehafteten int aus – deshalb casten
     * wir explizit auf unsigned char, um korrekte Bitmuster zu erhalten
     * (kein 2er-Komplement-Problem bei negativen Werten wie 0xFF).
     */
    unsigned char val = (unsigned char)word;
    printf("0b");
    for (int i = 7; i >= 0; i--) {
        printf("%d", (val >> i) & 1);
        if (i == 4) printf(" "); /* optionale Leerstelle zur Lesbarkeit */
    }
    printf("\n");
}
 
/* ------------------------------------------------------------------ */
/*  b) Einzelne Bits setzen und löschen                                */
/*                                                                      */
/*  Setzen:  OR  mit Maske  (1 << index)   => Bit auf 1 bringen        */
/*  Löschen: AND mit ~Maske (~(1 << index)) => Bit auf 0 bringen       */
/* ------------------------------------------------------------------ */
void setBitValue(unsigned char *word, char index)
{
    *word |= (1 << index);
}
 
void clearBitValue(unsigned char *word, char index)
{
    *word &= ~(1 << index);
}
 
/* Optionale Makro-Variante: */
#define SET_BIT(word, idx)   ((word) |=  (1 << (idx)))
#define CLEAR_BIT(word, idx) ((word) &= ~(1 << (idx)))
 
/* ------------------------------------------------------------------ */
/*  c) Zustand des Datenwortes lesbar ausgeben                         */
/* ------------------------------------------------------------------ */
void printStatus(unsigned char word)
{
    printf("--- Systemzustand ---\n");
    printf("Motor  M1: %s\n", (word & MASK_M1) ? "AN"        : "AUS");
    printf("Motor  M2: %s\n", (word & MASK_M2) ? "AN"        : "AUS");
    printf("Ventil V1: %s\n", (word & MASK_V1) ? "OFFEN"     : "GESCHLOSSEN");
    printf("Ventil V2: %s\n", (word & MASK_V2) ? "OFFEN"     : "GESCHLOSSEN");
    printf("Ventil V3: %s\n", (word & MASK_V3) ? "OFFEN"     : "GESCHLOSSEN");
    printf("Datenwort: ");
    printBin((char)word);
    printf("---------------------\n");
}
 
/* ------------------------------------------------------------------ */
/*  d) Prüffunktion für Sicherheitsbedingungen                         */
/*                                                                      */
/*  Regel 1: Alle Ventile aktiv => alle Motoren müssen aktiv sein.      */
/*  Regel 2: Alle Motoren aktiv => mind. 2 Ventile müssen offen sein.  */
/*  Regel 3: Mind. ein Ventil offen => mind. ein Motor muss laufen.    */
/* ------------------------------------------------------------------ */
int checkConditions(unsigned char word)
{
    int ok = 1;
 
    /* Hilfsvariablen */
    int m1 = (word & MASK_M1) ? 1 : 0;
    int m2 = (word & MASK_M2) ? 1 : 0;
    int v1 = (word & MASK_V1) ? 1 : 0;
    int v2 = (word & MASK_V2) ? 1 : 0;
    int v3 = (word & MASK_V3) ? 1 : 0;
 
    int alleMotoren  = m1 && m2;
    int alleVentile  = v1 && v2 && v3;
    int anzVentile   = v1 + v2 + v3;
    int einVentil    = (anzVentile >= 1);
    int einMotor     = m1 || m2;
 
    /* Regel 1 */
    if (alleVentile && !alleMotoren) {
        printf("[FEHLER] Alle Ventile offen, aber nicht alle Motoren aktiv!\n");
        ok = 0;
    }
 
    /* Regel 2 */
    if (alleMotoren && anzVentile < 2) {
        printf("[FEHLER] Alle Motoren aktiv, aber weniger als 2 Ventile offen!\n");
        ok = 0;
    }
 
    /* Regel 3 */
    if (einVentil && !einMotor) {
        printf("[FEHLER] Mindestens ein Ventil offen, aber kein Motor laeuft!\n");
        ok = 0;
    }
 
    if (ok) {
        printf("[OK] Alle Sicherheitsbedingungen erfuellt.\n");
    }
 
    return ok;
}
 
/* ------------------------------------------------------------------ */
/*  main – Demonstration aller Teilaufgaben                            */
/* ------------------------------------------------------------------ */
int main(void)
{
    printf("========================================\n");
    printf("  Aufgabe P-1.3 Musterloesung\n");
    printf("========================================\n\n");
 
    /* --- a) printBin testen --- */
    printf("--- a) printBin Tests ---\n");
    printf("  0   -> "); printBin(0);
    printf("  255 -> "); printBin((char)255);   /* 0xFF -> alle Bits 1 */
    printf("  127 -> "); printBin(127);          /* 0x7F */
    printf(" -128 -> "); printBin((char)-128);   /* 2er-Komplement: 0x80 */
    printf("\n");
 
    /* --- b) set/clearBitValue testen --- */
    printf("--- b) setBitValue / clearBitValue ---\n");
    unsigned char reg = 0x00;
    printf("Startwert:   "); printBin((char)reg);
    setBitValue(&reg, 0);   /* M1 an */
    printf("M1 gesetzt:  "); printBin((char)reg);
    setBitValue(&reg, 3);   /* V1 an */
    printf("V1 gesetzt:  "); printBin((char)reg);
    clearBitValue(&reg, 0); /* M1 aus */
    printf("M1 geloescht:"); printBin((char)reg);
    printf("\n");
 
    /* --- c) Aufgabenwerte setzen: M1=1, M2=0, V1=1, V2=0, V3=1 --- */
    printf("--- c) Aufgabenwerte: M1=1, M2=0, V1=1, V2=0, V3=1 ---\n");
    unsigned char datenwort = 0x00;
    setBitValue(&datenwort, 0);  /* M1 = 1 -> Bit 0 */
    /* M2 bleibt 0 */
    setBitValue(&datenwort, 3);  /* V1 = 1 -> Bit 3 */
    /* V2 bleibt 0 */
    setBitValue(&datenwort, 7);  /* V3 = 1 -> Bit 7 */
    printStatus(datenwort);
    printf("\n");
 
    /* --- d) Prüffunktion demonstrieren --- */
    printf("--- d) Sicherheitspruefung ---\n");
 
    printf("\nTest 1 – gueltiger Zustand (M1=1,M2=0,V1=1,V2=0,V3=1):\n");
    checkConditions(datenwort);
 
    printf("\nTest 2 – alle Ventile offen, kein Motor (sollte Fehler):\n");
    unsigned char test2 = MASK_V1 | MASK_V2 | MASK_V3;
    checkConditions(test2);
 
    printf("\nTest 3 – alle Motoren, nur 1 Ventil (sollte Fehler):\n");
    unsigned char test3 = MASK_M1 | MASK_M2 | MASK_V1;
    checkConditions(test3);
 
    printf("\nTest 4 – Ventil offen, kein Motor (sollte Fehler):\n");
    unsigned char test4 = MASK_V2;
    checkConditions(test4);
 
    printf("\nTest 5 – alles aus (kein Fehler):\n");
    checkConditions(0x00);
 
    return 0;
}