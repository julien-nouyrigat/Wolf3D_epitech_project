/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** window_evts
*/

#include "wolf.h"

void close_window(window_t *win, player_t *player, map_t *map)
{
    (void)player;
    (void)map;
    sfRenderWindow_close(win->window);
}

void resize_window(window_t *win, player_t *player, map_t *map)
{
    (void)player;
    (void)map;
    win->size = sfRenderWindow_getSize(win->window);
}
