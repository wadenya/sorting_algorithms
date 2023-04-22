#include "sort.h"

/**
 * quick_sort_hoare - Sort an array of integers in ascending
 * order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 * Description: prints array after two swaps
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	int pivot;
	int i = -1, j = size - 1;

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (i >= j)
			break;

		int tmp = array[i];

		array[i] = array[j];
		array[j] = tmp;

		printf("%d, ", array[i]);
		for (int k = i + 1; k < size - 1; k++)
			printf("%d, ", array[k]);
		printf("%d\n", array[size - 1]);
	}

	int tmp = array[i];

	array[i] = array[size - 1];
	array[size - 1] = tmp;

	quick_sort_hoare(array, i);
	quick_sort_hoare(array + i + 1, size - i - 1);

}
