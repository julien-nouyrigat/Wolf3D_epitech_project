/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** main
*/

#include <string.h>

#include "main.h"
#include "wolf.h"

int main(int ac, char **av)
{
    if (ac > 2)
        return EXIT_FAILURE;
    if (ac != 2)
        return EXIT_FAILURE;
    if (strcmp(av[FLAG], FLAG_H) == 0)
        return flag_h();
    return wolf(av[1]);
}
