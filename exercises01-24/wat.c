#include<stdio.h>

unsigned int ui_one = 1;
signed int i_one = 1;
signed short s_minus_one = -1;

int main()
{
    if ((int)s_minus_one > (int)ui_one)
        printf("-1 > 1 \n");

    if ((int)s_minus_one < (int)i_one)
        printf("-1 < 1 \n");

    return 0;
}
