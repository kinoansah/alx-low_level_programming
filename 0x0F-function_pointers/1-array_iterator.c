#include <stdio.h>
#include "function_pointers.h"

/**
 * array_iterator - Applies an action to each element in an array
 *
 * @array: Pointer to the array to iterate over
 * @size: The size of the array
 * @action: A pointer to a function to apply to each element
 *
 * Return: Nothing
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	unsigned int i;

	if (array == NULL || action == NULL)
		return;

	for (i = 0; i < size; i++)
		action(array[i]);
}
