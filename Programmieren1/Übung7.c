# include <stdio.h>
#include <math.h>


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
int len = 0;
int lenghtZahl = 0;
int PalindromLaenge(int Palindrom){
    len = 0;
    while (Palindrom != 0){
        Palindrom = Palindrom / 10;
        len++;
    }
    lenghtZahl = len;
    return len;
}

signed int PalindromCheck(int Palindrom, int lenght){
    if (lenght <= 1) {
        printf("Gültige Zahl eingegeben.\n");
        return 1; // einstellige Zahlen sind Palindrome
    }

    int links = Palindrom;
    int rechts = Palindrom;

    // pow10 = 10^(lenght-1)
    int pow10 = 1;
    for (int k = 1; k < lenght; ++k) {
        pow10 *= 10;
    } //geht auch mit pow10 = pow(10, lenght -1);

    int paaren = lenght / 2;
    for (int i = 0; i < paaren; ++i) {
        int erste = rechts / pow10;   // MSB
        int letzte = links % 10;      // LSB

        if (erste != letzte) {
            printf("Kein Palindrom.\n");
            return 0; // kein Palindrom
        }

        // entferne erste und letzte Ziffer
        rechts = rechts % pow10; // entferne MSB
        //printf("rechts nach entfernen MSB: %d\n", rechts); //Check check für mich
        rechts = rechts / 10;    // verschiebe um eine Stelle
        //printf("rechts nach verschieben: %d\n", rechts);
        links = links / 10;      // entferne LSB

        // zwei Ziffern weniger => pow10 durch 100 teilen
        pow10 /= 100; 
    }

    printf("yesss\n");
    return 1; // ist Palindrom
}

unsigned int func(unsigned int  b){
if (b >= 1) return func(b - 1) +3 * b * (b - 1) +1; 
else return 1;
}

unsigned int func_it(unsigned int b){
    unsigned int result = 1;
    for (unsigned int i = 1; i <= b; i++){
        result = result + 3 * i * (i - 1) + 1;
    }
    return result;
}

unsigned int foo(unsigned int l, double k){
    if (l == 0) return k + 1;
    else if (k == 0){
        printf("l: %u\n", l);
        if (l == 10000){
            return l;
        }
        return foo(l +1,0);
        
    }
    else {
        printf("l: %u, k: %lf\n", l, k);
        return foo(l, foo(l + 1,k));
    }
}

int main(void) {
double k = 0.0;
unsigned int l = 0;
unsigned int n = 0;
unsigned int a = 0;
unsigned int b = 0;
unsigned int count = 0;
unsigned int current = 0;
signed int Palindrom = 0;
printf("Welche Aufgabe moechten Sie ausfuehren? (1-5)\n");
do {
    printf("-1- Aufsummieren von 1 bis n\n");
    printf("-2- Fibonacci Zahl berechnen\n");
    printf("-3- Zahl invertieren\n");
    printf("-4- Funktion func berechnen (rekursiv und iterativ)\n");
    printf("-5- Funktion foo berechnen\n");
    printf("-6- Ist deine gesuchte Zahl ein Palindrom?\n");
    printf("-7- Beenden\n");
    printf("Ihre Wahl: ");
    int checkInput = scanf(" %u", &count);
    if (checkInput != 1) {
        printf("Falscher Werteinput, nochmal\n");
        while (getchar() != '\n');
        continue;
    }
    switch (count) {
        case 1: 
        printf("Aufsummieren von 1 bis n mit n = ");
        int check = scanf(" %u", &n);
        if(check != 1) {
        printf("Fehler!");
        return 1;
        }
        else {
        printf("Die Summe ist: %u.\n", sum(n)); 
        break;
        }
        case 2:
        printf("Fibonacci Zahl berechnen mit a = ");
        int checkA = scanf(" %u", &a);
        if(checkA != 1) {
        printf("Fehler!");
        return 1;
        }
        else {
        printf("Die Fibonacci Zahl ist: %u.\n", fib(a));
        break;
        }
        case 3:
        printf("Zahl für invert\n");
        int checkInvert = scanf(" %d", &zahl);
        if(checkInvert != 1) {
            printf("Fehler!");
            return 1;
        }
        printf("Die invert ist %d\n", invert(zahl));
        printf("%d\n", invCounter);
        break;
        case 4:
        printf("Wert für func(): ");
        int checkFunc = scanf(" %u", &b);
        if(checkFunc != 1) {
        printf("Fehler!");
        return 1;
        }   
        printf("Der Wert für Func ist %u. bzw. %u\n", func(b), func_it(b));
        break;
        case 5:
        printf("Wert für die erste Zahl von foo(): ");
        int checkFoo1 = scanf(" %u", &l);
        if(checkFoo1 != 1) {
        printf("Fehler!");
        return 1;
        }   
        printf("Und die zweite Zahl: ");
        int checkFoo2 = scanf(" %lf", &k);
        if(checkFoo2 != 1) {
        printf("Fehler!");
        return 1;
        }
        printf("Der Wert für Foo ist %u.\n", foo(l, k));
        break;
        
        case 6:
        printf("Zahl für Palindrom prüfen: ");
        int palinInput = scanf(" %d", &Palindrom);
        if(palinInput != 1) {
            printf("Fehler!");
            return 1;
        }  
        PalindromLaenge(Palindrom);
        printf("Die Länge des Palindroms ist %d.\n", lenghtZahl);
        PalindromCheck(Palindrom, lenghtZahl);
        break; 
        
        case 7:
        printf("Auf Wiedersehen!\n");
            return 0;
        default:
            printf("Falscher Werteinput, nochmal\n");
            continue;
    }
}
while (1);
return 0;
}