#include <stdio.h>
#include <math.h>

int ANzahlBrüche;

double leibnizPi(int ANzahlBrüche) { // leon 2.30, ich will nicht mehr :(
    double pi = 0.0;
    
    for (int n = 0; n < ANzahlBrüche; n++) {
        int vorzeichen;
        
        // Bestimme das Vorzeichen: gerade = +1, ungerade = -1
        if (n % 2 == 0) {
            vorzeichen = 1;
        } else {
            vorzeichen = -1;
        }
        
        pi += vorzeichen / (double)(2 * n + 1);
    }
    
    return pi * 4;
}

int fakultaet(int a) {
    int fak = 1;
    for (int i = 1; i <= a; i++) {
        fak *= i;
    }
    return fak;
}   

int main(){
    int count = 0;
    int i = 0;
    int größte = -1;
    int kleinste =  10;
    int größteZ;
    int kleinsteZ;
    int prüfGrößer = 1;
    int prüfKleiner = 1;
    unsigned int a1, a2, a3, a4, a5 ,a6, a7, a8, a9, a10;
    int x1; 
    int x2; 
    int x3;
    int x4;
    int x5;
    int x6;
    int x7;
    int x8;
    int x9;
    int x10; //sollte eigentlich ein array sein und der code in einer schleife laufen; wollen sie aber nicht
    //mir fällt sonst keine elegante Lösung ein, das ganze in der Funktion zu erhöhen
    printf("Wieviele Zahlen möchten sie eingeben?");
    scanf(" %d", &count);
    
    if (count <= 0 || count > 10) {
        printf("Ungültige Anzahl: Bitte eine Zahl zwischen 1 und 10 eingeben.\n");
        return 1;
    }
    
    for (i = 0; i < count; ) {
        int res;
        if (i == 0 && i < count){
            do {
                printf("%d. Zahl: ", i + 1);
                res = scanf(" %d", &x1);
                int a1 = fakultaet(x1);
                printf("Fakultät: %u\n", a1);
                if (x1 > größte){
                    größte = 1; 
                    größteZ = x1;
                    //printf("kurzer test: %d",größte);
                }else if (x1 == größteZ){
                    prüfGrößer++;
                }
                if (x1 < kleinste){
                    kleinste = 1;
                    kleinsteZ = x1; 
                }else if (x1 == kleinsteZ){
                    prüfKleiner++;
                }
                if (res != 1) {
                    printf("Ungültige Eingabe, bitte eine Zahl eingeben.\n");
                    while (getchar() != '\n');
                    continue;
                }
                if (x1 < 0) {
                    printf("Ungültige Eingabe, bitte eine positive Zahl eingeben.\n");
                } else break;
            } while (1);
            i++;
        }
        if (i == 1 && i < count){
            do {
                printf("%d. Zahl: ", i + 1);
                res = scanf(" %d", &x2);
                int a2 = fakultaet(x2);
                printf("Fakultät: %u\n", a2);
                if (x2 > größteZ){
                    größte = 2;
                    größteZ = x2; 
                }else if (x2 == größteZ){
                    prüfGrößer++;
                }
                if (x2 < kleinsteZ){
                    kleinste = 2;
                    kleinsteZ = x2; 
                }else if (x2 == kleinsteZ){
                    prüfKleiner++;
                }
                if (res != 1) {
                    printf("Ungültige Eingabe, bitte eine Zahl eingeben.\n");
                    while (getchar() != '\n');
                    continue;
                }
                if (x2 < 0) {
                    printf("Ungültige Eingabe, bitte eine positive Zahl eingeben.\n");
                } else break;
            } while (1);
            i++;  
        }
        if (i == 2  && i < count){
            do {
                printf("%d. Zahl: ", i + 1);
                res = scanf(" %d", &x3);
                int a3 = fakultaet(x3);
                printf("Fakultät: %u\n", a3);
                if (x3 > größteZ){
                    größte = 3;
                    größteZ = x3; 
                }else if (x3 == größteZ){
                    prüfGrößer++;
                }
                if (x3 < kleinsteZ){
                    kleinste = 3;
                    kleinsteZ = x3; 
                }else if (x3 == kleinsteZ){
                    prüfKleiner++;
                }
                if (res != 1) {
                    printf("Ungültige Eingabe, bitte eine Zahl eingeben.\n");
                    while (getchar() != '\n');
                    continue;
                }
                if (x3 < 0) {
                    printf("Ungültige Eingabe, bitte eine positive Zahl eingeben.\n");
                } else break;
            } while (1);
            i++;
        }
        if (i == 3 && i < count){
            do {
                printf("%d. Zahl: ", i + 1);
                res = scanf(" %d", &x4);
                int a4 = fakultaet(x4);
                printf("Fakultät: %u\n", a4);
                if (x4 > größteZ){
                    größte = 4;
                    größteZ = x4; 
                }else if (x4 == größteZ){
                    prüfGrößer++;
                }
                if (x4 < kleinsteZ){
                    kleinste = 4; 
                    kleinsteZ = x4;
                }else if (x4 == kleinsteZ){
                    prüfKleiner++;
                }
                if (res != 1) {
                    printf("Ungültige Eingabe, bitte eine Zahl eingeben.\n");
                    while (getchar() != '\n');
                    continue;
                }
                if (x4 < 0) {
                    printf("Ungültige Eingabe, bitte eine positive Zahl eingeben.\n");
                } else break;
            } while (1);
            i++;
        }
        if (i == 4 && i < count){
            do {
                printf("%d. Zahl: ", i + 1);
                res = scanf(" %d", &x5);
                int a5 = fakultaet(x5);
                printf("Fakultät: %u\n", a5);
                if (x5 > größteZ){
                    größte = 5;
                    größteZ = x5;
                }else if (x5 == größteZ){
                    prüfGrößer++;
                }
                if (x5 < kleinsteZ){
                    kleinste = 5;
                    kleinsteZ = x5; 
                }else if (x5 == kleinsteZ){
                    prüfKleiner++;
                }
                if (res != 1) {
                    printf("Ungültige Eingabe, bitte eine Zahl eingeben.\n");
                    while (getchar() != '\n');
                    continue;
                }
                if (x5 < 0) {
                    printf("Ungültige Eingabe, bitte eine positive Zahl eingeben.\n");
                } else break;
            } while (1);
            i++;
        }
        if (i == 5 && i < count){
            do {
                printf("%d. Zahl: ", i + 1);
                res = scanf(" %d", &x6);
                int a6 = fakultaet(x6);
                printf("Fakultät: %u\n", a6);
                if (x6 > größteZ){
                    größte = 6; 
                    größteZ = x6;
                }else if (x6 == größteZ){
                    prüfGrößer++;
                }
                if (x6 < kleinsteZ){
                    kleinste = 6;
                    kleinsteZ = x6; 
                }else if (x6 == kleinsteZ){
                    prüfKleiner++;
                }
                if (res != 1) {
                    printf("Ungültige Eingabe, bitte eine Zahl eingeben.\n");
                    while (getchar() != '\n');
                    continue;
                }
                if (x6 < 0) {
                    printf("Ungültige Eingabe, bitte eine positive Zahl eingeben.\n");
                } else break;
            } while (1);
            i++;
        }
        if (i == 6 && i < count){
            do {
                printf("%d. Zahl: ", i + 1);
                res = scanf(" %d", &x7);
                int a7 = fakultaet(x7);
                printf("Fakultät: %u\n", a7);
                if (x7 > größteZ){
                    größte = 7;
                    größteZ = x7;
                }else if (x7 == größteZ){
                    prüfGrößer++;
                }
                if (x7 < kleinsteZ){
                    kleinste = 7; 
                    kleinsteZ = x7;
                }else if (x7 == kleinsteZ){
                    prüfKleiner++;
                }
                if (res != 1) {
                    printf("Ungültige Eingabe, bitte eine Zahl eingeben.\n");
                    while (getchar() != '\n');
                    continue;
                }
                if (x7 < 0) {
                    printf("Ungültige Eingabe, bitte eine positive Zahl eingeben.\n");
                } else break;
            } while (1);
            i++;
        }
        if (i == 7 && i < count){
            do {
                printf("%d. Zahl: ", i + 1);
                res = scanf(" %d", &x8);
                int a8 = fakultaet(x8);
                printf("Fakultät: %u\n", a8);
                if (x8 > größteZ){
                    größte = 8;
                    größteZ = x8; 
                }else if (x8 == größteZ){
                    prüfGrößer++;
                }
                if (x8 < kleinsteZ){
                    kleinste = 8;
                    kleinsteZ = x8; 
                }else if (x8 == kleinsteZ){
                    prüfKleiner++;
                }
                if (res != 1) {
                    printf("Ungültige Eingabe, bitte eine Zahl eingeben.\n");
                    while (getchar() != '\n');
                    continue;
                }
                if (x8 < 0) {
                    printf("Ungültige Eingabe, bitte eine positive Zahl eingeben.\n");
                } else break;
            } while (1);
            i++;
        } 
        if (i == 8 && i < count){
            do {
                printf("%d. Zahl: ", i + 1);
                res = scanf(" %d", &x9);
                int a9 = fakultaet(x9);
                printf("Fakultät: %u\n", a9);
                if (x9 > größteZ){
                    größte = 9; 
                    größteZ = x9;
                }else if (x9 == größteZ){
                    prüfGrößer++;
                }
                if (x9 < kleinsteZ){
                    kleinste = 9;
                    kleinsteZ = x9; 
                }else if (x9 == kleinsteZ){
                    prüfKleiner++;
                }
                if (res != 1) {
                    printf("Ungültige Eingabe, bitte eine Zahl eingeben.\n");
                    while (getchar() != '\n');
                    continue;
                }
                if (x9 < 0) {
                    printf("Ungültige Eingabe, bitte eine positive Zahl eingeben.\n");
                } else break;
            } while (1);
            i++;
        }
        if (i == 9 && i < count){
            do {
                printf("%d. Zahl: ", i + 1);
                res = scanf(" %d", &x10);
                int a10 = fakultaet(x10);
                printf("Fakultät: %u\n", a10);
                if (x10 > größteZ){
                    größte = 10;
                    größteZ = x10; 
                }else if (x10 == größteZ){
                    prüfGrößer++;
                }
                if (x10 < kleinsteZ){
                    kleinste = 10;
                    kleinsteZ = x10; 
                } else if (x10 == kleinsteZ){
                    prüfKleiner++;
                }
                if (res != 1) {
                    printf("Ungültige Eingabe, bitte eine Zahl eingeben.\n");
                    while (getchar() != '\n');
                    continue;
                }
                if (x10 < 0) {
                    printf("Ungültige Eingabe, bitte eine positive Zahl eingeben.\n");
                } else break;
            } while(1);
            i++;
        }
        
    } 
    
    if (count == 1) {
    printf("Die Summe Ihrer Eingaben beträgt: %d\n Und die der Fakultäten: %u\n\n",x1, a1);
    }
    if (count == 2) {
    printf("Die Summe Ihrer Eingaben beträgt: %d\n Und die der Fakultäten: %u\n\n",x1 + x2, a1 + a2);
    }
    if (count == 3) {
    printf("Die Summe Ihrer Eingaben beträgt: %d\n Und die der Fakultäten: %u\n\n",x1 + x2 + x3, a1 + a2 + a3);
    }
    if (count == 4) {
    printf("Die Summe Ihrer Eingaben beträgt: %d\n Und die der Fakultäten: %u\n\n",x1 + x2 + x3 + x4, a1 + a2 + a3 + a4 );
    }
    if (count == 5) {
    printf("Die Summe Ihrer Eingaben beträgt: %d\n Und die der Fakultäten: %u\n\n",x1 + x2 + x3 + x4 + x5, a1 + a2 + a3 + a4 + a5 );
    }
    if (count == 6) {
    printf("Die Summe Ihrer Eingaben beträgt: %d\n Und die der Fakultäten: %u\n\n",x1 + x2 + x3 + x4 + x5 + x6, a1 + a2 + a3 + a4 + a5 + a6 );
    }
    if (count == 7) {
    printf("Die Summe Ihrer Eingaben beträgt: %d\n Und die der Fakultäten: %u\n\n",x1 + x2 + x3 + x4 + x5 + x6 + x7 , a1 + a2 + a3 + a4 + a5 + a6 + a7 );
    }
    if (count == 8) {
    printf("Die Summe Ihrer Eingaben beträgt: %d\n Und die der Fakultäten: %u\n\n",x1 + x2 + x3 + x4 + x5 + x6 + x7 + x8, a1 + a2 + a3 + a4 + a5 + a6 + a7 + a8 );
    }
    if (count == 9) {
    printf("Die Summe Ihrer Eingaben beträgt: %d\n Und die der Fakultäten: %u\n\n",x1 + x2 + x3 + x4 + x5 + x6 + x7 + x8 + x9 , a1 + a2 + a3 + a4 + a5 + a6 + a7 + a8 + a9);
    }
    if (count == 10) {
    printf("Die Summe Ihrer Eingaben beträgt: %d\n Und die der Fakultäten: %u\n\n",x1 + x2 + x3 + x4 + x5 + x6 + x7 + x8 + x9 + x10, a1 + a2 + a3 + a4 + a5 + a6 + a7 + a8 + a9 + a10);
    }
    
    printf("Die größte Zahl, ist die %i. Zahl mit dem Wert: %i\n",größte, größteZ);
    if (prüfGrößer != 1) { printf("Bitte Zahlen überprüfen, da %d Werte den Titel der größten Zahl teilen\n", prüfGrößer);}
    printf("Die kleinste Zahl, ist die %i. Zahl mit dem Wert: %d\n", kleinste, kleinsteZ);
    if (prüfKleiner != 1) { printf("Bitte Zahlen überprüfen, da %d Werte den Titel der kleinsten Zahl teilen\n", prüfKleiner);}
    printf("\nich will nicht mehr\n\nWieviele Brüche für die Leibniz Reihe?\n");
    scanf(" %d", &ANzahlBrüche);
    double ergebnis = leibnizPi(ANzahlBrüche);
    printf("Das ergebnis ist: %.6f\n", ergebnis);


    return 0;
}