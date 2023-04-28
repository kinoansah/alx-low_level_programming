#include <stdlib.h>

#include "lists.h"

/**

 * free_list - frees a linked list

 * @head: list_t list to be freed

 */

void free_list(list_t *head)

{

 list_t *temp;

 while (head)

 {

 temp = head->next;

 free(head->str);

 free(head);

 head = temp;

 }

}

===============================

100-first.c

#include <stdio.h>

void first(void) __attribute__ ((constructor));

/**

 * first - prints a sentence before the main

 * function is executed

 */

void first(void)

{

 printf("You're beat! and yet, you must allow,\n");

 printf("I bore my house upon my back!\n");

}
