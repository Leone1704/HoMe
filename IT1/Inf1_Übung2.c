#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
    printf("  I N F O\v\tR\v\tM A T I K\n\n\n");
    float a = 1000.50f, b = 150.70f, c = 2150.75f, d = 20.00f, summe = a + b + c + d; //Wenn ich die Summe unformatiertrt ausgebe, stimmt sie nicht genau, bzw sie spuckt mehr Nachkommastellen aus
    printf("\t%7.2f\n\t%7.2f\n\t%7.2f\n\t%7.2f\nSumme:  %7.2f\n\n", a, b, c, d, summe);
    

    //Zeichentabelle:
    char a1 = 201; //╔
    char b1 = 187; //╗ 
    char c1 = 200; //╚ 
    char d1 = 188; //╝ 
    char e1 = 205; //═ 
    char f1 = 186; //║  
    printf("\t%c%c%c%c%c%c%c%c\n\t%c      %c\n\t%c      %c\n\t%c      %c\n\t%c%c%c%c%c%c%c%c\n\n",a1,e1,e1,e1,e1,e1,e1,b1,f1,f1,f1,f1,f1,f1,c1,e1,e1,e1,e1,e1,e1,d1); //Zurzeit 6 Leertasten. Hier gerade ASCII Code 
    printf("\t╔═════╗\n\t║     ║\n\t║     ║\n\t║     ║\n\t╚═════╝"); //Für UTF-8
}

/*




Fehler im Quellcode: 
int Main () {                                       --> Main wurde groß geschrieben
    
    int a = 10 b = 20, c;                           --> Fehlendes Komma nach 10 // c muss initialisiert werden
    
    int summe = a + b + c                           --> Semantikfehler, da c nicht initialisiert ist // Semikolon fehlt
    printf(Summe der Variablen: d% \n", Summe);     --> Fehlende Anführungszeichen am Anfang (Syntax) // falscher Variablenname (Summe statt summe)(Syntax) // d% statt %d (Semantik), würde aber noch funktionieren.

    
    
    return 0;
}

printf("Programm-Ende\n");                          --> Falscher Platz, außerhalb der main-Funktion (Syntax)
*/