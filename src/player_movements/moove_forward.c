/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** moove_forward
*/

#include "wolf.h"

void moove_forward(player_t *player, map_t *map)
{
    int x_verif =
        (int)(player->position.x + player->direction.x * player->mvt_speed);
    int y_verif =
        (int)(player->position.y + player->direction.y * player->mvt_speed);

    if (map->int_map[x_verif][(int)player->position.y] == 0)
        player->position.x += player->direction.x * player->mvt_speed;
    if (map->int_map[(int)player->position.x][y_verif] == 0)
        player->position.y += player->direction.y * player->mvt_speed;
}
