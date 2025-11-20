# include <stdio.h>
int invert(int zahl);


int zahl, rest, inv = 0;
//int scanf(string prozU, int &input)
unsigned int sum(unsigned int n) {
    if (n > 0){
        return n + sum(n - 1);
    } 
}


unsigned int fib(unsigned int a){
    if (a == 1){
        return 1;
    } else if (a == 0){
        return 0;
    } else if(a > 1){
        unsigned int ab = fib(a - 1) + fib(a - 2);
        return ab;
    }

}
    int invCounter = 0;


int invert(int zahl){
    if (zahl > 0) {
        rest = zahl % 10;
        inv = inv * 10 + rest;
        zahl = zahl / 10; 
        invCounter++;
        return invert(zahl);
    }
    return inv;
}

int main(void) {

unsigned int n = 0;
unsigned int a = 0;
printf("Aufsummieren von 1 bis n mit n = ");
int check = scanf(" %u", &n);
if(check != 1) {
    printf("Fehler!");
    return 1;
}

printf("Die Summe ist: %u.\n", sum(n));
printf("Welchen Fibunaci Code wollen sie loesen? ");
int checkFib = scanf(" %u", &a);
if(checkFib != 1) {
    printf("Fehler!");
    return 1;
}
printf("Der FibCode ist %u.\n", fib(a));

printf("Zahl für invert\n");
scanf(" %d", &zahl);
printf("Die invert ist %d\n", invert(zahl));
printf("%d", invCounter);
return 0;
}