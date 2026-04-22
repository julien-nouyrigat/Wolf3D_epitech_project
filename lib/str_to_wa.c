/*
** EPITECH PROJECT, 2026
** str_to_wa
** File description:
** str_to_wa
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static int is_sep(char c)
{
    if (c == ' ' || c == '\n' || c == '\t')
        return 1;
    return 0;
}

int count_word_loop(char *str, int i)
{
    while (is_sep(str[i]) == 0 && str[i] != '\0')
        i++;
    return i;
}

static int count_words(char *str)
{
    int i = 0;
    int count = 0;

    while (str[i] != '\0') {
        while (str[i] != '\0' && is_sep(str[i]) == 1)
            i++;
        if (str[i] != '\0') {
            count++;
            i = count_word_loop(str, i);
        }
    }
    return count;
}

static char *get_word(char *str, int *i)
{
    int start = *i;
    int len = 0;
    char *word;

    while (is_sep(str[*i]) == 0 && str[*i] != '\0') {
        (*i)++;
        len++;
    }
    word = malloc(sizeof(char) * (len + 1));
    for (int j = 0; j < len; j++)
        word[j] = str[start + j];
    word[len] = '\0';
    return word;
}

int only_sep(char *str)
{
    int i = 0;

    while (str[i] != '\0'){
        if (is_sep(str[i]) == 0)
            return 0;
        i++;
    }
    return 1;
}

char **my_str_to_wa(char *str)
{
    char **dest;
    int i = 0;
    int j = 0;
    int words;

    if (str == NULL || only_sep(str) == 1)
        return NULL;
    words = count_words(str);
    dest = malloc(sizeof(char *) * (words + 1));
    while (str[i] != '\0') {
        while (is_sep(str[i]))
            i++;
        if (str[i] != '\0') {
            dest[j] = get_word(str, &i);
            j++;
        }
    }
    dest[j] = NULL;
    return dest;
}
