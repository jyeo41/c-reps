#include <stdio.h>
#include <string.h>
/* print Fahrenheit to Celsius table 
   in steps of 20 starting from fahr = 0 */

int main()
{
	float fahr, celsius;
	int space = 10; // used for formating the table headers
	int format = strlen("fahrenheit") + (space - 3) - (strlen("fahrenheit") - strlen("celsius"));

	printf("Printing a table for Fahrenheit to Celsius conversion\n");
	printf("Fahrenheit");
	printf("%*c", space-3, ' ');
	printf("Celsius\n");
	printf("-----------------------------------------------------\n");
	for(fahr = 0; fahr <= 300; fahr+= 20)
	{
		celsius = (5.0/9.0) * (fahr-32);
		printf("%3.0f\t%*.1f\n", fahr, format, celsius);
	}
	
	printf("\n");
	printf("Printing a table for Celsius to Fahrenheit conversion\n");
	printf("Celsius");
	printf("%*c", space, ' ');
	printf("Fahrenheit\n");
	printf("-----------------------------------------------------\n");
	for(celsius = -10; celsius <= 100; celsius += 10)
	{
		fahr = (9.0/5.0) * celsius + 32;
		printf("%3.0f\t%*.1f\n", celsius, format, fahr);
	}
}
