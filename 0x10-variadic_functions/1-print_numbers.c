#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_numbers - prints a variable number of integers separated by a string
 * @separator: the string to print between integers
 * @n: the number of integers to print
 * Return: void
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list args;
	unsigned int i;
	int num;

	va_start(args, n);

	for (i = 0; i < n; i++)
	{
		num = va_arg(args, int);
		printf("%d", num);

		if (separator != NULL && i != n - 1)
			printf("%s", separator);
	}

	va_end(args);

	printf("\n");
}
