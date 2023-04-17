#ifndef DOG_H
#define DOG_H

/**
 * struct dog - a struct that holds information about a dog
 * @name: the name of the dog (a string)
 * @age: the age of the dog (a float)
 * @owner: the name of the owner (a string)
 *
 * Description: This struct holds information about a dog, including its
 * name, age, and owner's name.
 */
struct dog
{
	char *name;
	float age;
	char *owner;
};

#endif /* DOG_H */
