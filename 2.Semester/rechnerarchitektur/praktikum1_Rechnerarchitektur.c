#include <stdint.h>
#include <stdio.h>
#include <string.h>

static void print_binary_float(float value) {
    uint32_t bits = 0;
    memcpy(&bits, &value, sizeof(bits));
    uint32_t vorzeichen = (bits >> 31) & 1U;
    uint32_t exponent = (bits >> 23) & 0xFFU; // 
    uint32_t mantisse = bits & 0x7FFFFFU; // 23 Bits für die Mantisse
    int exponent_unbiased = 0;
    double mantisse_anteil = 0.0;
    double signifikand = 0.0;


    printf("IEEE-754 (32-bit):\n");
    printf("S EEEEEEEE MMMMMMMMMMMMMMMMMMMMMMM\n");

    for (int i = 31; i >= 0; --i) {
        printf("%u", (bits >> i) & 1U);

        if (i == 31 || i == 23) {
            printf(" ");
        }
    }

    if (exponent > 0U && exponent < 255U) {
        exponent_unbiased = (int)exponent - 127;
        mantisse_anteil = (double)mantisse / (double)(1U << 23);
        signifikand = 1.0 + mantisse_anteil;
    } else {
        printf("Fehler: Ungültiger Exponent (Sonderfälle wie NaN oder Unendlich werden nicht unterstützt).\n");
        return;
    }

    printf("\n");
    printf("Vorzeichen = %s\n", (vorzeichen == 1) ? "-" : "+");
    printf("Exponent = %d\n", exponent_unbiased);
    printf("Mantisse = %.10f\n", signifikand);
}


float read_float_from_user() {
    float number = 0.0f;
    printf("Gib eine Gleitkommazahl ein: ");
    if (scanf("%f", &number) != 1) {
        fprintf(stderr, "Ungueltige Eingabe.\n");
        return 0.0f; // Rückgabewert bei ungültiger Eingabe
    }
    return number;
}



int main(void) {
    float number = read_float_from_user();
    print_binary_float(number);
    return 0;
}