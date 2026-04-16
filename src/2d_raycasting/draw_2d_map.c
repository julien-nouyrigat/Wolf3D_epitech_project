/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** draw_2d_map
*/

#include "wolf.h"

static void draw_tile(window_t *wolf_win, map_t *map,
    sfVector2i *tile_coord, sfRectangleShape *tile)
{
    sfVector2f tile_pos = (sfVector2f)
    {tile_coord->y * TILE_SIZE + 1, tile_coord->x * TILE_SIZE + 1};

    sfRectangleShape_setPosition(tile, tile_pos);
    if (map->int_map[tile_coord->x][tile_coord->y] == 1) {
        sfRectangleShape_setFillColor(tile, sfWhite);
        sfRenderWindow_drawRectangleShape(wolf_win->window, tile, NULL);
    } else {
        sfRectangleShape_setFillColor(tile, sfBlack);
        sfRenderWindow_drawRectangleShape(wolf_win->window, tile, NULL);
    }
}

void draw_2d_map(window_t *wolf_win, map_t *map)
{
    sfRectangleShape *tile = sfRectangleShape_create();
    sfVector2f tile_size = (sfVector2f){TILE_SIZE - 2, TILE_SIZE - 2};
    sfVector2i tile_coordinates;

    sfRectangleShape_setSize(tile, tile_size);
    for (int i = 0; i < map->y; i++) {
        for (int j = 0; j < map->x; j++) {
            tile_coordinates = (sfVector2i){i, j};
            draw_tile(wolf_win, map, &tile_coordinates, tile);
        }
    }
}
