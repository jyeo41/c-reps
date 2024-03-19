#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int array[], int length);

int main()
{
	int array[] = {4, 7, 1, 5, 2, 3};
	int length = sizeof(array)/sizeof(array[0]);
	int i;

	insertion_sort(array, length);

	for (i = 0; i < 6; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
	
}

void insertion_sort(int array[], int length)
{
	int i, j, key;
	for (i = 1; i < length; i++)
	{
		key = array[i];
		j = i;

		while (j > 0 && array[j - 1] > key)
		{
			array[j] = array[j - 1];
			j--;
		}
		array[j] = key;
	}
}
