/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** moove_forward
*/

#include "wolf.h"

void move_forward(player_t *player, map_t *map)
{
    int x_verif =
        (int)((player->position.x + player->direction.x * player->mvt_speed) / TILE_SIZE);
    int y_verif =
        (int)((player->position.y + player->direction.y * player->mvt_speed) / TILE_SIZE);

    if (map->int_map[(int)(player->position.y / TILE_SIZE)][x_verif] == 0) {
        player->position.x += player->direction.x * player->mvt_speed;
        player->pos_f.x = player->position.x / TILE_SIZE;
    }
    if (map->int_map[y_verif][(int)(player->position.x / TILE_SIZE)] == 0) {
        player->position.y += player->direction.y * player->mvt_speed;
        player->pos_f.y = player->position.y / TILE_SIZE;
    }
}
