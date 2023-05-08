#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * read_textfile - reads a text file and prints it to the POSIX standard output
 *
 * @filename: the name of the file to read
 * @letters: the number of letters to read and print
 *
 * Return: the actual number of letters read and printed, or 0 on failure
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	/* Check for NULL filename */
	if (filename == NULL)
	{
		return (0);
	}

	/* Attempt to open file for reading */
	FILE *file = fopen(filename, "r");
	if (file == NULL)
	{
		return (0);
	}

	/* Allocate buffer for file contents */
	char *buffer = (char*) malloc(sizeof(char) * letters);
	if (buffer == NULL)
	{
		fclose(file);
		return (0);
	}

	/* Read up to letters characters from file into buffer */
	ssize_t bytes_read = fread(buffer, sizeof(char), letters, file);
	if (bytes_read == -1)
	{
		fclose(file);
		free(buffer);
		return (0);
	}

	/* Write buffer contents to standard output */
	ssize_t bytes_written = write(STDOUT_FILENO, buffer, bytes_read);
	if (bytes_written == -1 || bytes_written != bytes_read)
	{
		fclose(file);
		free(buffer);
		return (0);
	}

	/* Clean up and return number of bytes read */
	fclose(file);
	free(buffer);

	return (bytes_read);
}

