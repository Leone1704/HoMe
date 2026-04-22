#include <stdio.h>
#include <stdint.h>
#include <stddef.h>

#define BIT_M1 0
#define BIT_M2 2
#define BIT_V1 3
#define BIT_V2 5
#define BIT_V3 7

static unsigned char to_uchar(char word)
{
    return (unsigned char)word;
}

void printBin(char word)
{
    unsigned char uword = to_uchar(word);

    /* Big-Endian-Ausgabe: höchstwertiges Bit zuerst, niedrigstes Bit zuletzt. */
    for (int i = 7; i >= 0; --i) {
        putchar(((uword >> i) & 1U) ? '1' : '0');
    }
    putchar('\n');
}

int main(void)
{
    signed char tests[] = {0, 1, 5, 42, -1, -42, (signed char)0x80, (signed char)0xB5};
    size_t count = sizeof(tests) / sizeof(tests[0]);

    for (size_t i = 0; i < count; ++i) {
        printf("Wert als signed char = %4d -> Binär = ", tests[i]);
        printBin((char)tests[i]);
    }

    return 0;
}