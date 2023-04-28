#include <stdlib.h>
#include "main.h"

/**
 * free_grid - Frees a 2D array previously created by alloc_grid function.
 *
 * @grid: Pointer to the 2D array to free.
 * @height: Height of the 2D array to free.
 *
 * Return: void.
 */

void free_grid(int **grid, int height)
{
	int i;

	for (i = 0; i < height; i++)
	{
		free(grid[i]);
	}
	free(grid);
}
