#include <stdio.h>

#define	YES	1
#define	NO	0

int htoi(char s[]);

int main()
{
	// input a string of hexadecimal digits from the user
	// print the hexadecimal 
	// convert it to its integer value
	// print the integer value

	char hex[] = "0x000F8307";
	int c = 0, hexvalue = 0;
	hexvalue = htoi(hex);

	printf("\n%-12s", "Hexadecimal String: ");
	while (hex[c] != '\0')
	{
		printf("%c", hex[c]);
		++c;
	}
	printf("\n%-12s%d", "Integer Value: ", hexvalue);
	printf("\n");
}

int htoi(char s[])
{
	// needs to check the optional "0x"
	// needs to check if its a valid hexadecimal character per char in string
	// adds it to the final return number using proper arithmetic

	int i, returnval, hexdigit, validhex;

	i = 0;
	if(s[i] == '0')	// checking for optional '0x' or "0X"
	{
		++i;
		if(s[i] == 'x' || s[i] == 'X')
		{
			++i;
		}
	}
	
	validhex = YES;	// assumes its a valid hex string to start
	returnval = 0;
	for ( ; validhex == YES; ++i) // as long as its a valid hex string iterate through it
	{
		if (s[i] >= '0' && s[i] <= '9')	// checks if its a valid int between 0 to 9
		{
			hexdigit = s[i] - '0'; // subtract by the character constant '0' to return true int value
		}
		else if (s[i] >= 'a' && s[i] <= 'f')
		{
			hexdigit = s[i] - 'a' + 10; // same logic as above, but add 10 otherwise a to f returns int 0 to 4
		}
		else if (s[i] >= 'A' && s[i] <= 'F')
		{
			hexdigit = s[i] - 'A' + 10; // same logic as above
		}
		else
		{
			validhex = NO; // if its not a valid hex char, exit the loop
		}
		if (validhex == YES)
		{
			returnval = 16 * returnval + hexdigit; // arithmetic logic to compute appropriate 16^n exponent
							       // + hexdigit at the end of equation so 16^n is correct for
							       // each digit
		}
	}
	return returnval;
}
