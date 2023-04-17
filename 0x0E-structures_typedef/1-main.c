#include "dog.h"
#include <stdio.h>

int main(void)
{
    struct dog my_dog;

    init_dog(&my_dog, "Poppy", 3.5, "Bob");
    print_dog(&my_dog);

    return (0);
}

