#include <stdio.h>
#include <math.h>

void ausgabe(){
    unsigned char wert1 = 10, wert2 = 10, wert3 = 255;
    int a = 2, b = 3, c = 4, f = 3;
    /*1*/printf("%d\n", (c - a % b)); //2
    /*2*/printf("%d\n", (c - b * --f)); //-2 
    /*3*/printf("%d\n", (wert1 ^ wert2)); // 1010 ^ 1010 = 0
    /*4*/printf("%d\n", (wert1 - 2 ^ wert2 + 2)); // 1000 ^ 1100 = 0100 --> 4
    /*5*/printf("%d\n", (wert1 >> 1));// sollte 5 sein nach kurzer rechereche, dachte dass nur der erste verschoben wird
    /*6*/printf("%d\n", (wert1 << 2));//1010 --> 101000 = 40
    /*7*/printf("%d\n", (wert1 & wert2));// 1010 & 1010 --> 1010 = 10
    /*8*/printf("%d\n", (!wert1 || wert2 && ++wert3)); //jz wirds lustig ==> !10 || 10 && 0? --> 0 || 0 --> 0
    /*9*/printf("%d\n", (wert1 || !wert2 && ++wert3)); // 10 || 0 && 1 --> 10|| 0 --> 1?
    /*10*/printf("%X\n", (~wert3 - 1)); // zuerst an 0 gedacht hmmm..hmmmmmmmmm naja da musste ich mir helfen lassen. 10te 3.wert wird durch 8. zu 0
    //, dann wird das ganze umgedreht, aber anscheinend als int mit 32 Bit gewertet und somit --> FFFFFFFE 
    wert3 = 255; //zurücksetzen
    /*11*/printf("%d\n", (unsigned char)(wert3 << 1)); // 255 >> 11111111 --> 111111110 = 510, aber wir haben nur 8 bit also 11111110 = 254, 
    //das problem damit ist dass die 1 die rausfällt verloren geht bzw. woanders hin verschoben wird
    //behebung durch int casten
    /*12*/printf("%d\n", (int)(wert3 << 1)); // jetzt sollte es klappen
}

int sensor(){
    int sensorValue = 20;
    if(10 <= sensorValue && sensorValue <= 30 )  
        printf("Sensorwert liegt im Intervall");
    else
        printf("Sensorwert liegt nicht im Intervall");
}

int check(){
    int a = -1;
    unsigned int b = 1;
    unsigned int c = 0xFFFFFFFFu;

/*  a) Welchen Typ hat der Ausdruck (a < b) und welchen Wert?           // Der Ausdruck hat den Typ int und den Wert 1 (wahr)
    b) Welchen Wert hat der Ausdruck a + b (als int interpretiert)?     // Der Ausdruck hat den Wert 0, da 2^32 + 1 = 0 owerflow
    c) Welchen Wert hat der Ausdruck b + c (als unsigned int)?          // 0xFFFFFFFF + 1 = 0 (overflow)    
    d) Welchen Wert hat der Ausdruck a == c?*/                          // müsste 0 sein da c nen unsigned int ist und a negativ ist
}

int main(void) {
    //ausgabe();
    sensor();
    return 0;
}
//a) optional
/*
int a = 24789;
int b = 10212;
a ^= b;
b ^= a;
a ^= b;
- Was macht dieser Code? Geben Sie eine alternative Variante ohne Bitoperationen an.
- Welchen Vorteil bietet dieser Art der Programmierung?
- Recherchieren Sie ggf. nach möglichen Nachteilen?
- Recherchieren Sie, warum das ganze so funktioniert!

Dieser Code tauscht die Werte von a und b ohne eine temporäre Variable zu verwenden.
Alternative Variante ohne Bitoperationen:
int temp = a;
a = b;  
b = temp;
Vorteil: Spart Speicherplatz, da keine zusätzliche Variable benötigt wird.
Nachteile: Kann schwerer zu lesen und zu verstehen sein, besonders für Anfänger. Zudem kann es bei bestimmten Datentypen 
oder Compiler-Optimierungen zu unerwartetem Verhalten führen.

24789 = 1100000011010101           
10212 = 0010011111100100       

a ^= b;  1110011100110001

1110011100110001
0010011111100100
-->
1100000011010101
b ^= a;  1100000011010101

1110011100110001
1100000011010101

a ^= b; 0010011111100100

b)


*/