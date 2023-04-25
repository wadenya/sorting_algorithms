#include "sort.h"

/**
 * swap - swaps two list elements
 * @head: second element
 * @next: first element
 * @list: the entire list
 * Return: void
*/

void swap(listint_t *head, listint_t *next, listint_t **list)
{
	head->next = next->next;
	next->prev = head->prev;
	if (head->prev)
		head->prev->next = next;
	else
		*list = next;
	head->prev = next;
	if (next->next)
		next->next->prev = head;
	next->next = head;
	head->prev = next;
}

/**
 * cocktail_sort_list - implements the cocktail shaker sort algorithm
 * @list: the list to sort
 * Return: void
*/

void cocktail_sort_list(listint_t **list)
{
	listint_t *next, *prev, *head, *tail;
	int swapped;

	if (!list || !*list)
		return;

	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		head = *list;
		while (head && head->next)
		{
			next = head->next;
			if (head->n > next->n)
			{
				swap(head, next, list);
				swapped = 1;
				print_list(*list);
			}
			else
				head = next;
		}
		if (!swapped)
			break;
		swapped = 0;
		tail = head;
		while (tail && tail->prev)
		{
			prev = tail->prev;
			if (prev->n > tail->n)
			{
				swap(prev, tail, list);
				swapped = 1;
				print_list(*list);
			}
			else
				tail = prev;
		}
	}
}
