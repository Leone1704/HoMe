#include <stdio.h>
#include <stdlib.h>

int getCount() {
    int count;
    int parameter = 10;
    int AbbruchCounter = 0;
    printf("Wieviele Zahlen wollen Sie im folgenden eingeben: ");
    while(!(scanf(" %d", &count) == 1 && count > 0 && count <= parameter))
    {
        while (getchar() != '\n');
        printf("Ungültige Anzahl: Bitte eine Zahl zwischen 1 und %d eingeben.\n", parameter);
        AbbruchCounter++;
        if (AbbruchCounter == 3) {
            printf("Zu viele ungültige Eingaben. Programm wird beendet.\n");
            exit(0);
        }
    }
    return count;
}

void readValues(int count, int values[]) {
    for (int i = 0; i < count; i++) {
        printf("%d.Zahl: ", i + 1);
        scanf("%d", &values[i]);
    }
}

int calculateSum(int count, int values[]) {
    int sum = 0;
    printf("Die Summe wird nun berechnet...\n");
    for (int i = 0; i < count; i++) {
        sum += values[i];
    }
    return sum;
}

int main() {
    int values[100] = {0};
    
    int count = getCount();
    readValues(count, values);
    int sum = calculateSum(count, values);
    
    printf("Die Summe der Zahlen ist: %d\n", sum);

    return 0;
}


