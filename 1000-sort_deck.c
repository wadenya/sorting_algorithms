#include "deck.h"

/**
 * get_value - gets the real value of a card
 * @c: character passed
 * Return: integer value representing the value of the card
*/
int get_value(char c)
{
	int val;

	switch (c)
	{
	case 65:
		val = 1;
		break;
	case 74:
		val = 11;
		break;
	case 81:
		val = 12;
		break;
	default:
		val = 13;
		break;
	}
	return (val);
}

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
 * @deck: the deck
 */
void swap_nodes(deck_node_t *n1, deck_node_t *n2, deck_node_t **deck)
{
	deck_node_t *tmp_node;

	tmp_node = n1->prev;
	if (tmp_node)
		tmp_node->next = n2;
	else
		*deck = n2;
	n1->prev = n2->prev;
	if (n2->prev)
		n2->prev->next = n1;
	else
		*deck = n1;
	n2->prev = tmp_node;

	tmp_node = n1->next;
	if (tmp_node)
		tmp_node->prev = n2;
	n1->next = n2->next;
	if (n2->next)
		n2->next->prev = n1;
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
		while (curr && curr->next)
		{
			if (card_cmp(curr->card, curr->next->card))
			{
				swap_nodes(curr, curr->next, deck);
				swapped = 1;
			}
			curr = curr->next;
		}
	} while (swapped);
}
