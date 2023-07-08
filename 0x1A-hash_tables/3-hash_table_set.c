#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"
/**
 * replace_value - Replaces the value of a key in a hash table.
 * @ht: The hash table.
 * @key: The key to search for.
 * @value: The new value to assign.
 */
void replace_value(hash_node_t **ht, const char *key, const char *value)
{
	hash_node_t *temp = *ht;

	while (temp && strcmp(temp->key, key))
		temp = temp->next;

	free(temp->value);
	temp->value = strdup(value);
}

/**
 * check_key - Checks if a key exists in a hash table.
 * @ht: The hash table.
 * @key: The key to search for.
 *
 * Return: 1 if the key exists, 0 otherwise.
 */
int check_key(hash_node_t *ht, const char *key)
{
	while (ht)
	{
		if (!strcmp(ht->key, key))
			return (1);
		ht = ht->next;
	}
	return (0);
}

/**
 * add_node - Adds a new node to a hash table.
 * @head: The head of the linked list.
 * @key: The key for the new node.
 * @value: The value for the new node.
 *
 * Return: The updated head of the linked list.
 */
hash_node_t *add_node(hash_node_t **head, const char *key, const char *value)
{
	hash_node_t *new;

	new = malloc(sizeof(hash_node_t));
	if (!new)
		return (NULL);

	new->key = strdup(key);
	new->value = strdup(value);

	if (*head == NULL)
	{
		(*head) = new;
		new->next = NULL;
	}
	else
	{
		new->next = (*head);
		(*head) = new;
	}
	return (*head);
}

/**
 * hash_table_set - Adds or updates a key-value pair in a hash table.
 * @ht: The hash table.
 * @key: The key to add or update.
 * @value: The value associated with the key.
 *
 * Return: 1 if successful, 0 otherwise.
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;

	if (!ht || !key || !strcmp(key, "") || !value)
		return (0);

	index = key_index((unsigned char *)key, ht->size);

	if (check_key(ht->array[index], key))
	{
		replace_value(&ht->array[index], key, value);
		return (1);
	}
	add_node(&ht->array[index], key, value);
	if (&ht->array[index] == NULL)
		return (0);
	return (1);
}
