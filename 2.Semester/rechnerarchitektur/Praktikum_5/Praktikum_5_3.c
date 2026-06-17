#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef unsigned int uint32_t;

uint32_t func(uint32_t x) {
    uint32_t r = 0;

    while (x) {
        r += x & 1;
        x >>= 1;
    }

    return r;
}


int main(void){

    clock_t start = clock();
    const int N = 10000000;

    uint32_t summe_für_test = 0;
    srand(time(NULL));
    for (int i = 0; i < N; i++){
        int randomZahl = rand();
        int binaerZahl = func(randomZahl);
        summe_für_test += binaerZahl;
        //printf("%d wird zu %d\n", randomZahl, binaerZahl);

    }
    printf("summe : %d\n", summe_für_test);
    clock_t end = clock();

    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Zeit: %.3f Sekunden\n", seconds);
    return 0;



}