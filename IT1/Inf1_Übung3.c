#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
    char wert1 = 10, wert2 = 11, wert3 = 127;
    short a = 30000, b = 3200, c = a + b;
    int div1 = 3, div2 = 2;
    float x = div1 / div2;
    //Aufgabe 1
    char komplementWert1 = ~wert1 + 1; 
    char komplementWert2 = ~wert2 + 1; 
    char ergebnis = wert1 + komplementWert2;
    printf("Das Ergebnis von %d + (%d) ist: %d\n", wert1, komplementWert2, ergebnis);
    //Aufgabe 2
    printf("%d", c);
    /*
    Der Wert von c ist negativ, da bei der Addition der Werte von a und b ein Überlauf (Overflow) stattfindet.
    Der maximale Wert, den ein short-Datentyp speichern kann, wird überschritten, was zu einem negativen Ergebnis führt.
    30000 --> 0
    15000 --> 0
    7500 --> 0
    3750 --> 0  
    1875 --> 1
    937  --> 1
    468  --> 0
    234  --> 0
    117  --> 1
    58   --> 0
    29   --> 1
    14   --> 0
    7    --> 1
    3    --> 1
    1    --> 1
    0    --> 0

    3200 --> 0
    1600 --> 0
    800  --> 0
    400  --> 0
    200  --> 0
    100  --> 0
    50   --> 0
    25   --> 1
    12   --> 0
    6    --> 0
    3    --> 1
    1    --> 1
    0    --> 0
    3200 in Binär: 0000 1100 1000 0000
    30000 in Binär: 0111 0101 0011 000
    Ergebnis in Binär: 1000 0001 1011 0000 --> -32336 
    */
}