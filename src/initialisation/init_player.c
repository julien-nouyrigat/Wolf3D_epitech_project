/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** init_player
*/

#include <stdlib.h>

#include "player.h"

int init_player(player_t *player)
{
    player = malloc(sizeof(player_t));
    if (!player)
        return EXIT_FAILURE;
    player->x = 4;
    player->y = 4;
    player->angle = 0;
    player->delta_x = cos(player->angle) * 5;
    player->delta_y = sin(player->angle) * 5;
    return EXIT_SUCCESS;
}
