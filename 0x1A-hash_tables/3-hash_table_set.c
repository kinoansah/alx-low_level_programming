#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

/**
 * hash_table_set - adds an element to the hash table
 * @ht: hash table to be added or updated
 * @key: the key to use
 * @value: value associated with the key
 *
 * Return: 1 if success, 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	hash_node_t *new_node;
	char *new_value;

	/* Check if the hash table and key are valid */
	if (ht == NULL || key == NULL)
		return (0);

	/* Calculate the index for the key */
	index = key_index((unsigned char *)key, ht->size);

	/* Create a new hash node */
	new_node = malloc(sizeof(hash_node_t));
	if (new_node == NULL)
		return (0);

	/* Duplicate the value */
	new_value = strdup(value);
	if (new_value == NULL)
	{
		free(new_node);
		return (0);
	}

	new_node->key = strdup(key);
	new_node->value = new_value;
	new_node->next = NULL;

	/* Add or update the node in the hash table */
	if (ht->array[index] == NULL)
	{
		ht->array[index] = new_node;
	}
	else
	{
		/* Handle collision by adding the new node */
		new_node->next = ht->array[index];
		ht->array[index] = new_node;
	}
	return (1);
}
