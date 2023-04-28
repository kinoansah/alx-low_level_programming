#include "function_pointers.h"
#include <stdio.h>

/**
 * print_name - prints a name using a given function pointer
 * @name: pointer to the name string to print
 * @f: pointer to a function that takes a char pointer as an argument and
 * returns void
 *
 * Return: void
 */
void print_name(char *name, void (*f)(char *))
{
	if (name == NULL || f == NULL)
		return;

	f(name);
}
