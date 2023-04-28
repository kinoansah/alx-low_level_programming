#include <stdio.h>

/**
 * factorial - returns the factorial of a number
 * @n: number to return the factorial from
 *
 * Return: factorial of n
 */

int factorial(int n)
{
	/* base case: factorial of 0 is 1 */
	if (n == 0)
	return (1);

	/* error case: factorial of negative numbers is undefined */
	if (n < 0)
	return (-1);

	/* recursive case: multiply n by the factorial of n-1 */
	return (n * factorial(n - 1));
}
