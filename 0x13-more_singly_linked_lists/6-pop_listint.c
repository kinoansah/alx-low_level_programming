#include "lists.h"

/**
 * pop_listint - deletes the head node of a listint_t linked list
 * @head: pointer to pointer to the head of the list
 *
 * Return: the head node's data (n), or 0 if the list is empty
 */
int pop_listint(listint_t **head)
{
	int data = 0;

	if (*head != NULL)
	{
		listint_t *temp = *head;

		data = temp->n;
		*head = temp->next;
		free(temp);
	}

	return (data);
}
