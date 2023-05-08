#ifndef MY_MAIN_H
#define MY_MAIN_H

#define BUFFER_SIZE 1024 /* Definition of buffer size for Task 3 */

/*
 * Description: Header file containing prototypes for all functions
 */

/* Libraries Used */
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

/* Prototypes */
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
int _putchar(char c);
ssize_t read_textfile(const char *filename, size_t letters);

#endif
