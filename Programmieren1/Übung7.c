# include <stdio.h>
<<<<<<< HEAD
=======
int invert(int zahl);


int zahl, rest, inv = 0;
//int scanf(string prozU, int &input)
>>>>>>> origin/main
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
        return fib(a-1) + fib(a-2);
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

unsigned int func(unsigned int b){
if (b >= 1) return func(b - 1) +3 * b * (b - 1) +1; 
else return 1;
}

char ubu(int c){
    if (c != 0 || c > 0) {
        return ("%c %c" , ubu(c - 1));
    }
}

int main(void) {

unsigned int n = 0;
unsigned int a = 0;
unsigned int b = 0;
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

printf("Wert für func(): ");
int checkFunc = scanf(" %u", &b);
if(checkFunc != 1) {
    printf("Fehler!");
    return 1;
}
printf("Der Wert für Func ist %u.", func(b));
return 0;
}