/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** draw_2d_player
*/

#include <stdio.h>
#include "wolf.h"

void draw_2d_player(window_t *wolf_win, player_t *player)
{
    sfVector2f position = (sfVector2f){player->pos_x, player->pos_y};

    sfRectangleShape_setPosition(player->hitbox, position);
    sfRenderWindow_drawRectangleShape(wolf_win->window, player->hitbox, NULL);
}
