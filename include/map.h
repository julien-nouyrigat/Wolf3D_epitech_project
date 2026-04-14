/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** map
*/

#ifndef MAP_H_
    #define MAP_H_

    #define TILE_SIZE 64
    #define MAP_SIDE 8

typedef struct {
    sfRectangleShape *ceilling;
    sfTexture *floor;
    int **map;
} map_t;

#endif /* MAP_H_ */
