#include "sort.h"

/**
 * get_max_val - Get the max value in an array of ints.
 * @array: Array of integers.
 * @size: Size of the array.
 * Return: The max int
 */
int get_max_val(int *array, int size)
{
	int max, y;

	for (max = array[0], y = 1; y < size; y++)
	{
		if (array[y] > max)
			max = array[y];
	}

	return (max);
}

/**
 * radix_cnting - sorts sig digits of an array of integers in ascending
 * order using the cnting sort algorithm
 * @array: An array of integers.
 * @size: The size of the array.
 * @sigd: The significant digit to sort on.
 * @buff: A buffer to store the sorted array.
 */
void radix_cnting(int *array, size_t size, int sigd, int *buff)
{
	int cnt[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t y;

	for (y = 0; y < size; y++)
		cnt[(array[y] / sigd) % 10] += 1;

	for (y = 0; y < 10; y++)
		cnt[y] += cnt[y - 1];

	for (y = size - 1; (int)y >= 0; y--)
	{
		buff[cnt[(array[y] / sigd) % 10] - 1] = array[y];
		cnt[(array[y] / sigd) % 10] -= 1;
	}

	for (y = 0; y < size; y++)
		array[y] = buff[y];
}

/**
 * radix_sort - Sort an array of integers in ascending
 * order using the radix sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 */
void radix_sort(int *array, size_t size)
{
	int max, sigd, *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	max = get_max_val(array, size);
	for (sigd = 1; max / sigd > 0; sigd *= 10)
	{
		radix_cnting(array, size, sigd, buff);
		print_array(array, size);
	}

	free(buff);
}
