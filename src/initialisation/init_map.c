/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** init_map
*/

#include <stdlib.h>

#include "wolf.h"

static void fill_map_line(map_t **map, int i)
{
    for (int j = 0; j < (*map)->y; j++) {
        if (i == 0 || i == (*map)->x - 1 || j == 0 || j == (*map)->y - 1)
            (*map)->int_map[i][j] = 1;
        else
            (*map)->int_map[i][j] = 0;
    }
}

static int get_int_map(map_t **map)
{
    for (int i = 0; i < (*map)->x; i++) {
        (*map)->int_map[i] = malloc(sizeof(int) * (*map)->y);
        if (!(*map)->int_map[i]) {
            free((*map)->int_map);
            free(*map);
            return EXIT_FAILURE;
        }
        fill_map_line(map, i);
    }
    (*map)->int_map[1][5] = 1;
    (*map)->int_map[2][5] = 1;
    (*map)->int_map[3][5] = 1;
    (*map)->int_map[4][1] = 1;
    (*map)->int_map[4][2] = 1;
    return EXIT_SUCCESS;
}

int init_map(map_t **map)
{
    *map = malloc(sizeof(map_t));
    if (!*map)
        return EXIT_FAILURE;
    (*map)->x = 8;
    (*map)->y = 8;
    (*map)->int_map = malloc(sizeof(int *) * (*map)->y);
    if (!(*map)->int_map) {
        free(*map);
        return EXIT_FAILURE;
    }
    if (get_int_map(map) == EXIT_FAILURE)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}
