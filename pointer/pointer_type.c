#include <stdio.h>

int main()
{
	unsigned char Arr[4] = {0x11, 0x22, 0x33, 0x44};
	unsigned int *uiptr = Arr;
	
	printf("Addr of ARR = 0x%x\r\n", Arr);
	printf("0x%x\r\n", uiptr);
	
	unsigned int v1 = 0x55667788;
	unsigned char *ucptr = &v1;
	
	printf("first value of uc = 0x%x\r\n", ucptr[1]);
	
	return 0;
};