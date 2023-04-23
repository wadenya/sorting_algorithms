#include "sort.h"

/**
 * insertion_sort_list - implements the insertion sort algorithm
 * @list: the list to sort
 * Return: void
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *head, *next, *prev, *tmp_head;
	int swapped;

	if (!list)
		return;

	while (head && head->next)
	{
		swapped = 0;
		tmp_head = head;
		next = head->next;
		while (tmp_head && tmp_head->n > next->n)
		{
			prev = tmp_head->prev;
			if (next && tmp_head->n > next->n)
			{
				tmp_head->prev = next;
				tmp_head->next = next->next;
				if (tmp_head->next)
					tmp_head->next->prev = tmp_head;
				next->next = tmp_head;
				next->prev = prev;
				if (prev)
					prev->next = next;
				else
					*list = next;
				print_list(*list);
			}
			tmp_head = prev;
			swapped = 1;
		}
		if (!swapped)
			head = head->next;
	}
}
