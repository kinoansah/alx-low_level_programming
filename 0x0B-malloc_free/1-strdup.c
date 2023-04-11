#include <stdlib.h>
#include <string.h>
#include "main.h"

/**
 * _strdup - returns a pointer to a newly allocated space in memory
 *
 *  _strdup - duplicates a string using malloc
 * @str: string to duplicate
 *
 * Return: (new_str)
 */

char *_strdup(char *str)
{
	char *new_str;

    /* Check if input string is NULL */
	if (str == NULL)
	{
		return (NULL);
	}

    /* Allocate memory for the new string */
	new_str = malloc(strlen(str) + 1);

    /* Check if malloc was successful */
	if (new_str == NULL)
	{
		return (NULL);
	}

    /* Copy the string to the new memory location */
	strcpy(new_str, str);

	return (new_str);
}

