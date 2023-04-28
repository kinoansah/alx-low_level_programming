#ifndef MAIN_H
#define MAIN_H

int _putchar(char c);
void free_dog(dog_t *d);
void print_dog(struct dog *d);
void init_dog(struct dog *d, char *name, float age, char *owner);
dog_t *new_dog(char *name, float age, char *owner);

#endif
