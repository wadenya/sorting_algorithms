#include "sort.h"

int get_maxv(int *array, int size);
void radix_cnting_sort(int *array, size_t size, int sigd, int *buff);
void radix_sort(int *array, size_t size);

/**
 * get_maxv - Get the max value in an array of ints.
 * @array: An array of integers.
 * @size: The size of the array.
 * Return: The maximum integer in the array.
 */
int get_maxv(int *array, int size)
{
	int max = 0;

	for (int i = 0; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	return (max);
}

/**
 * radix_cnting_sort - Sort the significant digits of an array of integers
 * in ascending order using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 * @sigd: significant digit to sort on.
 * @buff: A buffer to store the sorted array.
 */
void radix_cnting_sort(int *array, size_t size, int sigd, int *buff)
{
	int count[10] = {0};
	size_t i;

	for (i = 0; i < size; i++)
		count[(array[i] / sigd) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; (int)i >= 0; i--)
	{
		buff[count[(array[i] / sigd) % 10] - 1] = array[i];
		count[(array[i] / sigd) % 10]--;
	}

	for (i = 0; i < size; i++)
		array[i] = buff[i];
}

/**
 * radix_sort - Sort an array of integers in ascending
 * order using the radix sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 * Description: Implements the LSD radix sort algorithm. Prints
 * the array after each significant digit increase.
 */
void radix_sort(int *array, size_t size)
{
	int max, sigd, *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	max = get_maxv(array, size);
	for (sigd = 1; max / sigd > 0; sigd *= 10)
	{
		radix_cnting_sort(array, size, sigd, buff);
		print_array(array, size);
	}

	free(buff);
}
