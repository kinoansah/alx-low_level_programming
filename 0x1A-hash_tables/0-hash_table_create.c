#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

/**
 * hash_table_create - function which create hash table
 * @size: size of the array
 *
 * Return: pointer to the newly created hash table
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	unsigned long int i;

	/* Create hash table implementation */
	/* Allocate memory for the hash table structure */
	hash_table_t *hash_table = malloc(sizeof(hash_table_t));

	if (hash_table == NULL)
		return (NULL);

	/* Allocate memory for the array of size 'size' */
	hash_table->array = malloc(sizeof(hash_node_t *) * size);
	if (hash_table->array == NULL)
	{
		free(hash_table);
		return (NULL);
	}

	/* Initialize all array elements to NULL */
	for (i = 0; i < size; i++)
		hash_table->array[i] = NULL;

	/* Set the size of the hash table */
	hash_table->size = size;

	return (hash_table);
}
