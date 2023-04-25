#include "deck.h"

/**
 * compare_cards - compare two cards based on their value and suit
 * @a: card 1
 * @b: card 2
 *
 * Return: 0 if equal, 1 if card 1 is greater, -1 if card 2 is greater
 */
int compare_cards(const void *a, const void *b)
{
	int cmp;
	card_t *card1, *card2;

	card1 = (card_t *)a;
	card2 = (card_t *)b;

	cmp = card1->kind - card2->kind;
	if (cmp == 0)
	{
		cmp = strcmp(card1->value, card2->value);
		return (cmp);
	}
	return (cmp);
}

/**
 * sort_deck - sorts a deck of cards
 * @deck: double pointer to a doubly linked list
 */
void sort_deck(deck_node_t **deck)
{
	deck_node_t *curr;
	card_t *cards;
	int i;

	if (!deck || !(*deck))
		return;

	curr = *deck;
	cards = malloc(sizeof(card_t) * 52);
	if (!cards)
		return;

	i = 0;
	while (curr)
	{
		cards[i] = *(curr->card);
		curr = curr->next;
		i++;
	}
	qsort(cards, 52, sizeof(card_t), compare_cards);

	curr = *deck;
	i = 0;
	while (curr)
	{
		*(curr->card) = cards[i];
		curr = curr->next;
		i++;
	}
	free(cards);
}
