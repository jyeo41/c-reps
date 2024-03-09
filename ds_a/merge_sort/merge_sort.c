#include <stdio.h>
#include <stdlib.h>

void merge_sort(int array[], int length);
void merge(int array[], int low, int mid, int high);

int main (void)
{
	int test_array[] = {0, 5, 4, 1, 3, 9, 6, 8, 7, 2, -30, -50, 100, 90052};
	const int length = sizeof(test_array) / sizeof(test_array[0]);

	for (int i = 0; i < length; i++)
	{
		printf("%d ", test_array[i]);
	}
	printf("\n");

	merge_sort(test_array, length);
	for (int i = 0; i < length; i++)
	{
		printf("%d ", test_array[i]);
	}
	printf("\n");
}

void merge_sort(int array[], int length)
{
	if (length < 2)
	{
		return;
	}
	// calculate appropriate indices for left and right subarrays
	int mid = length / 2;

	merge_sort(array, mid);
	merge_sort(array + mid, length - mid);
	merge(array, 0, mid, length);
}

void merge(int array[], int low, int mid, int high)
{
	// create the temp arrays 
	int length_left = (mid - low);
	int length_right = (high - mid);
	int array_left[length_left];
	int array_right[length_right];
	int i, j, k;

	for (i = 0; i < length_left; i++)
	{
		array_left[i] = array[low + i];
	}
	for (i = 0; i < length_right; i++)
	{
		array_right[i] = array[mid + i];	
	}


	// perform 2 way merge on the subarrays
	i = j = k = 0;

	while (i < length_left && j < length_right)
	{
		if (array_left[i] < array_right[j])
		{
			array[k++] = array_left[i++];
		}
		else
		{
			array[k++] = array_right[j++];
		}
	}

	// once the end of one list has been reached
	// finish copying over the remaining list
	for ( ; i < length_left; i++)
	{
		array[k++] = array_left[i];
	}
	for ( ; j < length_right; j++)
	{
		array[k++] = array_right[j];
	}
}

