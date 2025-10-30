#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <inttypes.h>
int main(void){
    
    int value1 = -56;
    unsigned int value2 = 1234567;
    long long int value3 = 01234567;
    char value4 = 'AB';
    float value5 = 3.4565465457;
    double value6 = 3.45654654567;

    printf("Value 1: %u\n", value1); printf("Size von dem Value: %llu Bytes \n", sizeof(value1));
    printf("Value 2: %u\n", value2); printf("Size von dem Value: %llu Bytes \n", sizeof(value2));
    printf("Value 3: %llu\n", value3); printf("Size von dem Value: %llu Bytes \n", sizeof(value3));
    printf("Value 4: %c\n", value4); printf("Size von dem Value: %llu Bytes \n", sizeof(value4));
    printf("Value 5: %.9f\n", value5); printf("Size von dem Value: %llu Bytes \n", sizeof(value5));
    printf("Value 6: %.5lf\n", value6); printf("Size von dem Value: %llu Bytes \n", sizeof(value6));
}