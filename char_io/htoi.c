#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define	YES	1
#define	NO	0

// program to convert hexadecimal string to integer value

int htoi(char s[]);
void validinput(char Buffer[], int bufferlength, char* hexstring);

int main()
{
	// input a string of hexadecimal digits from the user
	// print the hexadecimal 
	// convert it to its integer value
	// print the integer value

	char Buffer[12] = {0}; // max length of hexstring + 1
	char hexstring[11] = ""; // max length of hexstring is 10 for optional 0x + 8 digits, + 1 for null terminator
	int c = 0, hexvalue = 0;

	validinput(Buffer, 12, hexstring);
	hexvalue = htoi(hexstring);
	printf("\n%-12s", "Hexadecimal String: ");
	while (hexstring[c] != '\0')
	{
		printf("%c", hexstring[c]);
		++c;
	}
	printf("\n%-15s%d", "Integer Value: ", hexvalue); // testing self implement function
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
	 // testing self implement function
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

void validinput(char Buffer[], int bufferlength, char* hexstring)
{
	printf("Please enter a valid hex string of no more than 8 bytes\n");
	printf("The '0x' prefix is optional and inputs are case insensitive\n");

	int validhex = NO; // variable to test the length of the input hexstring to see if len <= 8
	while (validhex == NO)
	{
		fgets(Buffer, bufferlength, stdin); // reading user input into buffer stream

		// if input begins with 0x or 0X prefix
		if (Buffer[0] == '0' && (Buffer[1] == 'x' || Buffer[1] == 'X'))
		{
			// checking if \n character was successfully read into the subarray
			// bufferlength - 2 because - 1 would be the guaranteed NULL terminator
			// \n means the length of the hexstring is valid
			for (int i = 0; i <= bufferlength - 2; i++)
			{
				if (Buffer[i] == '\n')
				{
					validhex = YES;
					break;
				}
			}
		}
		// same logic but without the leading prefix
		// checking bufferlength - 4 because we need to account for the offset
		// from the lack of prefix
		else
		{
			for (int i = 0; i <= bufferlength - 4; i++)
			{
				if (Buffer[i] == '\n')
				{
					validhex = YES;
					break;
				}
			}
		}
		if (validhex == NO)
		{
			int ch;
			// used for clearing the input buffer if the input hexstring was too big
			// otherwise the fgets() reads the stored \n in the next call automatically
			// skipping the user input thinking it received one
			while ((ch = getchar()) != '\n' && ch != EOF)
			{
			}
			printf("The hexstring was too long, please try again.\n");
			printf("Enter a valid hexstring of max 8 bytes with optional prefix '0x' or '0X'\n\n");
		}

	}

	sscanf(Buffer, "%s", hexstring);
	
}
