#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * free_listint2 - frees a listint_t list and sets the head to NULL
 * @head: pointer to a pointer to the head of the list
 */
void free_listint2(listint_t **head)
{
	if (head == NULL)
	{
		return;
	}

	while (*head != NULL)
	{
		listint_t *next_node = (*head)->next;

		free(*head);

		*head = next_node;
	}

	*head = NULL;
}
