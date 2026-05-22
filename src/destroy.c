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
        sfMusic_destroy(wolf_win->ambiance);
        sfRenderWindow_destroy(wolf_win->window);
        free(wolf_win);
    }
    if (player){
        if (player->inventory){
            sfSprite_destroy(player->inventory->s_inventory);
            sfTexture_destroy(player->inventory->t_inventory);
            free(player->inventory);
        }
        sfClock_destroy(player->p_clock);
        free(player);
    }
}
