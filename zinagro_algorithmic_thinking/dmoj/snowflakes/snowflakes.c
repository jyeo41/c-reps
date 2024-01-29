#include <stdio.h>
#include <stdlib.h>

#define SIZE 100000

typedef struct snowflake_node
{
	int snowflake[6];
	struct snowflake_node *next;
} snowflake_node;

void identify_identical(snowflake_node *snowflakes[]);
int are_identical(int snow1[], int snow2[]);
int identical_right(int snow1[], int snow2[], int start);
int identical_left(int snow1[], int snow2[], int start);
int snowflake_hashcode(int snowflake[]);


int main(void)
{
	static snowflake_node *snowflakes[SIZE] = {NULL}; // array of pointers where each element is a linked list of snowflakes
	snowflake_node *snow;
	int n, i, j, snowflake_code;

	scanf("%d", &n); // where n is the total number of snowflakes 

	for (i = 0; i < n; i++)
	{
		snow = malloc(sizeof(snowflake_node));
		if (snow == NULL)
		{
			fprintf(stderr, "malloc error\n");
			exit(1);
		}
		for (j = 0; j < 6; j++)
		{
			scanf("%d", &snow->snowflake[j]);
			//printf("snowflake created\n");
		}
		snowflake_code = snowflake_hashcode(snow->snowflake);
		snow->next = snowflakes[snowflake_code]; // inserting new snowflake to beginning of the list
		snowflakes[snowflake_code] = snow; // snowflakes[snowflake_code] IS the head of the list, so adjust pointer to new snowflake
	}

	identify_identical(snowflakes);

	return 0;
}


void identify_identical(snowflake_node *snowflakes[])
{
	snowflake_node *node1, *node2;
	int i;
	for (i = 0; i < SIZE; i++)
	{
		node1 = snowflakes[i];
		while (node1 != NULL)
		{
			node2 = node1->next;

			while(node2 != NULL)
			{
				if (are_identical(node1->snowflake, node2->snowflake))
				{
					printf("Twin snowflakes found.\n");
					return;
				}
				node2 = node2 -> next;
			}
			node1 = node1 -> next;
		}
	}
	printf("No two snowflakes are alike.\n");
}

int are_identical(int snow1[], int snow2[])
{
	int start;
	for (start = 0; start < 6; start++)
	{
		if (identical_right(snow1, snow2, start))
		{
			return 1;
		}
		if (identical_left(snow1, snow2, start))
		{
			return 1;
		}

	}
	return 0;
}

int identical_right(int snow1[], int snow2[], int start)
{
	int offset, snow2_index;

	for (offset = 0; offset < 6; offset++)
	{
		snow2_index = start + offset;
		if (snow2_index >= 6)
		{
			snow2_index -= 6;
		}
		if (snow1[offset] != snow2[snow2_index])
		{
			return 0;
		}
	}
	return 1;
}

int identical_left(int snow1[], int snow2[], int start)
{
	int offset, snow2_index;

	for (offset = 0; offset < 6; offset++)
	{
		snow2_index = start - offset;
		if (snow2_index < 0)
		{
			snow2_index += 6;
		}
		if (snow1[offset] != snow2[snow2_index])
		{
			return 0;
		}
	}
	return 1;
}

int snowflake_hashcode(int snowflake[])
{
	int i, code = 0;
	for (i = 0; i < 6; i++)
	{
		code += snowflake[i];
	}
	code = code % SIZE;
	return code;
}

