/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** ray_calculation
*/

#include <math.h>

#include "wolf.h"

void ray_calculation(map_t *map, player_t *player)
{
    ray_t *ray = malloc(sizeof(ray_t));
    float pov = (M_PI / 3) / WIN_WIDTH;
    int map_x = (int)player->pos_x / TILE_SIZE;
    int map_y = (int)player->pos_y / TILE_SIZE;

    if (!ray)
        return EXIT_FAILURE;
    init_ray(ray);
    for (ray->angle = player->angle - (M_PI / 6);
    ray_angle <= player->angle + (M_PI / 6); ray_angle += pov) {
        ray->x_len = fabs(1 / cos(ray->angle));
        ray->y_len = fabs(1 / sin(ray->angle));
        if (cos(ray->angle) < 0)
            ray->x_step = -1;
        else
            ray->x_step = 1;
        if (sin(ray->angle) < 0)
            ray->y_step = -1;
        else
            ray->y_step = 1;
        if (x_step == -1)
            ray->x_dist = (player->pos_y / TILE_SIZE - map_x) * ray->x_len;
        else
            ray->x_dist = (map_x + 1 - (player->pos_y / TILE_SIZE)) * ray->x_len;
        if (y_step == -1)
            ray->y_dist = (player->pos_x / TILE_SIZE - map_y) * ray->y_len;
        else
            ray->y_dist = (map_y + 1 - (player->pos_x / TILE_SIZE)) * ray->y_len;
    }
    return EXIT_SUCCESS;
}
