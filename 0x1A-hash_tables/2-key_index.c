#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

/**
 * key_index - function which gives the index of a key
 * @size: size of the array of the hash table
 * @key: the key
 *
 * Return: index of key
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	/* Assuming a hash_djb2 function in directory */
	unsigned long int hash_value = hash_djb2(key);

	/* Calculate the index by taking the modulo of the hash value with the size */
	unsigned long int index = size > 0 ? hash_value % size : 0;

	return (index);
}
