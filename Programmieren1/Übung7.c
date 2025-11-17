# include <stdio.h>
//int scanf(string prozU, int &input)
unsigned int sum(unsigned int n) {
    if (n > 0){
        return n + sum(n - 1);
    } 
}

unsigned int fib(unsigned int a){
    if (a = 1){
        return 1;
    } else if (a = 0){
        return 0;
    } else if(a > 1){
        unsigned int ab = fib(a - 1) + fib(a - 2);
        return ab;
    }

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
printf("Der FibCode ist %u.", fib(a));
return 0;
}