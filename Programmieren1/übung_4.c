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
        printf("die erste Zahl x ist nicht durch y teilbar");
        break;
        }
    printf("die erste zahl x ist durch y teilbar!");
    break;
    }   
    

    
    while (x <= y) {
    
        if(y % x != 0)     {
        printf("die zweite Zahl y ist nicht durch x teilbar");
        break;
        }
    printf("die zweite zahl y ist durch x teilbar!");
    break;
    }   
    
    return 0;
}
