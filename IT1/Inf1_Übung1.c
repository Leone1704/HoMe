#include <math.h>
#include <stdio.h>

int main() {
//Aufgabe 1
    int var = 10;
    printf("value von int var ist %d\n", sizeof(var));
    //Aufgabe 2 
    int n;
    n = 5;
    //Initialiseieren ist, wenn man erst eine variable deklariert und diese danach einem Wert zuteilt

    //Aufgabe 3
    printf("Der Wert n ist %d\n", n);
    // Wenn die variable nicht implementiert wird, dann kommt der wert -358948800,  

    //Aufgabe 4 && 5
    const float pi = acos(-1);//Ausdruck um den Wert von Pi zu bekommen
    float A = 2 * pi * n; //Ausdruck um die Fläche eines Kreises zu berechnen
    printf("Fläche ist %f\n", A); //Anweisung um die Fläche auszugeben

    //Aufgaben Rest
    char a = 'a';
    printf("%c\n", a); //wird nicht benutzt, weil mit %d ausgegben wird und dann nummer ist 
    a = a - 32; //von klein in groß von 97 zu 65 mit minus 32
    printf("%c\n", a);

    a = (a >= 'a' && a  <= 'z' ) ? a - 32 : a + 32;
    printf("%c\n", a);
    printf("Char: %c in Dezimal %d",a ,a);


return 0;
}