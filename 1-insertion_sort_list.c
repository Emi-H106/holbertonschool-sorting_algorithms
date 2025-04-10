#include "sort.h"

/**
 * insertion_sort_list - that sorts an array of integers in order using
 * @list: after each time you swap two elements
 * Return:
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		temp = current;
		while (temp->prev != NULL && temp->n < temp->prev->n)
		{
			listint_t *prev = temp->prev;
			listint_t *next = temp->next;

			if (prev->prev)
				prev->prev->next = temp;
			temp->prev = prev->prev;

			temp->next = prev;
			prev->prev = temp;
			prev->next = next;

			if (next)
				next->prev = prev;

			if (temp->prev == NULL)
				*list = temp;

			print_list(*list);
		}
		current = current->next;
	}
}
