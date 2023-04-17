#include <stdlib.h>
#include <string.h>
#include "main.h"

dog_t *new_dog(char *name, float age, char *owner) {
    /* Allocate memory for the dog struct */
    dog_t *new_dog = malloc(sizeof(dog_t));
    if (new_dog == NULL) {
        return NULL; /* return NULL if malloc fails */
    }
    
    /* Allocate memory for the name string */
    new_dog->name = malloc(strlen(name) + 1); /* +1 for the null terminator */
    if (new_dog->name == NULL) {
        free(new_dog);
        return NULL; /* free the previously allocated memory and return NULL if malloc fails */
    }
    
    /* Allocate memory for the owner string */
    new_dog->owner = malloc(strlen(owner) + 1); /* +1 for the null terminator */
    if (new_dog->owner == NULL) {
        free(new_dog->name);
        free(new_dog);
        return NULL; /* free the previously allocated memory and return NULL if malloc fails */
    }
    
    /* Copy the name and owner strings to the new memory locations */
    strcpy(new_dog->name, name);
    strcpy(new_dog->owner, owner);
    
    /* Set the age of the dog */
    new_dog->age = age;
    
    return new_dog;
}

