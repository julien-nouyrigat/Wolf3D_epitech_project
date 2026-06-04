/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** draw_hand
*/

#include "wolf.h"

void draw_hand(window_t *win, player_t *player)
{
    if (player->in_hand == NULL)
        return;
    animate_hand(player);
    sfRenderWindow_drawSprite(win->window, player->in_hand->sprite, NULL);
}
