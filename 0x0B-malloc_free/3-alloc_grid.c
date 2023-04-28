#include <stdlib.h>
#include "main.h"

/**
 * alloc_grid - allocate memory for a 2D array of integers and initialize all
 * elements to 0
 *
 * @width: the number of columns in the grid
 * @height: the number of rows in the grid
 *
 * Return: a pointer to the allocated grid, or NULL if the allocation fails or
 * if width/height are 0 or negative
 */

int **alloc_grid(int width, int height)
{
	int **grid;
	int i, j;

	if (width <= 0 || height <= 0)
	{
		return (NULL);
	}

	grid = (int **) malloc(height * sizeof(int *));
	if (grid == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < height; i++)
	{
		grid[i] = (int *) calloc(width, sizeof(int));
		if (grid[i] == NULL)
		{
			for (j = 0; j < i; j++)
			{
				free(grid[j]);
			}
			free(grid);
			return (NULL);
		}
	}

	return (grid);
}
