#include "sort.h"

void heap_sort(int *array, size_t size);
void sift_down(int *array, int n, int i);

/**
 * heap_sort - Sort an array of integers in ascending
 * order using the heap sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: void
 */
void heap_sort(int *array, size_t size)
{
	int i, temp;
	size_t j;

	/* Build max heap */
	for (i = size / 2 - 1; i >= 0; i--)
	{
		sift_down(array, size, i);
	}
	/* Heap sort */
	for (j = size - 1; j > 0; j--)
	{
		temp = array[0];
		array[0] = array[j];
		array[j] = temp;
		print_array(array, size);
		sift_down(array, j, 0);
	}
}

/**
 * sift_down - takes an array of integers
 * @array: pointer to an array of integers.
 * @n: size of the array
 * @i: index of the node to sift down
 * Return: void
 */
void sift_down(int *array, int n, int i)
{
	int max, temp;

	max = i;
	/* Left child */
	if (2 * i + 1 < n && array[2 * i + 1] > array[max])
		max = 2 * i + 1;
	/* Right child */
	if (2 * i + 2 < n && array[2 * i + 2] > array[max])
		max = 2 * i + 2;
	/* If root is not max */
	if (max != i)
	{
		temp = array[i];
		array[i] = array[max];
		array[max] = temp;
		print_array(array, n);
		sift_down(array, n, max);
	}
}
