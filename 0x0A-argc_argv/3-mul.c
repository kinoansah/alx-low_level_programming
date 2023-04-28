#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int multiply(int num1, int num2);

int main(int argc, char *argv[])
{
int num1, num2, result;

    /* Check if there are exactly two arguments */
if (argc != 3)
{
printf("Error\n");
return (1);
}

    /* Convert the arguments from strings to integers */
num1 = atoi(argv[1]);
num2 = atoi(argv[2]);

    /* Multiply the two numbers and store the result */
result = multiply(num1, num2);

    /* Print the result, followed by a newline character */
printf("%d\n", result);

    /* Return 0 to indicate successful completion of the program */
return (0);
}

/**
 * multiply - Multiplies two integers
 * @num1: The first integer to be multiplied
 * @num2: The second integer to be multiplied
 *
 * Return: The product of num1 and num2
 */
int multiply(int num1, int num2)
{
return (num1 *num2);
}
