#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <inttypes.h>
int main(void){
    
    int value1 = -56;
    unsigned int value2 = 1234567;
    long long int value3 = 01234567;
    char value4 = 'A';
    float value5 = 3.456546545f;
    double value6 = 3.45654654567;
    size_t groese1 = sizeof(value1/*, value2, value3, value4, value5, value6*/);
    /*size_t groese2 = sizeof(value2);
    size_t groese3 = sizeof(value3);
    size_t groese4 = sizeof(value4);
    size_t groese5 = sizeof(value5);
    size_t groese6 = sizeof(value6);*/


    printf("Value: %d\t", value1);
    printf("Size von dem Value: %llu Bytes \n", sizeof(value1));

    printf("Value: %u\n", value2); printf("Size von dem Value: %llu Bytes \n", sizeof(value2));
    printf("Value: %08lld\n", value3); printf("Size von dem Value: %llu Bytes \n", sizeof(value3));
    printf("Value: %c\n", value4); printf("Size von dem Value: %llu Bytes \n", sizeof(value4));
    printf("Value: %.9f\n", value5); printf("Size von dem Value: %llu Bytes \n", sizeof(value5));
    printf("Value: %.5lf\n", value6); printf("Size von dem Value: %llu Bytes \n", sizeof(value6));
    printf("value1 von %d bis %d\n", INT_MIN, INT_MAX);
    printf("value2 von %u bis %u\n", 0, UINT_MAX);
    printf("value3 von %lld bis %lld\n", LONG_LONG_MIN, LONG_LONG_MAX);
    printf("value4 von %hhd bis %hhd\n", CHAR_MIN, CHAR_MAX);
    printf("value5 von %.9f bis %.9f\n", FLT_MIN, FLT_MAX );
    printf("value6 von %.5lf bis %.5lf\n", DBL_MIN, DBL_MAX);
    int16_t value7 =4;
    //printf("Size von value1: %zu Bytes\n", groese1);


}