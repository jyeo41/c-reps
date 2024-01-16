#include <stdio.h>

int main()
{
	int c, count_char = 0, count_newlines = 0, count_blanks = 0, count_tabs = 0; 
	
	while((c = getchar()) != EOF)
	{
		if(c == '\t')
		{
			++count_tabs;
		}
		else if(c == ' ')
		{
			++count_blanks;
		}
		else if(c == '\n')
		{
			++count_newlines;
		}
		else
		{
			++count_char;
		}
	}
	printf("%-20s%d\n", "Char count:", count_char);
	printf("%-20s%d\n", "Newlines count:", count_newlines);
	printf("%-20s%d\n", "Tabs count:", count_tabs);
	printf("%-20s%d\n", "Blanks count:", count_blanks);

}
