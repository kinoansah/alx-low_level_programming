#include <stdlib.h>
#include <string.h>
#include "main.h"

/**
 * str_concat - concatenates two strings
 *
 * @s1: the first string to concatenate
 * @s2: the second string to concatenate
 *
 * Return: a newly allocated string containing s1 followed by s2,
 * or NULL on failure
 */
char *str_concat(char *s1, char *s2)
{
	size_t s1_len, s2_len;
	char *result;

	if (s1 == NULL)
	{
		s1 = "";
	}
	if (s2 == NULL)
	{
		s2 = "";
	}

	s1_len = strlen(s1);
	s2_len = strlen(s2);

	result = malloc(s1_len + s2_len + 1);
	if (result == NULL)
	{
		return (NULL);
	}

	memcpy(result, s1, s1_len);
	memcpy(result + s1_len, s2, s2_len + 1);

	return (result);
}
