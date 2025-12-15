/*# include <stdio.h>
# define COUNT 12
int main(void) {
int intValues[COUNT];
for(int i = COUNT; i > 0; i--) {
intValues[i] = i;
}

int i = -1;
while(i < COUNT) {
printf("%d ", intValues[i]);
i++;
}
return 0;
}*/

/*#include <stdio.h>

int main(void) {
char letters[5] = { 'A', 'B', 'C', 'D', 'E'};

printf("Die ersten 5 Grossbuchstaben: \n");
for(char c = 0; c < 5; c++) {
printf("%c (ASCII: %d)\n", c, letters[c]);
}

printf("Hintereinander: %s\n", letters);
return 0;
}*/

#include <stdio.h>
#include <string.h>


int printArray(int arr[], int size) {
for (int i = 0; i < size; i++) {
    printf(" %d", arr[i]);
}
printf("\n");
}

int dreierTeiler(int arr[], int size) {
for (int i = 0; i < size; i++) {
    if (arr[i] % 3 == 0) {
        printf(" %d", arr[i]);
    }
}
printf("\n");
}

int plusDrei(int arr[], int size, int start) {
    int val = start;
for (int i = 0; i < size; i++) {
    arr[i] = val;
    printf(" %d", arr[i]);
    val += 3;
}
printf("\n");
}

int zwooo(int arr[], int size, int start) {
    int val = start;
for (int i = 0; i < size; i++) {
    arr[i] = val;
    printf(" %d", arr[i]);
    val = val *2 - 2;
}
printf("\n");
}

void readString(char String[]) {
    static int CountA = 0;
    static int Count = 0;
    char ch; 
    if (String[0] == '\0' || String[0] >= 200) {
        printf("Fehler: Ungültige Eingabe.\n");
        return;
    }
    printf("Der eingegebene String ist: %s\n", String);
    strlen(String);
    printf("Die Länge des Strings ist: %lu\n", strlen(String));
    printf("Welches Zeichen soll gezählt werden? \n");
    scanf(" %c", &ch);
    for (size_t i = 0; i < strlen(String); i++) {
        if (String[i] == 'A' || String[i] == 'a'){ 
            CountA++;
        } else if (String[i] == ch) {
            Count++;
        }
    }
    printf("Der String hat %d-mal den Buchstaben a", Count);
    printf(" und %d-mal das Zeichen %c.\n", Count, ch);
    return;
}

void readString2(char String[]){
    int Counter = 0;
    for (int i = 0; String[i] != '\0'; i++){
        if(String[i] < (char)64 || String[i] > (char)91){
            Counter++;
        }
    }
    printf("Anzahl der Buchstaben: %d\n", Counter);
}

void enZaehler(char String[]){
    int zaehler = 0;
    for (int i = 0; String[i] != '\0'; i++){
        if(String[i] == 'e' && String[i + 1] == 'n'){
            zaehler++;
        }
    }
    printf("Anzahl der en's: %d\n", zaehler);
}

void StringZaehler(char String[], char extra[]){
    int count = 0;
    int lenString = strlen(String);
    int lenExtra = strlen(extra);
    for (int i = 0; i <= lenString - lenExtra; i++){
        int j;
        for (j = 0; j < lenExtra; j++){
            if (String[i + j] != extra[j]){
                break;
            }
        }
        if (j == lenExtra){
            count++;
        }
    }
    printf("Der String '%s' kommt %d-mal in '%s' vor.\n", extra, count, String);
}

void Zellen(){
    
}
    

int main(void) {
/*int array[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
for (int i = 0; i < 10; i++) {
    printf(" %d", array[i]);
}*/
char extra[200];
char String[200];
int arr[10] = {1,2,3,4,5,6,7,8,9,10};
int big[41] = {5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
                15, 16, 17, 18, 19, 20, 21, 22, 23, 24,
                25, 26, 27, 28, 29, 30, 31, 32, 33, 34,
                35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45};
int x = -5;
int smol[10] = {x};
int zwo[10] = {0};
//printArray(arr, 10);
//dreierTeiler(big, 41);
//plusDrei(smol, 9, x);
//zwooo(zwo, 13, 3);
printf("Geben sie einen String ein: ");scanf("%s", String);
//readString(String);
//readString2(String);
//enZaehler(String);
printf("Geben sie einen String ein den Sie überprüfen möchten: ");scanf(" %s", extra);
StringZaehler(String, extra);

return 0;
}
