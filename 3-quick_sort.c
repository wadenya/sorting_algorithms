#include "sort.h"

/**
<<<<<<< HEAD
* prtn_schm - partition scheme for quicksort
* @array: Array to sort
* @low: lowest index of array
* @high: highest index of array
* Return: index of a pivot
*/
int prtn_schm(int *array, int low, int high)
{
	int y, s, g, i;
	static int size, c;

	if (c == 0)
		size = high + 1, c++;
	y = array[high];
	s = low;
	for (g = low; g < high; g++)
	{
		if (array[g] <= y)
=======
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
>>>>>>> d0a44b4ee62e5950c8e531b7783b037b2491ccb0
		{
			if (s != g)
			{
<<<<<<< HEAD
				i = array[s];
				array[s] = array[g];
				array[g] = i;
				print_array(array, size);
=======
				i++;
				if (i != j)
				{
					tmp = array[i];
					array[i] = array[j];
					array[j] = tmp;
					print_array(array, size);
				}
>>>>>>> d0a44b4ee62e5950c8e531b7783b037b2491ccb0
			}
			s++;
		}
<<<<<<< HEAD
=======
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
>>>>>>> d0a44b4ee62e5950c8e531b7783b037b2491ccb0
	}
	if (s != high)
	{
		i = array[s];
		array[s] = array[high];
		array[high] = i;
		print_array(array, size);
	}

	return (s);
}

/**
* quick_rec_sort - Quicksort recurssive function
* @array: array to sort
* @low: lowest index
* @high: highest index
*/
void quick_rec_sort(int *array, int low, int high)
{
	int y;

	if (low < high)
	{
		y = prtn_schm(array, low, high);
		quick_rec_sort(array, low, y - 1);
		quick_rec_sort(array, low + 1, high);
	}
}


/**
* quick_sort - sorts array using quicksort algorithm
* @array: Array to sort
* @size: Size of array to sort
*/
void quick_sort(int *array, size_t size)
{
	if (array == NULL)
		return;
	quick_rec_sort(array, 0, size - 1);
}
