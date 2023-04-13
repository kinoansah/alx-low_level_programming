#include <stdlib.h>
#include <stdio.h>
#include "main.h"

/**
 * malloc_checked - Allocates memory using malloc
 *
 * @b: Size of the memory block to allocate
 *
 * Return: Pointer to the allocated memory block
 *         Exits with status value of 98 if malloc fails
 **/
void *malloc_checked(unsigned int b)
{
	void *ptr = malloc(b);

	if (!ptr)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(98);
	}
	return (ptr);
}
