#include <stdio.h>
#include <math.h>

int ANzahlBrüche;
int i = 0;
int groeßte;
int kleinste;
int groeßteZ = 0;
int kleinsteZ = 100;
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

int main()
{
    int x1 = -1;
    int res;
    int check;
    int count;
    int fehler = 0;
    printf("Wieviele Zahlen möchten sie eingeben?\n");
    check = scanf("Weiviele Zahlen moechten sie eingeben?", &count);
    while(!(scanf("%d", &count) == 1 && count >= 3 && count <= 10))
    {
        while (getchar() != '\n');
        printf("Ungültige Anzahl: Bitte eine Zahl zwischen 3 und 10 eingeben.\n");
    }

    for (i = 0; i < count; i++ || check != 1)
    {
        
        if (i < count)
        {
            printf("%d. Zahl: ", i + 1);
            res = scanf(" %d", &x1);
            if (res != 1 || x1 < 0)
            {
                while (getchar() != '\n');
                printf("Ungültige Eingabe, bitte eine Zahl eingeben.\n");
                i--;
                fehler++;
                if (fehler == 3) return 1;
                continue;
            }
            fehler = 0;
            addSumme(x1);
            if (x1 < kleinsteZ)
            {
                kleinsteZ = x1;
                kleinste = i + 1;
            }
            if (x1 > groeßteZ)
            {
                groeßteZ= x1;
                groeßte= i + 1;
            }
        }
        
        
    }
    printf("Summe: %d\n", sum);
    printf("Die %d. Zahl ist die kleinste Zahl mit dem Wert: %d\n",kleinste,  kleinsteZ);
    printf("Die größte Zahl ist die %d. Zahl mit dem Wert: %d", groeßte, groeßteZ);


    //scanf(" %d", &ANzahlBrüche);
    //double ergebnis = leibnizPi(ANzahlBrüche);
    //printf("Das ergebnis ist: %.6f\n", ergebnis);

    //printf("\n\n\n");
    //spiel();
    return 0;
}
