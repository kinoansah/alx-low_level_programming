#include "lists.h"

/**
 * free_listint_safe - Frees a listint_t linked list safely
 * @head: Pointer to a pointer to the head node of the list
 *
 * Return: Number of nodes in the list that was freed
 */
size_t free_listint_safe(listint_t **head)
{
	listint_t *slow = *head, *fast = *head, *temp;
	size_t count = 0;

	while (slow && fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
		{
			while (*head != slow)
			{
				temp = *head;
				*head = (*head)->next;
				free(temp);
				count++;
			}
			temp = slow->next;
			while (temp != slow)
			{
				listint_t *next = temp->next;

				free(temp);
				temp = next;
				count++;
			}

			free(slow);
			count++;
			*head = NULL;
			break;
		}
	}
	while (*head)
	{
		temp = *head;
		*head = (*head)->next;
		free(temp);
		count++;
	}
	return (count);
}

