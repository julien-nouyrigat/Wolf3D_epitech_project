/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** shoot
*/

#include <math.h>

#include "wolf.h"

static bool is_wall(map_t *map)
{
    if (map->int_map[map->map_pos.y][map->map_pos.x] == 1)
        return true;
    return false;
}

bool is_in_axis(window_t *win, monster_t *mob)
{
    if (win->size.x / 2 >= mob->hitbox.left &&
        win->size.x / 2 <= mob->hitbox.left + mob->hitbox.width &&
        win->size.y / 2 >= mob->hitbox.top &&
        win->size.y / 2 <= mob->hitbox.top + mob->hitbox.height)
        return true;
    return false;
}

static bool is_in_range(enemy_t *tmp, player_t *player)
{
    float dx = fabsf(tmp->monster->position.x - player->position.x);
    float dy = fabsf(tmp->monster->position.y - player->position.y);
    float dist = sqrt(dx * dx + dy * dy);

    if (dist <= (float)player->in_hand->stats->range)
        return true;
    return false;
}

static bool is_mob(map_t *map, window_t *win, player_t *player)
{
    enemy_t *tmp = map->level->enemies;

    for (; tmp != NULL; tmp = tmp->next) {
        if (is_in_axis(win, tmp->monster) && is_in_range(tmp, player) &&
            tmp->monster->health > 0) {
            tmp->monster->health -= player->in_hand->stats->damage;
            sfMusic_play(win->hurt_sound);
            return true;
        }
    }
    return false;
}

static void dda_loop(ray_t *ray, map_t *map,
    window_t __attribute_maybe_unused__ *win,
    player_t __attribute_maybe_unused__ *player)
{
    while (!is_wall(map)) {
        if (is_mob(map, win, player)) {
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
    bullet.direction.x = player->direction.x;
    bullet.direction.y = player->direction.y;
    init_dda(player, &bullet, map, win);
}

void shoot(window_t *win, player_t *player, map_t *map)
{
    verif_shoot(player, win, map);
    sfMusic_play(win->gun_sound);
}
