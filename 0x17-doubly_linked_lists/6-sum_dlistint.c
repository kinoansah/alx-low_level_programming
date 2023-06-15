#include "lists.h"

/**
 * sum_dlistint - Calculates the sum of all the data values in a linked list.
 * @head: Pointer to the head node of the list.
 * Return: Sum of the data values, or 0 if the list is empty.
 */
int sum_dlistint(dlistint_t *head)
{
	int sum = 0;
	dlistint_t *current = head;

	while (current != NULL)
	{
		sum += current->n;
		current = current->next;
	}

	return (sum);
}
