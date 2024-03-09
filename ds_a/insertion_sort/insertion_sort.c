// Insertion sort implementation

#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int array[], int length);

int main()
{
	int array[] = {0, -1, 123, 56, 80, 45};
	insertion_sort(array, 6);
	for (int i = 0; i < 6; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");

}

void insertion_sort(int array[], int length)
{
	int i, j;
	int i_min;

	for (i = 0; i < length - 1; i++)
	{
		i_min = i;
		for (j = i + 1; j < length; j++)
		{
			if (array[j] < array[i_min])
			{
				i_min = j;
			}
		}
		int temp = array[i_min];
		array[i_min] = array[i];
		array[i] = temp;
	}
}
