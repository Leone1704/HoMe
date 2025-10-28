#include <stdio.h>
#include <math.h>

int main() {
    /*printf("  I N F O\v\tR\v\tM A T I K\n\n\n");
    float a = 1000.50f, b = 150.70f, c = 2150.75f, d = 20.00f, summe = a + b + c + d; //Wenn ich die Summe unformatiertrt ausgebe, stimmt sie nicht genau, bzw sie spuckt mehr Nachkommastellen aus
    printf("\t%7.2f\n\t%7.2f\n\t%7.2f\n\t%7.2f\nSumme:  %7.2f\n", a, b, c, d, summe);
    */

    //Zeichentabelle:
    char a = 201; //╔
    char b = 187; //╗
    char c = 200; //╚
    char d = 188; //╝
    char e = 205; //═
    char f = 186; //║ 
   printf("\t%c%c%c%c%c%c%c%c\n\t%c      %c\n\t%c      %c\n\t%c      %c\n\t%c%c%c%c%c%c%c%c",a,e,e,e,e,e,e,b,f,f,f,f,f,f,c,e,e,e,e,e,e,d); //Zurzeit 6 Leertasten
    return 0;
}