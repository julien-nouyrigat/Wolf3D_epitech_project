/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** rotate_left
*/

#include <math.h>

#include "wolf.h"

void rotate_left(player_t *player, map_t *map)
{
    float old_dir_x = player->direction.x;
    float old_plane_x = player->camera_plane.x;

    (void)map;
    player->direction.x = player->direction.x * cos(- ROTATION_SPEED) -
        player->direction.y * sin(- ROTATION_SPEED);
    player->direction.y = old_dir_x * sin(- ROTATION_SPEED) +
        player->direction.y * cos(- ROTATION_SPEED);
    player->camera_plane.x = player->camera_plane.x * cos(- ROTATION_SPEED) -
        player->camera_plane.y * sin(- ROTATION_SPEED);
    player->camera_plane.y = old_plane_x * sin(- ROTATION_SPEED) +
        player->camera_plane.y * cos(- ROTATION_SPEED);
}
