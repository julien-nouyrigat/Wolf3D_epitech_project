/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** minimap
*/

#include "wolf.h"

static void update_minimap(window_t *win, player_t *player)
{
    float angle_rad = atan2(player->direction.y, player->direction.x);
    float angle_deg = angle_rad * (180 / M_PI);
    sfVector2f player_center = {player->position.x, player->position.y};

    sfSprite_setRotation(win->minimap.s_player, (angle_deg + 90));
    sfView_setCenter(win->view_minimap, player_center);
    sfView_setRotation(win->view_minimap, (angle_deg + 90));
}

static void set_bounds(int *bounds, player_t *player)
{
    bounds[0] = ((int)player->position.x / TILE_SIZE) - RENDER_DISTANCE;
    bounds[1] = ((int)player->position.x / TILE_SIZE) + RENDER_DISTANCE;
    bounds[2] = ((int)player->position.y / TILE_SIZE) - RENDER_DISTANCE;
    bounds[3] = ((int)player->position.y / TILE_SIZE) + RENDER_DISTANCE;
    if (bounds[0] < 0)
        bounds[0] = 0;
    if (bounds[1] >= MAP_SIZE)
        bounds[1] = MAP_SIZE - 1;
    if (bounds[2] < 0)
        bounds[2] = 0;
    if (bounds[3] >= MAP_SIZE)
        bounds[3] = MAP_SIZE - 1;
}

static void draw_tile(window_t *win, map_t *map, int x, int y)
{
    sfVector2f pos = {x * TILE_SIZE, y * TILE_SIZE};

    sfRectangleShape_setPosition(win->minimap.wall, pos);
    if (map->int_map[y][x] == 1) {
        sfRectangleShape_setFillColor(win->minimap.wall, sfColor_fromRGB(0, 50,
                10));
        sfRenderWindow_drawRectangleShape(win->window, win->minimap.wall, NULL);
    } else if (map->int_map[y][x] == 3) {
        return;
    } else {
        sfRectangleShape_setFillColor(win->minimap.wall, sfColor_fromRGB(0, 120,
                30));
        sfRenderWindow_drawRectangleShape(win->window, win->minimap.wall, NULL);
    }
    if (x == 31 && y == 31) {
        sfRectangleShape_setFillColor(win->minimap.wall,
            sfColor_fromRGB(102, 255, 255));
        sfRenderWindow_drawRectangleShape(win->window, win->minimap.wall, NULL);
    }
}

static void draw_tiles(window_t *win, map_t *map, int *bounds)
{
    for (int y = bounds[3]; y >= bounds[2]; y--) {
        for (int x = bounds[1]; x >= bounds[0]; x--) {
            draw_tile(win, map, x, y);
        }
    }
}

static void draw_minimap(window_t *win, player_t *player, map_t *map)
{
    int bounds[4];

    set_bounds(bounds, player);
    sfRenderWindow_drawRectangleShape(win->window, win->minimap.bg, NULL);
    draw_tiles(win, map, bounds);
}

static void draw_player_2d(window_t *win, player_t *player)
{
    sfVector2f pos = {player->position.x, player->position.y};

    printf("x%f y%f\n", pos.x, pos.y);
    sfSprite_setPosition(win->minimap.s_player, pos);
    sfRenderWindow_drawSprite(win->window, win->minimap.s_player, NULL);
}

void display_minimap(window_t *win, player_t *player, map_t *map)
{
    const sfView *default_view = sfRenderWindow_getDefaultView(win->window);

    update_minimap(win, player);
    sfRenderWindow_setView(win->window, win->view_minimap);
    draw_minimap(win, player, map);
    draw_player_2d(win, player);
    sfRenderWindow_setView(win->window, default_view);
}
