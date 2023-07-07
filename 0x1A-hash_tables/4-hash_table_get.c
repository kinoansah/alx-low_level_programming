#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

/**
 * hash_table_get - function that retrieves a value associated key
 * @ht: the hash table to find
 * @key: key been looked for
 *
 * Return: valued associated key, NULL if not found
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index;
	hash_node_t *node;

	/* Check if the hash table and key are valid */
	if (ht == NULL || key == NULL)
		return (NULL);

	/* Calculate the index for the key */
	index = key_index((const unsigned char *)key, ht->size);

	/* Traverse the linked list at the index */
	node = ht->array[index];
	while (node != NULL)
	{
		/* Compare the keys */
		if (strcmp(node->key, key) == 0)
			return (node->value);

		/* Move to the next node */
		node = node->next;
	}

	/* Key not found */
	return (NULL);
}
