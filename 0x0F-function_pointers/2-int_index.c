#include "function_pointers.h"
#include <stdio.h>

/**
 * int_index - searches for an integer in an array using a given function.
 * @array: pointer to an array of integers.
 * @size: size of the array.
 * @cmp: pointer to a function that takes an integer as parameter and
 * returns an integer.
 *
 * Return: index of the first element for which the cmp function does not
 * return 0 or -1 if no element matches or size <= 0.
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int x;

	if (array == NULL || cmp == NULL || size <= 0)
		return (-1);

	for (x = 0; x < size; x++)
	{
		if (cmp(array[x]))
			return (x);
	}
	return (-1);
}
