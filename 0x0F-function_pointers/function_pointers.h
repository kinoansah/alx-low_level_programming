#ifndef Main_h
#define Main_h

#include <stdlib.h>
#include <stddef.h>

int _putchar(char c);
int int_index(int *array, int size, int (*cmp)(int));
void array_iterator(int *array, size_t size, void (*action)(int));
void print_name(char *name, void (*f)(char *));

#endif
