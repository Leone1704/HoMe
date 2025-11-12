# include <stdio.h>
# include <stdlib.h>
# include <math.h>

# define GRADE_MIN 1
# define GRADE_MAX 6

unsigned int countOverall = 0;
unsigned int countGrade1 = 0, countGrade2 = 0, countGrade3 = 0,
            countGrade4 = 0, countGrade5 = 0, countGrade6 = 0;
unsigned int count = 0;



void readValues(unsigned int count) {
    printf("Sie möchtern %u Noten eingeben.\n", count);
    printf("Geben Sie %u Noten im Bereich von %d bis %d ein:\n", count, GRADE_MIN, GRADE_MAX);
    
    for(unsigned int i = 0; i < count; i++){
        unsigned int current = 0;
        unsigned int versuche = count - i;
        scanf(" %u", &current); 
        countOverall += 1;
        switch(current) {
            case 1: countGrade1++; break;
            case 2: countGrade2++; break;
            case 3: countGrade3++; break;
            case 4: countGrade4++; break;
            case 5: countGrade5++; break;
            case 6: countGrade6++; break;
            default: printf("Falscher Werteinput, nochmal. Sie haben %u Versuche\n", versuche); i--; countOverall--; break;
        }
    }
}

void printGrades(void){
    printf("Notenspiegel:\n");
    printf("Note 1: %u\n", countGrade1);
    printf("Note 2: %u\n", countGrade2);
    printf("Note 3: %u\n", countGrade3);
    printf("Note 4: %u\n", countGrade4);
    printf("Note 5: %u\n", countGrade5);
    printf("Note 6: %u\n", countGrade6);
    printf("Insgesamt wurden %u Noten eingegeben.\n", countOverall);
}

float computeMean(void){
    if (count == 0) {
        return 0.0f; // Schutz vor Division durch Null
    }
    float Durchschnitt = (countGrade1 * 1 + countGrade2 * 2 + countGrade3 * 3 + countGrade4 * 4 + countGrade5 * 5 + countGrade6 * 6) / (float)count;
    return Durchschnitt;
}

float standartAbweichung(void){
    if (countOverall == 0) {
        return 0.0f; // Schutz vor Division durch 0
    }
    double mean = computeMean();
    double meanSq = ((double)countGrade1 * 1.0 * 1.0
                   + (double)countGrade2 * 2.0 * 2.0
                   + (double)countGrade3 * 3.0 * 3.0
                   + (double)countGrade4 * 4.0 * 4.0
                   + (double)countGrade5 * 5.0 * 5.0
                   + (double)countGrade6 * 6.0 * 6.0) / (double)countOverall;
    double variance = meanSq - (mean * mean);
    double stdAbw = sqrt(variance);
    return stdAbw;
}

double computeMedian(void){
    // Median Berechnung
    double pos1 = 0, pos2 = 0;
    int cum = 0; //cumulated XD
    int val1 = 0, val2 = 0;
    if (countOverall % 2 == 1) {
        pos1 = (countOverall + 1) /2;
        pos2 = pos1;
    } else {
        // Gerade Anzahl von Noten
        pos1 = countOverall /2;
        pos2 = (countOverall + 1)/2;
    }
    cum += countGrade1;
    if (val1 == 0 && cum >= pos1) val1 = 1;
    if (val2 == 0 && cum >= pos2) val2 = 1;
    /* Note 2 */
    cum += countGrade2;
    if (val1 == 0 && cum >= pos1) val1 = 2;
    if (val2 == 0 && cum >= pos2) val2 = 2;
    /* Note 3 */
    cum += countGrade3;
    if (val1 == 0 && cum >= pos1) val1 = 3;
    if (val2 == 0 && cum >= pos2) val2 = 3;
    /* Note 4 */
    cum += countGrade4;
    if (val1 == 0 && cum >= pos1) val1 = 4;
    if (val2 == 0 && cum >= pos2) val2 = 4;
    /* Note 5 */
    cum += countGrade5;
    if (val1 == 0 && cum >= pos1) val1 = 5;
    if (val2 == 0 && cum >= pos2) val2 = 5;
    /* Note 6 */
    cum += countGrade6;
    if (val1 == 0 && cum >= pos1) val1 = 6;
    if (val2 == 0 && cum >= pos2) val2 = 6;

    /* Median ist Mittelwert der beiden Positionen (bei ungerader N sind pos1==pos2) */
    return ((double)val1 + (double)val2) / 2.0;
}

int main(void) {
    
    unsigned int current = 0;
    printf("Wie viele Pruefungsnoten wollen Sie eingeben?\n ");

    if(scanf(" %u", &count) != 1) {
        printf("Fehlerhafte Eingabe!\n");
        exit(EXIT_FAILURE);
    }
    else {
        readValues(count);
        printf("Folgende Noten wurden eingegeben:\n");
        printGrades(); 
        float rück = computeMean();
        printf("Die Durchschnittsnote ist %.2f\n", rück);
        float abweichung = standartAbweichung();
        printf("Die Standardabweichung ist %.2f\n", abweichung);
        double median = computeMedian();
        printf("Der Median ist %.2f\n", median);
        return 0;
    }
}
