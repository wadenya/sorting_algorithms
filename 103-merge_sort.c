#include "sort.h"


/**
* merg_split - Merges the splits from merge_sorty
* @array: Array split to merge
* @low: lowest index of split
* @mid: middle index of split
* @high: high index of split
* @temp: temp array for merging
*/

void merg_split(int *array, int low, int mid, int high, int *temp)
{
	int y, j, k, n, l = 0, r = 0;
	int left[4096], right[4096];

	printf("Merging...\n");
	y = low, j = mid + 1, k = l = 0;
	while (y <= mid && j <= high)
	{
		if (array[y] <= array[j])
			temp[k] = left[l] = array[y], k++, y++, l++;
		else
			temp[k] = right[r] = array[j], k++, j++, r++;
	}
	while (y <= mid)
		temp[k] = left[l] = array[y], k++, y++, l++;
	while (j <= high)
		temp[k] = right[r] = array[j], k++, j++, r++;
	printf("[left]: ");
	for (n = 0; n < l; n++)
		(n == 0) ? printf("%d", left[n]) : printf(", %d", left[n]);
	printf("\n[right]: ");
	for (n = 0; n < r; n++)
		(n == 0) ? printf("%d", right[n]) : printf(", %d", right[n]);
	printf("\n[Done]: ");
	for (y = low; y <= high; y++)
	{
		array[y] = temp[y - low], printf("%d", array[y]);
		if (y != high)
			printf(", ");
		else
			printf("\n");
	}
}

/**
* merg_rec - recsive fnct utilizing merge sort algorithm
* @array: Array
* @low: Lowest index of split
* @high: highest index of split
* @temp: temp array for merging
*/

void merg_rec(int *array, int low, int high, int *temp)
{
	int mid;

	if (low < high)
	{
		mid = ((high + low - 1) / 2);
		merg_rec(array, low, mid, temp);
		merg_rec(array, mid + 1, high, temp);
		merg_split(array, low, mid, high, temp);
	}
}

/**
* merge_sort - Sorts array with merge sort algo
* @array: array to sort
* @size: Size of array to sort
*/

void merge_sort(int *array, size_t size)
{
	int *temp;

	if (array == NULL || size < 2)
		return;
	temp = malloc(sizeof(int) * (size + 1));
	if (temp == NULL)
		return;
	merg_rec(array, 0, size - 1, temp);
	free(temp);
}
