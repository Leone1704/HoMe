#include <stdio.h>

extern int quadrat_test(int n);

int main(void)
{
    int zahl;
    int ergebnis;

    printf("Geben Sie eine natuerliche Zahl ein: ");
    scanf("%d", &zahl);

    ergebnis = quadrat_test(zahl);

    printf("Das Quadrat von %d ist: %d\n", zahl, ergebnis);

    return 0;
}

//nasm -f bin  .\Praktikum_6.asm -o .\Praktikum_6.bin 
//nasm -fwin32 quadrat_test.s -o quadrat_test.o 
//gcc .\Praktikum_5_2.o .\quadrat_test.o -o .\Praktikum_5_2.exe
