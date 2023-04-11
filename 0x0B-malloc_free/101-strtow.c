#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * count_words - Counts the number of words in a string.
 * @str: The string to be counted.
 *
 * Return: The number of words in the string.
 */
int count_words(char *str)
{
    int count = 0, i = 0;

    while (str[i])
    {
        if (str[i] == ' ')
            i++;
        else
        {
            count++;
            while (str[i] && str[i] != ' ')
                i++;
        }
    }

    return (count);
}

/**
 * next_word - Locates the next word in a string.
 * @str: The string to be parsed.
 *
 * Return: A pointer to the next word.
 */
char *next_word(char *str)
{
    while (*str && *str == ' ')
        str++;

    return (str);
}

/**
 * strtow - Splits a string into words.
 * @str: The string to be split.
 *
 * Return: If str = NULL, str = "", or memory allocation fails - NULL.
 *         Otherwise - a pointer to an array of strings (words).
 */
char **strtow(char *str)
{
    char **words, *word_start;
    int i = 0, num_words = 0, word_len;

    if (str == NULL || *str == '\0')
        return (NULL);

    num_words = count_words(str);
    words = malloc(sizeof(char *) * (num_words + 1));

    if (words == NULL)
        return (NULL);

    while (*str)
    {
        str = next_word(str);
        word_start = str;
        word_len = 0;

        while (*str && *str != ' ')
        {
            word_len++;
            str++;
        }

        words[i] = malloc(sizeof(char) * (word_len + 1));

        if (words[i] == NULL)
        {
            while (i--)
                free(words[i]);

            free(words);
            return (NULL);
        }

        for (i = 0; i < word_len; i++)
            words[i][i] = *word_start++;

        words[i][i] = '\0';
	i++;
    }

    words[i] = NULL;
    return (words);
}
