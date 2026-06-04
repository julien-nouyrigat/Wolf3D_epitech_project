/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** init_minimap
*/

#include <stdlib.h>
#include "wolf.h"

static void init_player_minimap(window_t *win)
{
    sfFloatRect rect;

    win->minimap.s_player = sfSprite_create();
    win->minimap.t_player = sfTexture_createFromFile(
        "./assets/image/player_cursor.png", NULL);
    sfSprite_setTexture(win->minimap.s_player, win->minimap.t_player, sfTrue);
    sfSprite_setScale(win->minimap.s_player, (sfVector2f){0.20, 0.20});
    rect = sfSprite_getLocalBounds(win->minimap.s_player);
    sfSprite_setOrigin(win->minimap.s_player,
        (sfVector2f){rect.width / 2, rect.height / 2});
}

static void init_tv(window_t *win)
{
    win->minimap.s_tv = sfSprite_create();
    win->minimap.t_tv = sfTexture_createFromFile(
        "./assets/image/tv_map.png", NULL);
    sfSprite_setTexture(win->minimap.s_tv, win->minimap.t_tv, sfTrue);
    sfSprite_setScale(win->minimap.s_tv, (sfVector2f){2.35, 2.2});
    sfSprite_setPosition(win->minimap.s_tv, (sfVector2f){400, 45});
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
    sfRectangleShape_setSize(win->minimap.bg, (sfVector2f){100000, 200000});
    sfRectangleShape_setPosition(win->minimap.bg,
        (sfVector2f){0, 0});
    sfRectangleShape_setFillColor(win->minimap.bg, sfColor_fromRGB(0, 50,
            10));
}

void init_minimap(window_t *win)
{
    sfVector2f view_size;
    float ratio = (float)WIN_WIDTH / (float)WIN_HEIGHT;
    sfFloatRect viewport = {0.308, 0.237, 0.4, 0.43};

    win->view_minimap = sfView_create();
    view_size.x = -15 * TILE_SIZE * ratio;
    view_size.y = 15 * TILE_SIZE;
    sfView_setSize(win->view_minimap, view_size);
    sfView_setViewport(win->view_minimap, viewport);
    init_rect_player(win);
    init_player_minimap(win);
    init_tv(win);
}
