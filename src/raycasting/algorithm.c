/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** algorithm
*/

#include <math.h>
#include <stdlib.h>

#include "wolf.h"

static void project_wall(ray_t *ray, window_t *win, map_t *map,
    player_t *player)
{
    sfColor wall_color = {0};
    float fog_value = 0;

    if (ray->orientation == VERTICAL) {
        ray->real_dist = ray->side_dist.x - ray->delta_dist.x;
        fog_value = LIGHT / (1 + ray->real_dist * FOG);
        wall_color = sfColor_fromRGB(fog_value, fog_value, fog_value);
    } else {
        ray->real_dist = ray->side_dist.y - ray->delta_dist.y;
        fog_value = SHADOW / (1 + ray->real_dist * FOG);
        wall_color = sfColor_fromRGB(fog_value, fog_value, fog_value);
    }
    ray->color = wall_color;
    player->z_buffer[ray->screen_x] = ray->real_dist;
    draw_wall(ray, win, map, player);
}

static bool is_wall(map_t *map)
{
    if (map->int_map[map->map_pos.y][map->map_pos.x] == 1)
        return true;
    return false;
}

static void dda_loop(ray_t *ray, map_t *map, window_t *win, player_t *player)
{
    while (!is_wall(map)) {
        if (ray->side_dist.x < ray->side_dist.y) {
            ray->side_dist.x += ray->delta_dist.x;
            map->map_pos.x += ray->step.x;
            ray->orientation = VERTICAL;
        } else {
            ray->side_dist.y += ray->delta_dist.y;
            map->map_pos.y += ray->step.y;
            ray->orientation = HORIZONTAL;
        }
    }
    project_wall(ray, win, map, player);
}

static void init_raycasting(ray_t *ray, player_t *player, map_t *map)
{
    if (ray->direction.x < 0) {
        ray->step.x = -1;
        ray->side_dist.x = (player->pos_f.x - map->map_pos.x) *
            ray->delta_dist.x;
    } else {
        ray->step.x = 1;
        ray->side_dist.x = (map->map_pos.x + 1 - player->pos_f.x) *
            ray->delta_dist.x;
    }
    if (ray->direction.y < 0) {
        ray->step.y = -1;
        ray->side_dist.y = (player->pos_f.y - map->map_pos.y) *
            ray->delta_dist.y;
    } else {
        ray->step.y = 1;
        ray->side_dist.y = (map->map_pos.y + 1 - player->pos_f.y) *
            ray->delta_dist.y;
    }
}

static void init_dda(player_t *player, ray_t *ray, map_t *map, window_t *win)
{
    map->map_pos = (sfVector2i){(int)(player->pos_f.x),
        (int)(player->pos_f.y)};
    ray->delta_dist.x =
        (ray->direction.x == 0) ? ZERO_INV : fabsf(1 / ray->direction.x);
    ray->delta_dist.y =
        (ray->direction.y == 0) ? ZERO_INV : fabsf(1 / ray->direction.y);
    init_raycasting(ray, player, map);
    dda_loop(ray, map, win, player);
}

void dda_algorithm(player_t *player, map_t *map, window_t *win)
{
    ray_t ray = {0};

    player->z_buffer = calloc(sizeof(float), win->size.x);
    if (player->z_buffer == NULL)
        return;
    draw_floor(&ray, win, map, player);
    for (float screen_col = 0.0; screen_col < win->size.x; screen_col += 1.0) {
        player->camera.x = (2 * screen_col / (win->size.x - 1) - 1);
        ray.screen_x = screen_col;
        ray.direction.x = player->direction.x + player->camera_plane.x *
            player->camera.x;
        ray.direction.y = player->direction.y + player->camera_plane.y *
            player->camera.x;
        init_dda(player, &ray, map, win);
        //display_enemies(player, map, win, ray);
    }
    display_enemies(player, map, win);
    free(player->z_buffer);
}
