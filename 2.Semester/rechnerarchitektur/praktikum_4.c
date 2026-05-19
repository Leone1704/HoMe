/*
a) 
ax bekokmt 64 als dez und 24 als dez
called die unter prozedur funk1
funk1: 
compared ax mit bx, wenn ax == bx, dann return 0
wenn ax > bx dann jump in funktion L1
L1 setzt cx auf den wert von ax und danach wird ax = ax - bx gerechnet
wenn ax < bx, dann wird bx = bx - ax gerechnet
und dann wird das ganze wiederholt bis ax == bx
also werden immer die werte von einander abgezogen
also eine funktion die theoretisch ein gemeinsamen nenner findet? vielleicht sogar den größten?
64-24
40-24
24-16
16-8
8==8, jap also den 

b) dat macht hier garnichts, ich kann mir aber 
denken, dass damit später gerechnter werden 
möchte, weil der letzte wert von ax benutzt 
wird, wo ax größer als bx ist

c) die programm ausgabe ist 8 auf ascii ebene, 
da 48 der anfang von 0 in der ascii tabelle ist








*/

#include <stdio.h>

volatile int cx = 0;

int funk1(int ax, int bx) {
    while(ax != bx){
    if(ax > bx){
        cx = ax;
        ax = ax - bx;
    } else if(ax < bx){
        bx = bx - ax;
    }
    
    }
    printf("ax = %d = bx = %d", ax, bx);
}

int main(){
    funk1(64, 24);

}

