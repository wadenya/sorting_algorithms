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
	size_t end, start, i = 0, j, stack[1024], top = 0;

	stack[top++] = 0;
	stack[top++] = size;

	while (top > 0)
	{
		end = stack[--top];
		start = stack[--top];
		if (end - start <= 1)
			continue;
		piv = array[end - 1];
		i = start - 1;
		for (j = start; j < end - 1; j++)
		{
			if (array[j] <= piv)
			{
				i++;
				if (i != j)
				{
					tmp = array[i];
					array[i] = array[j];
					array[j] = tmp;
					print_array(array, size);
				}
			}
		}
		if (i != end - 2)
		{
			tmp = array[i + 1];
			array[i + 1] = array[end - 1];
			array[end - 1] = tmp;
			print_array(array, size);
		}
		stack[top++] = start;
		stack[top++] = i + 1;
		stack[top++] = i + 2;
		stack[top++] = end;
	}
}
