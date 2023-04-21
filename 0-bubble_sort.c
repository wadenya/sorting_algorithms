#include "sort.h"

/**
 * bubble_sort - implements the bubble sort algorithm
 * @array: the array to sort
 * @size: size of the array
 * Return: void
*/
void bubble_sort(int *array, size_t size)
{
	int swapped, tmp;
	size_t i;

	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		for (i = 1; i < size; i++)
		{
			if (array[i - 1] > array[i])
			{
				tmp = array[i - 1];
				array[i - 1] = array[i];
				array[i] = tmp;
				swapped = 1;
				print_array(array, size);
			}
		}
	}
}
