/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** algorithm
*/

#include <math.h>

#include "wolf.h"

static void project_wall(ray_t *ray, window_t *win)
{
    if (ray->orientation == VERTICAL)
        ray->real_dist = ray->side_dist.x - ray->delta_dist.x;
    else
        ray->real_dist = ray->side_dist.y - ray->delta_dist.y;
    draw_wall(ray, win);
}

static bool is_wall(sfVector2i *map_pos, map_t *map)
{
    if (map->int_map[map_pos->x][map_pos->y] == 1)
        return true;
    return false;
}

static void dda_loop(ray_t *ray, sfVector2i *map_pos, map_t *map, window_t *win)
{
    while (!is_wall(map_pos, map)) {
        if (ray->side_dist.x < ray->side_dist.y) {
            ray->side_dist.x += ray->delta_dist.x;
            map_pos->x += ray->step.x;
            ray->orientation = VERTICAL;
        } else {
            ray->side_dist.y += ray->delta_dist.y;
            map_pos->y += ray->step.y;
            ray->orientation = HORIZONTAL;
        }
    }
    project_wall(ray, win);
}

static void init_raycasting(ray_t *ray, player_t *player, sfVector2i *map_pos)
{
    if (ray->direction.x < 0) {
        ray->step.x = -1;
        ray->side_dist.x = (player->position.x - map_pos->x) *
            ray->delta_dist.x;
    } else {
        ray->step.x = 1;
        ray->side_dist.x = (map_pos->x + 1 - player->position.x) *
            ray->delta_dist.x;
    }
    if (ray->direction.y < 0) {
        ray->step.y = -1;
        ray->side_dist.y = (player->position.y - map_pos->y) *
            ray->delta_dist.y;
    } else {
        ray->step.y = 1;
        ray->side_dist.y = (map_pos->y + 1 - player->position.y) *
            ray->delta_dist.y;
    }
}

static void init_dda(player_t *player, ray_t *ray, map_t *map, window_t *win)
{
    sfVector2i map_pos = (sfVector2i){(int)(player->position.x / TILE_SIZE),
        (int)(player->position.y / TILE_SIZE)};

    ray->delta_dist.x =
        (ray->direction.x == 0) ? ZERO_INV : fabsf(1 / ray->direction.x);
    ray->delta_dist.y =
        (ray->direction.y == 0) ? ZERO_INV : fabsf(1 / ray->direction.y);
    init_raycasting(ray, player, &map_pos);
    dda_loop(ray, &map_pos, map, win);
}

void dda_algorithm(player_t *player, map_t *map, window_t *win)
{
    ray_t ray = {0};

    for (size_t screen_col = 0; screen_col < WIN_WIDTH; screen_col++) {
        player->camera.x = 2 * screen_col / WIN_WIDTH - 1;
        ray.screen_x = screen_col;
        ray.direction.x = player->direction.x + player->camera_plane.x *
            player->camera.x;
        ray.direction.y = player->direction.y + player->camera_plane.y *
            player->camera.x;
        init_dda(player, &ray, map, win);
    }
}
