/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** map
*/

#ifndef MAP_H_
    #define MAP_H_

    #include "level.h"

    #define TILE_SIZE 128
    #define MAP_SIDE 8
    #define MAP_SIZE 70

typedef struct {
    sfRectangleShape *ceilling;
    sfTexture *floor;
    int x;
    int y;
    int **int_map;
    int type;
    sfVector2i map_pos;
    struct level_s *level;
} map_t;

#endif /* MAP_H_ */
