#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list using Insertion Sort.
 * @list: Double pointer to the head of the doubly linked list.
 *
 * Description: This function sorts the doubly linked list in ascending order.
 *              It moves each node to its correct position in the sorted part.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current_node, *key_node, *previous_node;

	/* Return if the list is empty or contains only one element */
	if (!list || !*list || !(*list)->next)
		return;

	current_node = (*list)->next;
	while (current_node)
	{
		key_node = current_node;
		previous_node = current_node->prev;

		/* Move the key node backwards to its correct position */
		while (previous_node && previous_node->n > key_node->n)
		{
			/* Adjust the links to insert key_node before previous_node */
			previous_node->next = key_node->next;
			if (key_node->next)
				key_node->next->prev = previous_node;

			key_node->prev = previous_node->prev;
			if (previous_node->prev)
				previous_node->prev->next = key_node;

			key_node->next = previous_node;
			previous_node->prev = key_node;

			/* Update the list's head if the key_node is the new head */
			if (!key_node->prev)
				*list = key_node;

			print_list(*list);
			previous_node = key_node->prev;
		}
		current_node = current_node->next;
	}
}

