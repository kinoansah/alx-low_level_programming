#ifndef MAIN_H
#define MAIN_H

int _putchar(char c);
int (*get_op_func(char *s))(int, int);
int op_add(int a, int b);
int int_index(int *array, int size, int (*cmp)(int));
void array_iterator(int *array, size_t size, void (*action)(int));
void print_name(char *name, void (*f)(char *));

#endif
