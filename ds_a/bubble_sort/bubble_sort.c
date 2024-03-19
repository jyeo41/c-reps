#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int array[], int length);
void swap(int *a, int *b);

int main()
{
	int array[] = {5, 8, 1, 4, 2, 3};
	int i, length;

	length = sizeof(array)/sizeof(array[0]);
	bubble_sort(array, length);
	for (i = 0; i < length; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");

}

void bubble_sort(int array[], int length)
{
	int i, j, flag;

	// loop runs till length - 1 because otherwise
	// the inner loop comparison check will go out of bounds
	for(i = 0; i < length - 1; i++)
	{
		// flag set to 0 to indicate no swap has been done in the current iteration
		flag = 0;

		// loop runs till length - i - 1
		// optimization so subsequent iterations doesn't check the already sorted sub array
		for (j = 0; j < length - i - 1; j++)
		{

			// bubble logic to bubble out the greatest element to the end of the array
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				flag = 1;
			}
		}

		// if no swaps happened means the list is now sorted
		// no need to run anymore iterations
		if (flag == 0)
		{ 
			break; 
		}
	}
}

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
