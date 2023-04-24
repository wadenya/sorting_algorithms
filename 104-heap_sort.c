#include "sort.h"

/**
 * swap_int - Swap two integers in an array.
 * @a: The first int to swap.
 * @b: The second int to swap.
 */
void swap_int(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * complt_heap - Turn a binary tree into a complete binary heap.
 * @array: Array of int rep a binary tree.
 * @size: Size of the array or tree.
 * @base: Index of the base row of tree.
 * @root: Root node of the binary tree.
 */
void complt_heap(int *array, size_t size, size_t base, size_t root)
{
	size_t left, right, big;

	left = 2 * root + 1;
	right = 2 * root + 2;
	big = root;

	if (left < base && array[left] > array[big])
		big = left;
	if (right < base && array[right] > array[big])
		big = right;
	if (big != root)
	{
		swap_int(array + root, array + big);
		print_array(array, size);
		complt_heap(array, size, base, big);
	}
}

/**
 * heap_sort - Sort an array of integers in ascending
 * order using the heap sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 */
void heap_sort(int *array, size_t size)
{
	int y;

	if (array == NULL || size < 2)
		return;

	for (y = (size / 2) - 1; y >= 0; y--)
		complt_heap(array, size, size, y);

	for (y = size - 1; y > 0; y--)
	{
		swap_int(array, array + y);
		print_array(array, size);
		complt_heap(array, size, y, 0);
	}
}
