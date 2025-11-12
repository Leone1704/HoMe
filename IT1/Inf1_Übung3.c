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
    printf("%d\n", c);
    /*
    Der naive Wert von c ist beim ersten hinschauen 33200. Doch nach kurzer überlegung fällt etwas auf.
    Der wahre Wert von c ist negativ, da bei der Addition der Werte von a und b ein Überlauf (Overflow) stattfindet.
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
    //Aufgabe 3
    printf("%f\n", x);
    /*Der naive Wert von x ist 1.5. Da div1 und div2 beide Integer sind, wird die Division als Ganzzahl-Division durchgeführt,
    was bedeutet, dass der Bruchteil abgeschnitten wird. Das Ergebnis der Division von 3 durch 2 ist also 1.
    Dieses Ergebnis wird dann in den Float-Datentyp konvertiert, was zu 1.0 führt.
    Um das korrekte Ergebnis von 1.5 zu erhalten, müsste mindestens einer der Operanden als Float deklariert werden,  z.B.:*/
    float x2 = (float)div1 / div2;
    printf("%f\n", x2);
    //Aufgabe 4
    printf("%d\n", (++wert1 == wert2--));/*--> das Ergebnis sollte 1, also true, da zuerst wert1 um 1 
    eröht wird, aber wert2 erst nachm vergleich erhöht wird, also vergleicht das ganze gerade 11 == 11, 
    danach wird wert2 auf 10 gesetzt.*/
    printf("%d\n", (wert1++ == ++wert2)); // vergleicht 11 == 11, danach wird wert1 auf 12 gesetzt.
    printf("%d\n", (wert1 == ++wert2)); // vergleicht 12 == 12 
    // --> daher immer 1 als ergebnis.
    
    //Aufgabe 5
    wert1 = 10, wert2 = 11, wert3 = 127;
    printf("%d\n" , (!wert1 || wert2 && ++wert3)); 
    // (0 || 1 && 1) --> 1 Hier wird alles mit 0 verglichen, alle ungleich 0, also 1, aber !wert1 macht daraus 0.
    printf("%d\n" , (wert1 || !wert2 && ++wert3)); 
    // (1 || 0 && 1) --> (1 || 0) --> 1 
    printf("%d\n" , (wert1 & wert2)); 
    // hier wird der bitweise AND operator verwendet. 10 = 1010 und 11 = 1011 --> 1010 & 1011 = 1010 --> 10 
    //also die gleichen bits werden beibehalten, der rest wird zu 0.

    //Aufgabe 6
    float a1 = 100.2, b1 = 0.1;
    float a2 = 100.5, b2 = 0.2;
    a1 = 0.2;
    a2 = 0.5; //Vermeidung von Rundungsfehlern durch direkte Zuweisung der genauen Werte. Dadurch wird sichergestellt, dass die Werte exakt sind und keine Ungenauigkeiten durch vorherige Berechnungen entstehen.
    float e1 = a1 + b1;
    float e2 = a2 - b2;
    

    if(e1 == e2) 
    printf("Die Zahlen sind gleich!\n");
    else printf("Die Zahlen sind nicht identisch\n");
    // Die Zahlen sind nicht identisch, da bei der Addition und Subtraktion von Gleitkommazahlen Rundungsfehler auftreten können.
    //In diesem Fall führt die Addition von 100.2 und 0.1 zu einem Ergebnis, das geringfügig von dem Ergebnis der Subtraktion von 100.5 und 0.2 abweicht.
    //Dies liegt daran, dass Gleitkommazahlen nicht exakt dargestellt werden können, was zu kleinen Ungenauigkeiten bei mathematischen Operationen führt.
    // Copilot warum scheint es bei größeren Zahlen zu existieren und bei kleineren nicht? Schauen Sie sich dazu den IEEE754 Standard an.
    // Der IEEE754 Standard definiert, wie Gleitkommazahlen im Binärformat dargestellt werden. Bei größeren Zahlen kann es zu mehr Rundungsfehlern kommen, da die Anzahl der signifikanten Stellen begrenzt ist.
    // um das ganze zu vermeiden würde ich den dezimalen Datentyp verwenden, der eine höhere Genauigkeit bietet oder eine Abweichung zulassen.
}