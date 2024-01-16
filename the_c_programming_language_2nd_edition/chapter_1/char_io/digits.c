#include <stdio.h>

// program to count the number of digits, whitespace, and other characters

int main()
{
	int c, i, whitespace, otherchars;
	int digits[10];

	whitespace = otherchars = 0;

	for(i = 0; i < 10; i++)
	{
		digits[i] = 0;
	}
	while((c = getchar()) != EOF)
	{
		if (c >= '0' && c <= '9')
		{
			digits[c-'0']++;
		}
		else if (c == '\n' || c == ' ' || c == '\t')
		{
			whitespace++;
		}
		else
		{
			otherchars++;
		}	
		
		/*if(c != '\n')
		{
			printf("%-30s%c\n", "Input integer:", c);
			printf("%-30s%d\n", "Value of char as an integer:", c);
			printf("%-30s%d\n\n", "Value of c-'0'", (c-'1'));
		}*/
	}
	
	printf("%-20s", "Digits Array:");
	for(i = 0; i< 10; i++)	// prints the occurences of digits 1 ... 9 from input
	{
		printf("%d ", digits[i]);
	}
	printf("\n%-20s%d\n", "Whitespace count:", whitespace); // prints the occurences of white spaces from input
	printf("%-20s%d\n", "Otherchars count:", otherchars); // prints the occurences of non digit chars from input
}
