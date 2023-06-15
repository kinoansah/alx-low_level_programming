#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERNAME_LENGTH 100

void generate_key(char *username, char *key) {
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s username\n", argv[0]);
        return 1;
    }

    char username[MAX_USERNAME_LENGTH];
    char key[MAX_KEY_LENGTH];

    strncpy(username, argv[1], MAX_USERNAME_LENGTH);

    generate_key(username, key);

    printf("%s\n", key);

    return 0;
}

