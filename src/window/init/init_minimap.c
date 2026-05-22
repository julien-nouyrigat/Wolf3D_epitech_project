/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** init_minimap
*/

#include <stdlib.h>
#include "wolf.h"

static void reverse_map(map_t *map)
{
    size_t max = MAP_SIZE;

    map->int_map_reversed = malloc(sizeof(int *) * MAP_SIZE);
    for (size_t i = 0; i < MAP_SIZE; i++) {
        map->int_map_reversed[i] = malloc(sizeof(int) * MAP_SIZE);
        for (size_t j = 0; j < MAP_SIZE; j++) {
            map->int_map_reversed[i][j] = map->int_map[i][max - j];
        }
    }
}

static void init_player_minimap(window_t *win)
{
    win->minimap.s_player = sfSprite_create();
    win->minimap.t_player = sfTexture_createFromFile(
        "./assets/image/player_cursor.png", NULL);
    sfSprite_setTexture(win->minimap.s_player, win->minimap.t_player, sfTrue);
    sfSprite_setScale(win->minimap.s_player, (sfVector2f){0.20, 0.20});
}

static void init_rect_player(window_t *win)
{
    win->minimap.player = sfCircleShape_create();
    win->minimap.wall = sfRectangleShape_create();
    win->minimap.bg = sfRectangleShape_create();
    sfRectangleShape_setSize(win->minimap.wall, (sfVector2f){TILE_SIZE,
            TILE_SIZE});
    sfRectangleShape_setOutlineThickness(win->minimap.wall, -2.0);
    sfRectangleShape_setOutlineColor(win->minimap.wall, sfColor_fromRGB(0, 255,
            0));
    sfCircleShape_setRadius(win->minimap.player, TILE_SIZE / 4.0);
    sfCircleShape_setOrigin(win->minimap.player, (sfVector2f){TILE_SIZE / 4.0,
            TILE_SIZE / 4.0});
    sfCircleShape_setFillColor(win->minimap.player, sfColor_fromRGB(0, 255,
            255));
    sfRectangleShape_setSize(win->minimap.bg, (sfVector2f){200, 200});
    sfRectangleShape_setPosition(win->minimap.bg,
        (sfVector2f){0, 0});
    sfRectangleShape_setFillColor(win->minimap.bg, sfRed);
}

void init_minimap(window_t *win, map_t *map)
{
    sfVector2f view_size;
    float ratio = (float)WIN_WIDTH / (float)WIN_HEIGHT;
    sfFloatRect viewport = {0.80, 0.05, 0.15, 0.15};

    win->view_minimap = sfView_create();
    view_size.x = 20 * TILE_SIZE * ratio;
    view_size.y = 20 * TILE_SIZE;
    sfView_setSize(win->view_minimap, view_size);
    sfView_setViewport(win->view_minimap, viewport);
    init_rect_player(win);
    init_player_minimap(win);
    reverse_map(map);
}
