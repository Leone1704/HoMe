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
Aufgabe 2-b
a) Erläutern Sie kurz die beiden Begriffe Syntax und Semantik bzgl. der Programmierung.
Antwort:
Syntax bezeichnet die korrekte Anordnung von Zeichen und Befehlen in einer Programmiersprache, ähnlich wie Grammatik in der natürlichen Sprache. 
Semantik hingegen bezieht sich auf die Bedeutung und den Zweck dieser Befehle und Anweisungen im Kontext des Programms.

b) Erklären Sie wie sich falsche Syntax und Semantik auf den Quelltext/Programm auswirkt.
Antwort: 
Falsche Syntax:
- Führt zu Kompilierungsfehlern, das Programm kann nicht übersetzt werden
- Der Compiler erkennt die Fehler und gibt entsprechende Fehlermeldungen aus
- Beispiel: Fehlende Semikolons, falsche Klammerung, unbekannte Befehle

Falsche Semantik:
- Das Programm kann kompiliert werden, führt aber nicht die beabsichtigte Funktion aus
- Logische Fehler, die erst zur Laufzeit oder in den Ergebnissen erkennbar werden
- Beispiel: Falscher Operatorgebrauch (+ statt *), falsche Bedingungen in if-Anweisungen
- Ich würde auch sagen, dass semantische Fehler oft schwerer zu erkennen und zu beheben sind als syntaktische Fehler, da sie nicht sofort offensichtlich sind.
- Zudem sind sie ein größeres Risiko für die Zuverlässigkeit und Korrektheit des Programms, da solche Logikfehler gerne auch ausgenutzt werden können (Siehe eigene Erfahrungen).



Fehler im Quellcode: 
int Main () {                                       --
    
    int a = 10 b = 20, c;                           --> Fehlendes Komma nach 10 // c muss initialisiert werden
    
    int summe = a + b + c                           --> Semantikfehler, da c nicht initialisiert ist // Semikolon fehlt
    printf(Summe der Variablen: d% \n", Summe);     --> Fehlende Anführungszeichen am Anfang (Syntax) // falscher Variablenname (Summe statt summe)(Syntax) // d% statt %d (Semantik), würde aber noch funktionieren.

    
    
    return 0;
}

printf("Programm-Ende\n");                          --> Falscher Platz, außerhalb der main-Funktion (Syntax)
*/