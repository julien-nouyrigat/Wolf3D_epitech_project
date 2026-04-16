/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** ray_calculation
*/

#include <math.h>
#include <stdlib.h>

#include "wolf.h"

static void find_true_distance(ray_t *ray, player_t *player)
{
    if (ray->wall_face == VERTICAL)
        ray->dist = ray->x_dist - ray->x_len;
    else
        ray->dist = ray->y_dist - ray->y_len;
    ray->dist *= cos(player->angle - ray->angle);
}

static bool is_wall(map_t *map, int map_x, int map_y)
{
    if (map->int_map[map_x][map_y] == 1)
        return true;
    return false;
}

static void dda_loop(map_t *map, ray_t *ray, sfVector2i *map_pos,
    player_t *player)
{
    while (!is_wall(map, map_pos->x, map_pos->y)) {
        if (ray->x_dist < ray->y_dist) {
            ray->x_dist += ray->x_len;
            map_pos->x += ray->x_step;
            ray->wall_face = VERTICAL;
        } else {
            ray->y_dist += ray->y_len;
            map_pos->y += ray->y_step;
            ray->wall_face = HORIZONTAL;
        }
    }
    find_true_distance(ray, player);
}

static void init_dda(player_t *player, ray_t *ray, sfVector2i *map_pos)
{
    if (cos(ray->angle) < 0)
        ray->x_step = -1;
    else
        ray->x_step = 1;
    if (sin(ray->angle) < 0)
        ray->y_step = -1;
    else
        ray->y_step = 1;
    if (ray->x_step == -1)
        ray->x_dist = (player->pos_y / TILE_SIZE - map_pos->x) * ray->x_len;
    else {
        ray->x_dist = (map_pos->x + 1 - (player->pos_y / TILE_SIZE))
            * ray->x_len;
    }
    if (ray->y_step == -1)
        ray->y_dist = (player->pos_x / TILE_SIZE - map_pos->y) * ray->y_len;
    else {
        ray->y_dist = (map_pos->y + 1 - (player->pos_x / TILE_SIZE))
            * ray->y_len;
    }
}

int ray_calculation(map_t *map, player_t *player)
{
    ray_t *ray = malloc(sizeof(ray_t));
    float pov = (M_PI / 3) / WIN_WIDTH;
    sfVector2i map_pos = (sfVector2i)
    {(int)player->pos_x / TILE_SIZE, (int)player->pos_y / TILE_SIZE};

    if (!ray)
        return EXIT_FAILURE;
    init_ray(ray);
    for (ray->angle = player->angle - (M_PI / 6);
        ray->angle <= player->angle + (M_PI / 6); ray->angle += pov) {
        ray->x_len = fabs(1 / cos(ray->angle));
        ray->y_len = fabs(1 / sin(ray->angle));
        init_dda(player, ray, &map_pos);
        dda_loop(map, ray, &map_pos, player);
    }
    return EXIT_SUCCESS;
}
