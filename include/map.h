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
    float angle;
    float x;
    float y;
    float aTan;
    float x_offset;
    float y_offset;
    float max_cast;
} ray_t;

typedef struct {
    sfRectangleShape *ceilling;
    sfTexture *floor;
    int x;
    int y;
    int **int_map;
} map_t;

#endif /* MAP_H_ */
