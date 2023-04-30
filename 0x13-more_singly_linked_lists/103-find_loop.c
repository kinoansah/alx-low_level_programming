#include "lists.h"

/**
 * find_listint_loop - Finds the node where a loop starts in a listint_t
 * linked list
 *
 * @head: Pointer to the head node of the list
 *
 * Return: Address of the node where the loop starts, or NULL if there
 * is no loop
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *slow = head, *fast = head;

	while (slow && fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)
		{
			slow = head;
			while (slow != fast)
			{
				slow = slow->next;
				fast = fast->next;
			}

			return (slow);
		}
	}

	return (NULL);
}

