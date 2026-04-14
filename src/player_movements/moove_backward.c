/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** moove_backward
*/

#include "player.h"

void moove_backward(player_t *player)
{
    player->x -= player->delta_x;
    player->y -= player->delta_y;
}
