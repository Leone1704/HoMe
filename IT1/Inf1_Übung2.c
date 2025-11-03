#include <stdio.h>
#include <math.h>

int main() {
    printf("  I N F O\v\tR\v\tM A T I K\n\n\n");
    float a = 1000.50f, b = 150.70f, c = 2150.75f, d = 20.00f, summe = a + b + c + d; //Wenn ich die Summe unformatiertrt ausgebe, stimmt sie nicht genau, bzw sie spuckt mehr Nachkommastellen aus
    printf("\t%7.2f\n\t%7.2f\n\t%7.2f\n\t%7.2f\nSumme:  %7.2f\n\n", a, b, c, d, summe);
    

    //Zeichentabelle:
    char a1 = 201; //╔
<<<<<<< HEAD
    char b1 = 187; //╗
    char c1 = 200; //╚
    char d1 = 188; //╝
    char e1 = 205; //═
    char f1 = 186; //║
    int breite, hoehe;
    
    printf("Wie hoch und wie breit soll der Kasten sein?\nSchreibe folgenderweiße: yy/xx (hoehe/breite)\n");
    scanf("%d/%d", &hoehe, &breite);
    
    // Obere Zeile mit Einrückung
    printf("\t%c", a1);
    
    // Horizontale Linien (oben und unten)
    char line[100] = "";
    for(int i = 0; i < breite; i++) line[i] = e1;
    line[breite] = '\0';
    
    // Mittlere Leerzeilen
    char spaces[100] = "";
    for(int i = 0; i < breite; i++) spaces[i] = ' ';
    spaces[breite] = '\0';
    
    // Kompletter Kasten mit 5 printf Befehlen
    printf("%s%c\n", line, b1);
    for(int zeile = 0; zeile < hoehe; zeile++) {
        printf("\t%c%s%c\n", f1, spaces, f1);
    }
    printf("\t%c%s%c", c1, line, d1);
    return 0;
=======
    char b1 = 187; //╗ 
    char c1 = 200; //╚ 
    char d1 = 188; //╝ 
    char e1 = 205; //═ 
    char f1 = 186; //║  
    printf("\t%c%c%c%c%c%c%c%c\n\t%c      %c\n\t%c      %c\n\t%c      %c\n\t%c%c%c%c%c%c%c%c\n\n",a1,e1,e1,e1,e1,e1,e1,b1,f1,f1,f1,f1,f1,f1,c1,e1,e1,e1,e1,e1,e1,d1); //Zurzeit 6 Leertasten. Hier gerade ASCII Code 
    printf("\t╔═════╗\n\t║     ║\n\t║     ║\n\t║     ║\n\t╚═════╝"); 
>>>>>>> 1b4de5766dae3dca68a76f341c3b183f0c39dfec
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