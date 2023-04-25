#include "sort.h"

/**
* prtn_schm - partition scheme for quicksort
* @array: Array to sort
* @low: lowest index of array
* @high: highest index of array
* Return: index of pivot
*/
int prtn_schm(int *array, int low, int high)
{
	int y, s, g, m;
	static int size, c;

	if (c == 0)
		size = high + 1, c++;
	y = array[high];
	s = low;
	for (g = low; g < high; g++)
	{
		if (array[g] <= y)
		{
			if (s != g)
			{
				m = array[s];
				array[s] = array[g];
				array[g] = m;
				print_array(array, size);
			}
			s++;
		}
	}
	if (s != high)
	{
		m = array[s];
		array[s] = array[high];
		array[high] = m;
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
		quick_rec_sort(array, y + 1, high);
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
