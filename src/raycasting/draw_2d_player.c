/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** draw_2d_player
*/

#include "wolf.h"

void draw_2d_player(window_t *wolf_win, player_t *player)
{
    sfRectangleShape_setPosition(player->hitbox, player->position);
    sfRenderWindow_drawRectangleShape(wolf_win->window, player->hitbox, NULL);
}
