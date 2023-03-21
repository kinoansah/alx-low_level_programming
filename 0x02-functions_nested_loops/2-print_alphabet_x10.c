#include "main.h"

/**
 * print_alphabet_x10 - print 10 times the alphabet, in lowercase
 *
 * Return: always 0;
 *
 */

void print_alphabet_x10(void)
{
	char i;
	char h;

	for (h = 0; h <= 9; h++)
	{
		for (i = 'a'; i <= 'z'; i++)
		{
			_putchar(i);
		}
		_putchar('\n');
	}
}
