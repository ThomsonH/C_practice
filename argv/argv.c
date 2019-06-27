#include <stdio.h>

int main(int argc, char *argv[])
{  
	if(argc > 1)
	{
		printf("%s\r\n", *argv);
		printf("%s\r\n", *(argv + 1));
	}
	else
	{
		printf("Too few argument!\r\n");
	}
	
	return 0;
}