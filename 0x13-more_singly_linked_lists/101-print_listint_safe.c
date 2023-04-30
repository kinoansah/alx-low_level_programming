#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * print_listint_safe - Prints a listint_t linked list safely
 * @head: Pointer to the head node of the list
 *
 * Return: Number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *node = head, *node2 = head;
	size_t count = 0;

	while (node)
	{
		printf("[%p] %d\n", (void *)node, node->n);
		node = node->next;
		count++;

		if (node >= node2)
		{
			printf("-> [%p] %d\n", (void *)node, node->n);
			break;
		}

		node2 = node2->next->next;
	}

	return (count);
}
