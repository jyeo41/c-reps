// simple program to test char input output

#include <stdio.h>

int main()
{
	int c;

	printf("Value of EOF: %d\n", EOF);
	while((c = getchar()) != EOF)
	{
		putchar(c);
	}
	
	
}
