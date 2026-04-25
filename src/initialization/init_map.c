/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** init_map
*/

#include <stdlib.h>

#include "textures.h"
#include "room.h"
#include "wolf.h"

int init_map(map_t **map)
{
    *map = malloc(sizeof(map_t));
    if (!*map)
        return EXIT_FAILURE;
    (*map)->x = SIZE_MAP;
    (*map)->y = SIZE_MAP;
    (*map)->int_map = create_map(20);
    (*map)->type = CASTLE;
    (*map)->map_pos = (sfVector2i){0, 0};
    return EXIT_SUCCESS;
}
