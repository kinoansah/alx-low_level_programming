#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

shash_table_t *shash_table_create(unsigned long int size)
{
    shash_table_t *ht = malloc(sizeof(shash_table_t));
    if (ht == NULL)
        return NULL;

    ht->size = size;
    ht->array = malloc(sizeof(shash_node_t *) * size);
    if (ht->array == NULL)
    {
        free(ht);
        return NULL;
    }

    ht->shead = NULL;
    ht->stail = NULL;

    return ht;
}

int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
    unsigned long int index;
    shash_node_t *new_node, *current;

    if (ht == NULL || key == NULL || value == NULL)
        return 0;

    index = key_index((const unsigned char *)key, ht->size);

    current = ht->array[index];
    while (current != NULL)
    {
        if (strcmp(current->key, key) == 0)
        {
            free(current->value);
            current->value = strdup(value);
            return 1;
        }
        current = current->next;
    }

    new_node = malloc(sizeof(shash_node_t));
    if (new_node == NULL)
        return 0;

    new_node->key = strdup(key);
    new_node->value = strdup(value);
    new_node->next = ht->array[index];
    new_node->sprev = NULL;
    new_node->snext = NULL;
    ht->array[index] = new_node;

    /* Insert into sorted linked list */
    if (ht->shead == NULL)
    {
        ht->shead = new_node;
        ht->stail = new_node;
    }
    else
    {
        current = ht->shead;
        while (current != NULL && strcmp(key, current->key) > 0)
            current = current->snext;

        if (current == NULL)
        {
            new_node->sprev = ht->stail;
            ht->stail->snext = new_node;
            ht->stail = new_node;
        }
        else if (current->sprev == NULL)
        {
            new_node->snext = ht->shead;
            ht->shead->sprev = new_node;
            ht->shead = new_node;
        }
        else
        {
            new_node->sprev = current->sprev;
            new_node->snext = current;
            current->sprev->snext = new_node;
            current->sprev = new_node;
        }
    }

    return 1;
}

char *shash_table_get(const shash_table_t *ht, const char *key)
{
    unsigned long int index;
    shash_node_t *current;

    if (ht == NULL || key == NULL)
        return NULL;

    index = key_index((const unsigned char *)key, ht->size);

    current = ht->array[index];
    while (current != NULL)
    {
        if (strcmp(current->key, key) == 0)
            return current->value;
        current = current->next;
    }

    return NULL;
}

void shash_table_print(const shash_table_t *ht)
{
    shash_node_t *current;

    if (ht == NULL)
        return;

    current = ht->shead;
    printf("{");
    while (current != NULL)
    {
        printf("'%s': '%s'", current->key, current->value);
        current = current->snext;
        if (current != NULL)
            printf(", ");
    }
    printf("}\n");
}

void shash_table_print_rev(const shash_table_t *ht)
{
    shash_node_t *current;

    if (ht == NULL)
        return;

    current = ht->stail;
    printf("{");
    while (current != NULL)
    {
        printf("'%s': '%s'", current->key, current->value);
        current = current->sprev;
        if (current != NULL)
            printf(", ");
    }
    printf("}\n");
}
