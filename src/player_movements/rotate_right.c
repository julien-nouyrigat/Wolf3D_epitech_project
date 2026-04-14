/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** rotate_right
*/

#include "player.h"

void rotate_right(player_t *player)
{
    player->angle -= 0.1;
    if (player->angle > 2 * M_PI)
        player->angle = 0;
    player->delta_x = cos(player->angle) * 5;
    player->delta_y = sin(player->angle) * 5;
}
