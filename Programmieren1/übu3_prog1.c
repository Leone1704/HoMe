# include <stdio.h>
#include <math.h>
#include <windows.h>

/*int main(void) {
int number;

printf("Bitte geben Sie eine ganze Zahl ein: ");

int result = scanf(" %d", &number);                         //Teil 1

if(result != 1) {
printf("Leider Fehler bei der Eingabe!\n");
return 1;
}
printf("Es wurde(n) %d Wert(e) eingegeben.\n", result);
printf("Der erste Wert lautet: %d\n", number);
return 0;
}*/

int main(void) {
float pi = acos(-1);
float r = 0;
float h = 0;
int auswahl = 0;
//printf("Der Wert von PI ist %f\n", pi);
printf("Welche Rechnung wollen sie unternehmen?\nKreisumfang berechnen (1)\nKreisflaeche berechnen (2)\nKugelvolumen berechnen (3)\nKegelvolumen berechnen (4)\n");
int frage = scanf("%d", &auswahl);
    /*if (auswahl != 1 && auswahl != 2 && auswahl != 3 && auswahl !=4) {
    printf("Ungueltige Auswahl.\n");
    Sleep(1000);
    printf("Bitte Eingabe wiederholen.\nKreisumfang berechnen (1)\nKreisflaeche berechnen (2)\n Kugelvolumen berechnen (3)\nKegelvolumen berechnen (4)\n");
    int frage = scanf("%d", &auswahl);
    }*/
    if (auswahl == 1) {
        printf("Wie lautet der radius zur Berechnung des Kreisumfangs?\n");             //Teil 2
        float result1 = scanf("%f", &r);
        float u = 2 * pi * r;
        printf("Der Kreisumfang ist %f\n", u);
        return 0;
    } 
    if (auswahl == 2) {
        printf("Wie lautet der Radius zur Kreisflaeche?");
        float result2 = scanf("%f", &r);
        double A = pi * r * r;
        printf("Die Kreisflaeche ist %f\n", A);
        return 0;
    }    
    if (auswahl == 3) {
    printf("Wie lautet der Radius zur Berechnung des Kugelvolumens?\n");
    float result3 = scanf("%f", &r);
    double Vu = (4.0/3.0) * pi * r * r * r;
    printf("Das Kugelvolumen ist %f\n", Vu);
    return 0;
    }
    if (auswahl == 4) {
    printf("Wie lautet der Radius und die Hoehe zur Berechnung des Kegelvolumens?\n");
    printf("r = ");
    float result4_1 =scanf("%f", &r);
    printf("h = ");
    float result4_2 = scanf("%f", &h);
    
    //int result4 = scanf("%d %d", &r, &h);
    double Vk = (1.0/3.0) * pi * r * r * h;
    printf("Das Kegelvolumen ist %f\n", Vk);
    return 0;
    }
    else {
    printf("Ungueltige Auswahl.\n");
    return 0;
    }
return 0;
}


