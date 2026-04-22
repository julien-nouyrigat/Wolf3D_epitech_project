/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** destroy
*/

#include <stdlib.h>

#include "wolf.h"

void destroy_assets(window_t *wolf_win, player_t *player)
{
    if (wolf_win) {
        sfRenderWindow_destroy(wolf_win->window);
        free(wolf_win);
    }
    if (player)
        free(player);
}
