#include<stdio.h>

int main(int argc, char *argv[])
{
	//Arithmetic operator
	int num1 = 10, num2 = 20;
	double num3 = 30.0;
	
	printf("%d + %d = %d\r\n", num1, num2, num1+num2);
	printf("%d - %d = %d\r\n", num1, num2, num1-num2);    //Signed!!!
	printf("%d * %d = %d\r\n", num1, num2, num1*num2);	
	printf("%d / %d = %d\r\n", num1, num2, num1/num2);
	
	//Type conversion
	printf("%f \r\n", num3 / 3);
	//                       ↑ is a integer, implicit type conversion
	
	printf("%f \r\n", (double)num1 / 3);
	//                   ↑ explicit cast, convert integer to float type.
	
	//Relational operator
	//printf();
	
	//Conitional operator
	printf("num1 > num2 : %s\r\n", num1 > num2 ? "True" : "False");
	
	unsigned int bitnum = 1, shift = 3;
	//Bitwise left shift assignment
	printf("%d left shift %d: %d\r\n", bitnum, shift, bitnum<<shift);
	//Bitwise right shift assignment
	bitnum <<= shift;
	printf("%d right shift %d: %d\r\n", bitnum, shift, bitnum>>shift);
	
	
	return 0;
}