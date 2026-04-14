//6.1 
// i) Die funktionsdeklaration bestimmt die werte, rückgabewert und parameter für eine funktion, damit der compiler weiß, was dass es eine funktion ist 
// zb. int sum(int a, int b); 
// die definition implementiert nun die funktion und macht daraus eine funktion mit anweisungen zb. int sum(int a, int b){ return a + b }
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool isDecimal(char ch); 

bool isDecimal(char ch){
    if (ch >= 48 && ch <=57){
        printf("Ist eine dezimalzahl\n");
        return true;
    } 
    
}

bool isCapitalLetter(char ch);

bool isCapitalLetter(char ch){
    if (ch >= 65 && ch <= 90){
        printf("Ist ein Großbuchstabe\n");
        return true;
    } 
}

bool isSmallLetter(char ch);

bool isSmallLetter(char ch){
    if (ch >= 92 && ch <= 122){
        printf("Ist ein Kleinbuchstabe\n");
        return true;
    } 
}

bool isPrintable(char ch);

bool isPrintable(char ch){
    if (ch >= 33 && ch <= 126){
        printf("Ist ausgebbar!\n");
        return true;
    } 
}

void printAsciiTable(){
    int n = 0;
    char cha = 0; 
    while (n < 128){
        if (n < 33 || n > 126)
        printf("|%d\t", cha);
        else 
        printf("|%c\t", cha);
        cha++;
        n++;
        if (n % 16 == 0){
            printf("|\n");
        }
    }
}

int main(){
    int zif;
    int n = 0;
    char ch;
    char cha;
    //Ascii Tabelle
    do {
        printf("-1- Alles Ausgeben\n");
        printf("-2- Alle Dezimalziffern\n");
        printf("-3- Alle Großbuchstaben\n");
        printf("-4- Alle Kleinbuchstaben\n");
        printf("-5- Alle Sonderzeichen\n");
        printf("-6- Ascii Tablle ausgeben\n");
        printf("-7- Beenden\n");
        scanf("%d", &zif);
        switch (zif) {
            case 1: 
                n = 0;
                cha = 33;
                while (n < 94){
                printf("Dezimal: %d, Hexadezimal: %x, Oktal: %o, Zeichen: %c\n", cha, cha, cha, cha);
                cha++;
                n++;
                }
                break;
            case 2:
                n = 0;
                cha = 48;
                while (n < 10){
                printf("Dezimal: %d, Hexadezimal: %x, Oktal: %o, Zeichen: %c\n", cha, cha, cha, cha);
                cha++;
                n++;
                }
                break;
            case 3: 
                n = 0;
                cha = 65;
                while (n < 26){
                printf("Dezimal: %d, Hexadezimal: %x, Oktal: %o, Zeichen: %c\n", cha, cha, cha, cha);
                cha++;
                n++;
                }
                break;
            case 4: 
                n = 0;
                cha = 97;
                while (n < 26){
                printf("Dezimal: %d, Hexadezimal: %x, Oktal: %o, Zeichen: %c\n", cha, cha, cha, cha);
                cha++;
                n++;
                }
                break;
            case 5: 
                n = 0;
                cha = 33;
                while (n < 32){
                printf("Dezimal: %d, Hexadezimal: %x, Oktal: %o, Zeichen: %c\n", cha, cha, cha, cha);
                cha++;
                n++;
                if (cha == 48)
                    cha = 58;
                if (cha == 65)
                    cha = 91;
                if (cha == 97)
                    cha = 123;
                }
                break;
            case 6:
            printAsciiTable();
            printf("\n\n");
            break;
            case 7:
            printf("Beende Programm...\n"); // Schleifenbedingung beendet die Schleife
            break;
            default: 
                printf("Falcher Wert\n");
                return 0;
                break;
            }
        }
    while (zif != 7);
    printf("Programm beendet.\n");
    



    
    printf("Geben sie ein zeichen ein:\n");
    scanf(" %c", &ch);
    printf("Zeichen ist %c\n", ch);
    isDecimal(ch);
    isCapitalLetter(ch);
    isSmallLetter(ch);
    isPrintable(ch);
    return 0;    
}
