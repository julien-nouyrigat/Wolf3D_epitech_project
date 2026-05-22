/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** shoot
*/

#include "wolf.h"

static bool is_wall(map_t *map)
{
    if (map->int_map[map->map_pos.y][map->map_pos.x] == 1)
        return true;
    return false;
}

static bool shoot_mob(enemy_t *tmp, window_t *win)
{
    sfTime time = sfClock_getElapsedTime(win->clock.gun_clock);
    float sec = time.microseconds / SECOND;

    if (sec >= GUN_COOLDOWN) {
        tmp->monster->health -= GUN_DAMAGE;
        sfClock_restart(win->clock.gun_clock);
        return true;
    }
    return false;
}

static bool is_mob(map_t *map, window_t *win)
{
    enemy_t *tmp = map->level->enemies;

    for (; tmp != NULL; tmp = tmp->next) {
        if (map->map_pos.x >= ((int)tmp->monster->position.x / TILE_SIZE) - 1 &&
            map->map_pos.x <= ((int)tmp->monster->position.x / TILE_SIZE) + 1 &&
            map->map_pos.y >= ((int)tmp->monster->position.y / TILE_SIZE) - 1 &&
            map->map_pos.y <= ((int)tmp->monster->position.y / TILE_SIZE) + 1) {
            return shoot_mob(tmp, win);
        }
    }
    return false;
}

static void dda_loop(ray_t *ray, map_t *map,
    window_t __attribute_maybe_unused__ *win,
    player_t __attribute_maybe_unused__ *player)
{
    while (!is_wall(map)) {
        if (is_mob(map, win)) {
            return;
        }
        if (ray->side_dist.x < ray->side_dist.y) {
            ray->side_dist.x += ray->delta_dist.x;
            map->map_pos.x += ray->step.x;
        } else {
            ray->side_dist.y += ray->delta_dist.y;
            map->map_pos.y += ray->step.y;
        }
    }
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

static void verif_shoot(player_t *player, window_t *win, map_t *map)
{
    ray_t bullet = {0};

    bullet.screen_x = win->size.x / 2;
    bullet.direction.x = player->direction.x + player->camera_plane.x *
        player->camera.x;
    bullet.direction.y = player->direction.y + player->camera_plane.y *
        player->camera.x;
    init_dda(player, &bullet, map, win);
}

void shoot(window_t *win, player_t *player, map_t *map)
{
    verif_shoot(player, win, map);
    sfMusic_play(win->gun_sound);
}
