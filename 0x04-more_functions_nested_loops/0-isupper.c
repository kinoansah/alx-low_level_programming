#include "main.h"

/**
 * main - checks for uppercase character
 * @c: character that is checked
 * is written by sirking
 * Return: 1 if c is uppercase, 0 otherwise
 */

int _isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return (1);
	}
		return (0);
}
