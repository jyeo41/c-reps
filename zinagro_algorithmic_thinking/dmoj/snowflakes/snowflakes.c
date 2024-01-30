// Implementing the given code by Daniel Zingaro in his book Algorithmic Thinking
// making sure to understand the design and implementation and confirming the code 
// compiles and runs in gcc

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
	static snowflake_node *snowflakes[SIZE] = {NULL}; // hashtable, array of snowflake pointers where each bucket is a LL
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
	for (i = 0; i < SIZE; i++) // iterating through the hash table
	{
		node1 = snowflakes[i];
		while (node1 != NULL) // double while loop to check twin snowflake pairs in a given hashtable bucket
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
	for (start = 0; start < 6; start++) // iterates through snow2 to find the first matching arm of the snowflake
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

	for (offset = 0; offset < 6; offset++) // once initial matching arm is found with start, use offsets to compare if twin snowflakes
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
		snow2_index = start - offset; // start - offset ORDER MATTERS otherwise offset - start will give wrong comparison
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
	code = code % SIZE; // mod operation to put in correct buckets, otherwise it'll overflow for big snowflake arm integers
	return code;
}

