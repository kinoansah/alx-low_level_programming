#include <stdio.h>
#include "main.h"

/**
 * main - Entry point of the program
 * @argc: The number of arguments passed to the program
 * @argv: An array of strings containing the arguments passed to the program
 *
 * Return: Always 0 (Success)
 */
int main(int argc, char *argv[])
{
int i;

    /* Iterate over each argument and print it on a new line */
for (i = 0; i < argc; i++)
{
printf("%s\n", argv[i]);
}

    /* Return 0 to indicate successful completion of the program */
return (0);
}
