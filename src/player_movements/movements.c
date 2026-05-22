/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** movements
*/

#include <math.h>

#include "wolf.h"

static int get_verif(float pos, float dir, player_t *player)
{
    int res = (int)((pos + dir * (player->mvt_speed +
                SPRINT * player->sprint + PLAYER_SIZE / 2)) / TILE_SIZE);

    return res;
}

static sfVector2f normalize(sfVector2f *vector)
{
    float len = sqrtf(vector->x * vector->x + vector->y * vector->y);
    sfVector2f norm;

    if (len == 0.0f)
        norm = (sfVector2f){0.f, 0.f};
    else
        norm = (sfVector2f){vector->x / len, vector->y / len};
    return norm;
}

static void change_pos(map_t *map, player_t *player,
    sfVector2f *movement_dir, sfVector2f *verif)
{
    sfVector2f norm = normalize(movement_dir);

    if (map->int_map[(int)(player->position.y / TILE_SIZE)]
        [(int)verif->x] != WALL) {
        player->position.x += norm.x *
            (player->mvt_speed + SPRINT * player->sprint);
        player->pos_f.x = player->position.x / TILE_SIZE;
        player->is_moving = true;
    }
    if (map->int_map[(int)verif->y]
        [(int)(player->position.x / TILE_SIZE)] != WALL) {
        player->position.y += norm.y *
            (player->mvt_speed + SPRINT * player->sprint);
        player->pos_f.y = player->position.y / TILE_SIZE;
        player->is_moving = true;
    }
}

static void move(player_t *player, map_t *map, sfVector2f *movement_dir)
{
    sfVector2f verif = {0, 0};

    verif.x = get_verif(player->position.x, movement_dir->x, player);
    verif.y = get_verif(player->position.y, movement_dir->y, player);
    if (player->is_in_inv)
        return;
    player->bobing += BOBING_COEF * (player->sprint + 1);
    change_pos(map, player, movement_dir, &verif);
}

void move_forward(player_t *player, map_t *map)
{
    sfVector2f movement_dir = {0};

    movement_dir.x = player->direction.x;
    movement_dir.y = player->direction.y;
    move(player, map, &movement_dir);
}

void move_backward(player_t *player, map_t *map)
{
    sfVector2f movement_dir = {0};

    movement_dir.x = - player->direction.x;
    movement_dir.y = - player->direction.y;
    move(player, map, &movement_dir);
}

void move_right(player_t *player, map_t *map)
{
    sfVector2f movement_dir = {0};

    movement_dir.x = player->direction.y;
    movement_dir.y = - player->direction.x;
    move(player, map, &movement_dir);
}

void move_left(player_t *player, map_t *map)
{
    sfVector2f movement_dir = {0};

    movement_dir.x = - player->direction.y;
    movement_dir.y = player->direction.x;
    move(player, map, &movement_dir);
}
