#include <stdio.h>
#include <math.h>

int main(void) {
    //Fakultätsberechnung
    int n;
    printf("Geben Sie eine nicht-negative ganze Zahl ein, um die Fakultät zu berechnen: ");
    scanf("%d", &n);
    do {
        unsigned long long fakultaet = 1;
        for (int i = 1; i <= n; ++i) {
            fakultaet *= i;
            printf("Die Fakultät von %d ist %llu\n", n, fakultaet);
    } while (n < 0);
    
    return 0;
}
}
