#include "sort.h"

/**
 * selection_sort - implements the selection sort algorithm
 * @array: the array to sort
 * @size: size of the array
 * Return: void
*/

void selection_sort(int *array, size_t size)
{
	int tmp, min;
	size_t i, j, idx;

	for (i = 0; i < size; i++)
	{
		min = array[i];
		for (j = i; j < size; j++)
		{
			if (array[j] < min)
			{
				min = array[j];
				idx = j;
			}
		}
		if (min != array[i])
		{
			tmp = array[i];
			array[idx] = tmp;
			array[i] = min;
			print_array(array, size);
		}
	}
}
