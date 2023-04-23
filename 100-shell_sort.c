#include "sort.h"

/**
 * shell_sort - implements the shell sort algorithm
 * @array: the array to sort
 * @size: size of the array
 * Return: void
*/

void shell_sort(int *array, size_t size)
{
	size_t i, j, idx, n = 1;
	int tmp, min;

	if (!array)
		return;

	while (n < size / 3 + 1)
		n = n * 3 + 1;

	while (n > 0)
	{
		for (i = 0; i < n; i++)
		{
			j = i;
			while (j < size)
			{
				idx = j;
				min = array[j];
				while (idx < size)
				{
					if (array[idx] < min)
					{
						min = array[idx];
						tmp = array[j];
						array[j] = min;
						array[idx] = tmp;
					}
					idx += n;
				}
				j += n;
			}
		}
		n = (n - 1) / 3;
		print_array(array, size);
	}
}
