#include <stdio.h>
#include <stdlib.h>

void quick_sort(int array[], int start, int end);
int partition(int array[], int start, int end);
void swap(int array[], int i, int j);
void swap_pointers(int *a, int *b);

int main()
{
	int array[] = {7, 2, 1, 6, 8, 5, 3, 4};
	int length = sizeof(array)/sizeof(array[0]);
	int i;

	quick_sort(array, 0, length - 1);

	for (i = 0; i < 8; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}

void quick_sort(int array[], int start, int end)
{
	int p_index;
	
	if (start >= end)
	{
		return;
	}

	p_index = partition(array, start, end);
	quick_sort(array, start, p_index - 1);
	quick_sort(array, p_index + 1, end);
	
}

int partition(int array[], int start, int end)
{
	int pivot, p_index;
	pivot = array[end];
	p_index = start;

	int i;
	
	for (i = start; i < end; i++)
	{
		if (array[i] <= pivot)
		{
			swap_pointers(&array[i], &array[p_index]);
			p_index++;
		}
	}

	swap(array, p_index, end);

	return p_index;
}

void swap(int array[], int i, int j)
{
	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

void swap_pointers(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
