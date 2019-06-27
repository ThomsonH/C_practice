#include <stdio.h>

int main()
{
	int v1 = 2, v2 = 4;
	int *ptr;
	
	ptr = &v1;
	printf("value of ptr = %x\r\n", *ptr);
	printf("address of v1 = 0x%x\r\n", &v1);
	printf("address of v2 = 0x%x\r\n", &v2);
	printf("address of ptr = 0x%x\r\n", ptr);
	return 0;
}