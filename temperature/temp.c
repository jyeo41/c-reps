#include <stdio.h>
/* print Fahrenheit to Celsius table 
   in steps of 20 starting from fahr = 0 */

int main()
{
	int fahr, celsius;
	
	for(fahr = 0; fahr <= 300; fahr+= 20)
	{
		celsius = 5 * (fahr-32) / 9;
		printf("%3d\t%6d\n", fahr, celsius);
	}
}
