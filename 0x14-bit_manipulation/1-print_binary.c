#include "main.h"

/**
 * print_binary - prints the binary representation of a number.
 * @n: unsigned long int to be converted to binary and printed.
 */
void print_binary(unsigned long int n)
{
	unsigned long int mask = 1;
	int bit_count = 0;

	/* Find the most significant bit in n */
	while ((mask << 1) <= n)
	{
		mask <<= 1;
		bit_count++;
	}

	/* Print the binary representation of n */
	while (mask > 0)
	{
		if ((n & mask) == mask)
			_putchar('1');
		else
			_putchar('0');
		mask >>= 1;
	}
	if (bit_count == 0)
		_putchar('0');
}

