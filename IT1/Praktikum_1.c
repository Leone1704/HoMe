#include <stdio.h>
#include <math.h>

int ANzahlBrüche;
int count = 0;
int i = 0;
int groeßte;
int kleinste;
int groeßteZ = 0;
int kleinsteZ = 100;
int pruefGrößer = 1;
int pruefKleiner = 1;
int x1 = -1;
int sum = 0;

double leibnizPi(int ANzahlBrüche)
{ // leon 2.30, ich will nicht mehr :(
    double pi = 0.0;

    for (int n = 0; n < ANzahlBrüche; n++)
    {
        int vorzeichen;

        // Bestimme das Vorzeichen: gerade = +1, ungerade = -1
        if (n % 2 == 0)
        {
            vorzeichen = 1;
        }
        else
        {
            vorzeichen = -1;
        }

        pi += vorzeichen / (double)(2 * n + 1);
    }

    return pi * 4;
}

/*unsigned long long fakultaet(int a) {
    unsigned long long fak = 1ULL;
    for (int i = 1; i <= a; i++) {
        fak *= i;
    }
    return fak;
}   */

#define wei "\x1b[0m"
#define bla "\x1b[34m"

int spiel()
{
    // magische Zahl 37
    char b = 201;  // ╔
    char b1 = 187; // ╗
    char b2 = 200; // ╚
    char b3 = 188; // ╝
    char b4 = 205; // ═
    char b5 = 186; // ║

    printf(bla "%c%c%c%c%c%c%c ASCII-Zeichensatz, Hexadezimalcodes %c%c%c%c%c%c%c\n", b, b4, b4, b4, b4, b4, b4, b4, b4, b4, b4, b4, b4, b1);
    printf(bla "%c                                                 %c", b5, b5);
    printf("");
}
void addSumme(int x1)
{
    sum += x1;
}

void CompareSmall(int x1,int kleinsteZ){
    if (x1 < kleinsteZ)
    {
        kleinsteZ = x1;
        kleinste = i;
    }
}

void CompareBig(int x1,int groeßteZ)
{
    if (x1 > groeßteZ)
    {
        groeßteZ= x1;
        groeßte= i;
    }
}

int main()
{

    printf("Wieviele Zahlen möchten sie eingeben?");
    scanf(" %d", &count);

    while (count < 3 || count > 10)
    {
        while (getchar() != '\n');
        printf("Ungültige Anzahl: Bitte eine Zahl zwischen 3 und 10 eingeben.\n");
    }

    for (i = 0; i < count; i++)
    {
        int x1 = -1;
        int res;
        if (i < count)
        {
            printf("%d. Zahl: ", i + 1);
            res = scanf(" %d", &x1);
            if (res != 1 || x1 < 0)
            {
                while (getchar() != '\n')
                    ;
                printf("Ungültige Eingabe, bitte eine Zahl eingeben.\n");
                i--;
                continue;
            }
            addSumme(x1);
        CompareSmall(x1, kleinsteZ);
        CompareBig(x1, groeßteZ);
            
            
            
        }
        
        
    }
    printf("Summe: %d", sum);
    printf("Die kleinste Zahl ist %d\n", kleinsteZ);

    scanf(" %d", &ANzahlBrüche);
    double ergebnis = leibnizPi(ANzahlBrüche);
    printf("Das ergebnis ist: %.6f\n", ergebnis);

    printf("\n\n\n");
    spiel();
    return 0;
}
