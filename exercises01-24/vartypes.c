#include <stdio.h>
#include <stdlib.h>

char a = -123;
char b = 'q';
int num;

int main()
{
	printf("Char as int:%d Unsigned: %d\n",a,(unsigned char)a);
	printf("Char as char:%c\n", a);
	printf("Char hex value: %X\n",(unsigned char)a);
	printf("Char displayed normally: %c\n",(char)b);
	num = 0L;
	printf("Num: %d\n", num);
	
return 0;
}
