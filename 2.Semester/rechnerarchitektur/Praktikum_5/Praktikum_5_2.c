#include <stdio.h>

extern int quadrat(int n);

int main(void)
{
    int zahl;
    int ergebnis;

    printf("Geben Sie eine natuerliche Zahl ein: ");
    scanf("%d", &zahl);

    ergebnis = quadrat(zahl);

    printf("Das Quadrat von %d ist: %d\n", zahl, ergebnis);

    return 0;
}