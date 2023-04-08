#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * main - prints the minimum number of coins to
 * make change for an amount of money
 *
 * @argc: number of command line arguments
 * @argv: array of command line arguments
 *
 * Return: 0 if successful, 1 if there was an error
 */
int main(int argc, char *argv[])
{
int cents, coins = 0;

if (argc != 2) /* if incorrect number of arguments */
{
printf("Error\n");
return (1);
}

cents = atoi(argv[1]); /* convert argument to int */

if (cents < 0) /* if argument is negative */
{
printf("0\n");
return (0);
}

coins += cents / 25; /* count number of quarters */
cents %= 25; /* find remaining cents */

coins += cents / 10; /* count number of dimes */
cents %= 10; /* find remaining cents */

coins += cents / 5; /* count number of nickels */
cents %= 5; /* find remaining cents */

coins += cents / 2; /* count number of twopences */
cents %= 2; /* find remaining cents */

coins += cents; /* count number of pennies */

printf("%d\n", coins); /* print result */

return (0);
}

