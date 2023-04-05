#include <stdio.h>

/**
 * _pow_recursion - returns the value of x raised to the power y
 * @x: value to be raised
 * @y: power
 *
 * Return: result of the power
 */

int _pow_recursion(int x, int y)
{
	/* Base case: If y is 0, return 1 */
	if (y == 0)
	{
		return (1);
	}
    /* If y is negative, return -1 */
	else if (y < 0)
	{
		return (-1);
	}
    /* Recursive case: Multiply x by _pow_recursion(x, y-1) */
	else
	{
		return (x * _pow_recursion(x, y - 1));
	}
}
