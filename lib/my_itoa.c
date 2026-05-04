/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** my_itoa
*/

#include <stdbool.h>
#include <stdlib.h>

static int nb_chars(int nb)
{
    int nb_chars = 1;

    if (nb < 0)
        nb = - nb;
    for (; nb / 10 > 0; nb /= 10)
        nb_chars++;
    return nb_chars;
}

static void fill_str(char **str, int nb, int size, bool is_neg)
{
    int rem = 0;
    int i = size - 1;

    for (; nb != 0; nb /= 10) {
        rem = nb % 10;
        (*str)[i] = rem + '0';
        i--;
    }
    if (is_neg) {
        (*str)[0] = '-';
    }
}

char *my_itoa(int nb)
{
    int size = nb_chars(nb);
    bool is_neg = false;
    char *str = NULL;

    if (nb < 0) {
        is_neg = true;
        nb = - nb;
        size++;
    }
    str = malloc(sizeof(char) * (size + 1));
    if (!str)
        return NULL;
    if (nb == 0) {
        str = "0\0";
        return str;
    }
    str[size] = '\0';
    fill_str(&str, nb, size, is_neg);
    return str;
}
