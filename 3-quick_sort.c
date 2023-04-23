#include "sort.h"

/**
 * quick_sort - implements the quick sort algorithm
 * @array: the array to sort
 * @size: size of the array
 * Return: void
*/

void quick_sort(int *array, size_t size)
{
	int tmp, piv, idx = 0, i_tmp;
	size_t i = 0, j;

	if (!array)
		return;

	while (1)
	{
		if (i == size - idx - 1)
			break;
		piv = array[size - idx - 1];
		i_tmp = i;
		for (j = i; j < size - idx; j++)
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
		if (piv == array[j - 1])
		{
			idx++;
			i = i_tmp;
		}
		else if (i - i_tmp > 2)
		{
			idx = size - i + 1;
			i = i_tmp;
		}
	}
}
