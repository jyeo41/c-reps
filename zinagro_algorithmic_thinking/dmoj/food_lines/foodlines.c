#include <stdio.h>

int shortest_line_index(int lines[], int n);
void solve_lines(int lines[], int n, int m);

#define MAX_LINES 100

int main(void)
{
	int i, n, m;
	int lines[MAX_LINES];
	
	scanf("%d%d", &n, &m);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &lines[i]);
	}
	solve_lines(lines, n, m);

	return 0;
}

int shortest_line_index(int lines[], int n)
{
	int i, shortest = 0;
	
	for (i = 1; i < n; i++)
	{
		if (lines[i] < lines[shortest])
		{
			shortest = i;
		}
	}
	return shortest;
}

void solve_lines(int lines[], int n, int m)
{
	int i, shortest = 0;

	for (i = 0; i < m; i++)
	{
		shortest = shortest_line_index(lines, n);
		printf("%d\n", lines[shortest]);
		lines[shortest]++;
	}
	
}
