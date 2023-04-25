#include "deck.h"

/**
 * card_cmp - Compare two cards
 * @c1: First card
 * @c2: Second card
 * Return: 1 if c1 > c2, 0 otherwise
 */
int card_cmp(const card_t *c1, const card_t *c2)
{
	int c1_val, c2_val, ret = 0;

	if (c1->kind > c2->kind)
		ret = 1;
	else if (c1->kind == c2->kind)
	{
		c1_val = atoi(c1->value);
		if (c1_val == 0)
			c1_val = get_value(c1->value[0]);
		c2_val = atoi(c2->value);
		if (c2_val == 0)
			c2_val = get_value(c2->value[0]);
		printf("%d %d\n", c1_val, c2_val);
		if (c1_val > c2_val)
			ret = 1;
	}
	return (ret);
}

/**
 * swap_nodes - Swap two nodes
 *
 * @n1: First node
 * @n2: Second node
 */
void swap_nodes(deck_node_t *n1, deck_node_t *n2)
{
	card_t *tmp_card;
	deck_node_t *tmp_node;

	tmp_card = n1->card;
	n1->card = n2->card;
	n2->card = tmp_card;

	tmp_node = n1->prev;
	n1->prev = n2->prev;
	n2->prev = tmp_node;

	tmp_node = n1->next;
	n1->next = n2->next;
	n2->next = tmp_node;
}


/**
 * sort_deck - Sort a deck of cards
 *
 * @deck: Deck to sort
 */
void sort_deck(deck_node_t **deck)
{
	int swapped;
	deck_node_t *curr;

	if (!deck || !*deck || !(*deck)->next)
		return;

	do {
		swapped = 0;
		curr = *deck;
		while (curr->next)
		{
			if (card_cmp(curr->card, curr->next->card) > 0)
			{
				swap_nodes(curr, curr->next);
				if (curr->prev == NULL)
					*deck = curr;
				swapped = 1;
			}
			curr = curr->next;
		}
	} while (swapped);
}
