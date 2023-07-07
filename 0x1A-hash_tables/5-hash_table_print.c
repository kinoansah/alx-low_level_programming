#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

/**
 * hash_table_print - function that prints a hash table
 * @ht: hash table
 *
 *Return: 0, ht is NULL
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i;
	unsigned char comma_flag;

	/* Check if the hash table is valid */
	if (ht == NULL)
		return;

	printf("{");
	comma_flag = 0;	/* Flag to track comma printing */
	/* Print the array elements */
	for (i = 0; i < ht->size; i++)
	{
		hash_node_t *node = ht->array[i];

		while (node != NULL)
		{
			if (comma_flag)
				printf(", ");
			printf("'%s': '%s'", node->key, node->value);
			comma_flag = 1;
			node = node->next;
		}
	}

	printf("}\n");
}
