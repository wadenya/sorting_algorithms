#include "sort.h"

/**
 * get_maxv - Get the max value in an array of ints.
 * @array: array of integers.
 * @size: size of the array.
 * Return: The max integer in array.
 */
int get_maxv(int *array, int size)
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
 * counting_sort - Sort an array of integers in ascending order
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: Print array
 */
void counting_sort(int *array, size_t size)
{
	int *cnt, *srt, max, y;

	if (array == NULL || size < 2)
		return;

	srt = malloc(sizeof(int) * size);
	if (srt == NULL)
		return;
	max = get_maxv(array, size);
	cnt = malloc(sizeof(int) * (max + 1));
	if (cnt == NULL)
	{
		free(srt);
		return;
	}

	for (y = 0; y < (max + 1); y++)
		cnt[y] = 0;
	for (y = 0; y < (int)size; y++)
		cnt[array[y]] += 1;
	for (y = 0; y < (max + 1); y++)
		cnt[y] += cnt[y - 1];
	print_array(cnt, max + 1);

	for (y = 0; y < (int)size; y++)
	{
		srt[cnt[array[y]] - 1] = array[y];
		cnt[array[y]] -= 1;
	}

	for (y = 0; y < (int)size; y++)
		array[y] = srt[y];

	free(srt);
	free(cnt);
}
