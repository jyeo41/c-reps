#include <stdio.h>
/* print Fahrenheit to Celsius table 
   in steps of 20 starting from fahr = 0 */

int main()
{
	float fahr, celsius;
	
	for(fahr = 0; fahr <= 300; fahr+= 20)
	{
		celsius = (5.0/9.0) * (fahr-32);
		printf("%3.0f\t%6.1f\n", fahr, celsius);
	}
}
