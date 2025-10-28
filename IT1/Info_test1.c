#include <stdio.h>

int main(void){
    int alter = 0;
    printf("Wie alt bist du?\n");
    scanf("%d", &alter);
    printf("Du bist '%d' Jahre alt.\n", alter);
    
    return 0;
}