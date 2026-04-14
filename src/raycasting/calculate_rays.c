/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** calculate_rays
*/

#include <math.h>

#include "map.h"
#include "wolf.h"

void calculate_rays(player_t *player)
{
    float ray_angle = player->angle;
    float ray_x = 0;
    float ray_y = 0;
    float aTan = 0;
    float x_offset = 0;
    float y_offset = 0;
    float max_cast = 0;
    int map_x = 0;
    int map_y = 0;
    map_pos = 0;

    for (int ray_nb = 0; ray_nb < NB_RAYS; ray_nb ++) {
        aTan = -1 / tan(ray_angle);
        if (ray_angle > M_PI) {
            ray_y = (((int)player->y / TILE_SIZE) * TILE_SIZE) - OFFSET;
            ray_x = (player->y - ray_y) * aTan + player->x;
            y_offset -= TILE_SIZE;
            x_offset = - y_offset * aTan;
        }
        if (ray_angle < M_PI) {
            ray_y = (((int)player->y / TILE_SIZE) * TILE_SIZE) + TILE_SIZE;
            ray_x = (player->y - ray_y) * aTan + player->x;
            y_offset = TILE_SIZE;
            x_offset = - y_offset * aTan;
        }
        if (ray_angle == 0 || ray_angle == M_PI) {
            ray_x = player->x;
            ray_y = player->y;
            max_cast = MAP_SIDE;
        }
        while (max_cast < MAP_SIDE) {
            map_x = (int)ray_x / TILE_SIZE;
            map_y = (int)ray_y / TILE_SIZE;
            map_pos = map_y * MAP_SIDE + map_x;
            if (map_pos < MAP_SIDE * MAP_SIDE && map[map_pos] == 1)
                max_cast = MAP_SIDE;
            else {
                ray_x += x_offset;
                ray_y += y_offset;
                max_cast++;
            }
        }
    }
}
