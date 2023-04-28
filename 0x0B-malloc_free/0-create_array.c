#include <stdlib.h>
#include "main.h"
#include <stdio.h>

/**
 * create_array - creates an array of chars, and initializes it with
 * a specific char
 *
 * @size: size of array
 * @c: character
 *
 * Return: (arr)
 */

char *create_array(unsigned int size, char c)
{
	unsigned int i;
	char *arr;

	if (size == 0)
	{
		return (NULL);
	}

	arr = (char *)malloc(size * sizeof(char));
	if (arr == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < size; i++)
	{
		arr[i] = c;
	}

	return (arr);
}

