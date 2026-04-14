#include <stdio.h>
#include <stdbool.h>

/*int main(void) {
int a = 21, b = 42;
bool r1 = (a == 21) && (a != 21); //0
bool r2 = (a == 21) || (a != 21); //1
bool r3 = (!( a == b / 2) && !( a - 21)); //0
bool r4 = a >= b || b - a >= a; //1
bool r5 = b % 21 + 1 && b / 21; //1
int r6 = a | b; //63
int r7 = a & b; //0
bool r8 = r6 && r7; //0
bool r9 = !((a != b) || (a < b)); //0
bool r10 = a == b && a >= b; //0
printf("r1: %d\nr2: %d\nr3: %d\nr4: %d\nr5: %d\nr6: %d\nr7: %d\nr8: %d\nr9: %d\nr10: %d\n", r1, r2, r3, r4, r5, r6, r7, r8, r9, r10);
return 0;
}
  */

int main() {
    printf("Geben sie zwei Ganzzahlen im Format xxx/yyy ein:\n");
    int x, y;
    int check = scanf("%d/%d", &x, &y);
    if (check != 2 || x < 0 || y < 0 || y > 1234 || x > 1234)
    {
        printf("Fehlerhafte Eingabe!\n");
        return 1;
    }

    
    printf("Die eingegebenen Zahlen sind %d und %d\n", x, y);
    
    
    while (y <= x) {
        
        if(x % y != 0)     {
        printf("die erste Zahl x ist nicht durch y teilbar\n");
        break;
        }
    printf("die erste zahl x ist durch y teilbar!\n");
    break;
    }   
    
    
    
    while (x <= y) {
    
        if(y % x != 0)     {
        printf("die zweite Zahl y ist nicht durch x teilbar\n");
        break;
        }
    printf("die zweite zahl y ist durch x teilbar!\n");
    
    break;
    }   
    

    int todo = -1;
    /*printf("-1- Vorlesung besuchen\n");
    printf("-2- Praktikumsaufgaben loesen\n");
    printf("-3- In die Bibliothek gehen\n");
    printf("-4- In die Mensa gehen (erst ab 11:30!)\n");
    printf("-5- Ausschlafen\n");
    printf("-6- Ein Weinchen trinken\n");
    printf("Was wollen Sie als naechstes tun?\n");
    if(scanf(" %d", &todo) != 1) {
    printf("Fehler bei der Eingabe!\n");
    return 1;
    }
    if(todo == 1) {
    printf("Besuche Vorlesung.\n");
    }
    else if (todo == 2) {
    printf("Nichts leichter als das!\n");
    }
    else if (todo == 3) {
    printf("Dann los in die Bibliothek.\n");
    }
    else if (todo == 4) {
    printf("Guten Appetit!\n");
    }
    else if (todo == 5) {
    printf("*Gaehn*, gute Nacht!\n");
    }
    else if (todo == 6) {
    printf("Zum Fruehstueck? Echt jetzt?\n");
    }
    else {
    printf("Unbekannter Code (%d)\n", todo);
    }*/
    do {
        printf("-1- Vorlesung besuchen\n");
        printf("-2- Praktikumsaufgaben loesen\n");
        printf("-3- In die Bibliothek gehen\n");
        printf("-4- In die Mensa gehen (erst ab 11:30!)\n");
        printf("-5- Ausschlafen\n");
        printf("-6- Ein Weinchen trinken\n");
        printf("-7- Alles erledigt!\n");
        printf("Was wollen Sie als naechstes tun?\n");
        scanf("%d", &todo);

        switch (todo) {
            case 1:
                printf("Besuche Vorlesung.\n");
                break;
            case 2:
                printf("Nichts leichter als das!\n");
                break;
            case 3:
                printf("Dann los in die Bibliothek.\n");
                break;
            case 4:
                printf("Guten Appetit!\n");
                break;
            case 5:
                printf("*Gaehn*, gute Nacht!\n");
                break;
            case 6:
                printf("Zum Fruehstueck? Echt jetzt?\n");
                break;
            case 7: 
                printf("Super gemacht!\n");
                break;
            default:
                printf("Unbekannter Code (%d)\n", todo);
                break;
            } 
        }
    while (todo != 7);
    return 0;
}