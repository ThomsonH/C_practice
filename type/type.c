#include <stdio.h>

int main(void)
{
	unsigned int num = 10;
	float num2 = 1.5;
	printf("%d\n", num);
	num2 = num;
	printf("%f\n", (float)num);
	
	printf("%d\n", num/3);
	printf("%d\n", num%3);
	
	return 0;
}

