#include <stdio.h>

#define IS ==
#define TRUE 0

void main(void)
{
    int x = 0;

    if (x IS TRUE)
        printf("x is true\n");
    else
        printf("x is not true\n");
}
