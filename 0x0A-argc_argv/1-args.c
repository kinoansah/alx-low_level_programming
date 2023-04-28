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
    /* Unused parameter argv */
(void) argv;

    /* Print the number of arguments passed in (excluding the program name) */
printf("%d\n", argc - 1);

    /* Return 0 to indicate successful completion of the program */
return (0);
}
