#include "sort.h"

/**
 * swap_int - Swap two integers in an array.
 * @a: first int to swap.
 * @b: second int to swap.
 */
void swap_int(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * hoare_schm - Order a subset of an array of ints
 * according to the hoare partition scheme.
 * @array: The array of ints.
 * @size: The size of the array.
 * @left: starting index of the subset to order.
 * @right: ending index of the subset to order.
 * Return: The final partition index.
 */
int hoare_schm(int *array, size_t size, int left, int right)
{
	int pvot, abve, blow;

	pvot = array[right];
	for (abve = left - 1, blow = right + 1; abve < blow;)
	{
		do {
			abve++;
		} while (array[abve] < pvot);
		do {
			blow--;
		} while (array[blow] > pvot);

		if (abve < blow)
		{
			swap_int(array + abve, array + blow);
			print_array(array, size);
		}
	}

	return (abve);
}

/**
* hoare_qcksort_rec - Implement the quicksort algorithm through recursion.
 * @array: array of integers to sort.
 * @size: size of the array.
 * @left: starting index of the array partition to order.
 * @right: ending index of the array partition to order.
 */
void hoare_qcksort_rec(int *array, size_t size, int left, int right)
{
	int prt;

	if (right - left > 0)
	{
		prt = hoare_schm(array, size, left, right);
		hoare_qcksort_rec(array, size, left, prt - 1);
		hoare_qcksort_rec(array, size, prt, right);
	}
}

/**
 * quick_sort_hoare - Sort an array of integers in ascending
 * order using the quicksort algorithm.
 * @array: An array of ints.
 * @size: size of the array.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_qcksort_rec(array, size, 0, size - 1);
}
