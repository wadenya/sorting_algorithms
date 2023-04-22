#include "sort.h"

/**
 * merge_sort - sorts an array of integers in ascending order using
 * the Merge sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */
void merge_sort(int *array, size_t size)
{
	int mid = 0;
	int *temp = malloc(sizeof(int) * size);
	int i = 0, j = 0, k = 0;

	if (!array || size < 2)
		return;

	mid = size / 2;
	merge_sort(array, mid);
	printf("Merging...\n");
	printf("[left]: ");
	for (i = 0; i < mid; i++)
		printf("%d ", array[i]);
	printf("\n[right]: ");
	for (i = mid; i < (int)size; i++)
		printf("%d ", array[i]);
	printf("\n");
	merge_sort(array + mid, size - mid);

	for (i = 0; i < mid; i++)
		temp[i] = array[i];

	i = mid;
	j = 0;
	k = 0;

	while (i < (int)size && j < mid)
	{
		if (array[i] < temp[j])
			array[k++] = array[i++];
		else
			array[k++] = temp[j++];
	}
	while (j < mid)
		array[k++] = temp[j++];
	printf("[Done]: ");
	for (i = 0; i < (int)size; i++)
		printf("%d ", array[i]);
	printf("\n");
	free(temp);
}
