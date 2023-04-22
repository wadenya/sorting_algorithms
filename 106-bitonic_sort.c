#include "sort.h"

/**
 * bitonic_sort - Sort an array of integers in ascending
 * order using the bitonic sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 * Description: Prints the array after each swap.
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return;
	size_t step, i;
	int up;

	for (step = 2; step <= size; step *= 2)
	{
		for (up = step <= size; up > 0; up /= 2)
		{
			for (i = up; i < size; i += step)
			{
				if (array[i - up] > array[i])
				{
					int temp = array[i - up];

					array[i - up] = array[i];
					array[i] = temp;
					printf("Merging [%lu/%lu] (%s):\n", step, size, up ? "UP" : "DOWN");
					print_array(array, size);
				}
			}
		}
	}
}
