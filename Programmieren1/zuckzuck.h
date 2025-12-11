#ifndef ZUCKZUCK_H
#define ZUCKZUCK_H

#include <stdio.h>

#define PROC_MAIN    int main(void)
#define BEGIN        {
#define END          }
#define SUCCESS      return 0;
#define WRITE(...)  printf(__VA_ARGS__);

#endif // ZUCKZUCK_H