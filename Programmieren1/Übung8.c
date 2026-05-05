#define zuckzuck.h <stdio.h>
#include <stdio.h>
//#include zuckzuck.h


#define PROC_MAIN int main()
#define BEGIN {
#define WRITE printf
#define SUCCES return 0;
#define END }

PROC_MAIN
BEGIN
    WRITE("Hallo Welt!\n");
    SUCCES
END