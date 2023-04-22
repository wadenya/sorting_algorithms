#include "sort.h"

/**
 * quick_sort - implements the quick sort algorithm
 * @array: the array to sort
 * @size: size of the array
 * Return: void
*/

void quick_sort(int *array, size_t size)
{
	int tmp, piv;
	size_t i = 0, j;

	if (size > 1)
	{
		piv = array[size - 1];
		for (j = i; j < size; j++)
		{
			if (array[j] <= piv)
			{
				if (j != i)
				{
					tmp = array[i];
					array[i] = array[j];
					array[j] = tmp;
					print_array(array, size);
				}
				i++;
			}
		}
		quick_sort(array, i - 1);
		quick_sort(array + i, size - i);
	}
}
