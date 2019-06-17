#include <stdio.h>

int main(int argc, char *argv[])
{

	printf("Length of char :%d\r\n", sizeof(unsigned char));
	printf("Length of short :%d\r\n", sizeof(short));
	printf("Length of int :%d\r\n", sizeof(int));
	printf("Length of float :%d\r\n", sizeof(float));
	printf("Length of double :%d\r\n", sizeof(double));

	char word = 'c';
	printf("Character : \'%c\', Decimal : \'%d\', Hex : \'%x\'\r\n", word, word, word);
	return 0;
}