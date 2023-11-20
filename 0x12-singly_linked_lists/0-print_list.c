#include <stdio.h>
#include "lists.h"
/**
 * print_list - Prints all the elements of a list_t list.
 * @h: A pointer to the head of the linked list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_list(const list_t *h)
{
    size_t count = 0;

   for (i = 0; h; i++)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
	return (count);
}
