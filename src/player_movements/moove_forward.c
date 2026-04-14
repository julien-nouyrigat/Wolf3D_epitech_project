/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** moove_forward
*/

#include "player.h"

void moove_forward(player_t *player)
{
    player->x += player->delta_x;
    player->y += player->delta_y;
}
