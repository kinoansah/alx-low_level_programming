#include "lists.h"

/**
 * free_listint - frees a listint_t linked list
 * @head: pointer to the head of the list
 */
void free_listint(listint_t *head)
{
	listint_t *current = head;

	while (current != NULL)
	{
		listint_t *temp = current;
		current = current->next;
		free(temp);
	}
}
