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
 * bitonic_merge_seq - Sort a bitonic sqnce inside an array of int.
 * @array: Array of integers.
 * @size: size of the array.
 * @strt: starting index of the sequence in array to sort.
 * @seq: size of the sequence to sort.
 * @flw: direction to sort in.
 */
void bitonic_merge_seq(int *array, size_t size, size_t strt,
		size_t seq, char flw)
{
	size_t y, jmp = seq / 2;

	if (seq > 1)
	{
		for (y = strt; y < strt + jmp; y++)
		{
			if ((flw == UP && array[y] > array[y + jmp]) ||
			    (flw == DOWN && array[y] < array[y + jmp]))
				swap_int(array + y, array + y + jmp);
		}
		bitonic_merge_seq(array, size, strt, jmp, flw);
		bitonic_merge_seq(array, size, strt + jmp, jmp, flw);
	}
}

/**
 * bitonic_convt_seq - Convert an array of ints into a bitonic seq.
 * @array: An array of integers.
 * @size: The size of the array.
 * @strt: starting index of a block of the building bitonic seq.
 * @seq: size of a block of the building bitonic sequence.
 * @flw: direction to sort the bitonic sequence block in.
 */
void bitonic_convt_seq(int *array, size_t size, size_t strt,
		size_t seq, char flw)
{
	size_t cut = seq / 2;
	char *str = (flw == UP) ? "UP" : "DOWN";

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + strt, seq);

		bitonic_convt_seq(array, size, strt, cut, UP);
		bitonic_convt_seq(array, size, strt + cut, cut, DOWN);
		bitonic_merge_seq(array, size, strt, seq, flw);

		printf("Result [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + strt, seq);
	}
}

/**
 * bitonic_sort - Sort an array of integers in ascending
 * order using the bitonic sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_convt_seq(array, size, 0, size, UP);
}
