#include <stdio.h>

int main(void){
    int monat, tag;
    printf("Gib dein Geburtstag folgenderweiße an : mm/tt\n");
    scanf("%d/%d", &monat, &tag);
    printf("Du hast am %d/%d Geburtstag\n", tag, monat);
    
    return 0;
}