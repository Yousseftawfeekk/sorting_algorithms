#include "sort.h"

/**
 * node_swap - Swap two nodes in a listint_t doubly-linked list.
 * @head: the head of the doubly-linked list.
 * @node_1: the first node
 * @node_2: The second node
 */

void node_swap(listint_t **head, listint_t **node_1, listint_t *node_2)
{
	(*node_1)->next = node_2->next;

	if (node_2->next != NULL)
		node_2->next->prev = *node_1;

	node_2->prev = (*node_1)->prev;
	node_2->next = *node_1;

	if ((*node_1)->prev != NULL)
		(*node_1)->prev->next = node_2;
	else
		*head = node_2;
	(*node_1)->prev = node_2;
	*node_1 = node_2->prev;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *
 * @list: pointer to the head of a doubly-linked list
 *
 * Description: Print the list after each swap
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *i, *ins, *replace;

	if (!list || !*list || !(*list)->next)
	{
		return;
	}

	for (i = (*list)->next; i != NULL; i = replace)
	{
		replace = i->next;
		ins = i->prev;
	
		while (ins != NULL && i->n < ins->n)
		{
			node_swap(list, &ins, i);
			print_list((listint_t *)*list);
		}
	}
}
