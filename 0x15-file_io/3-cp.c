#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

/**
 * main - copies the content of a file to another file.
 *
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to, num_read, num_written;
	char buffer[BUFFER_SIZE];

	if (argc != 3)
	{
		printf("Usage: %s file_from file_to\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
	{
		perror("Error opening file_from");
		exit(EXIT_FAILURE);
	}

	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_to == -1)
	{
		perror("Error opening file_to");
		exit(EXIT_FAILURE);
	}

	while ((num_read = read(fd_from, buffer, BUFFER_SIZE)) > 0)
	{
		num_written = write(fd_to, buffer, num_read);
		if (num_written == -1 || num_written != num_read)
		{
			perror("Error writing to file_to");
			close(fd_from);
			close(fd_to);
			exit(EXIT_FAILURE);
		}
	}

	if (num_read == -1)
	{
		perror("Error reading from file_from");
		close(fd_from);
		close(fd_to);
		exit(EXIT_FAILURE);
	}

	if (close(fd_from) == -1 || close(fd_to) == -1)
	{
		perror("Error closing file descriptors");
		exit(EXIT_FAILURE);
	}

	exit(EXIT_SUCCESS);
}

