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

static void change_pos(map_t *map, player_t *player,
    sfVector2f *movement_dir, sfVector2f *verif)
{
    if (map->int_map[(int)(player->position.y / TILE_SIZE)]
        [(int)verif->x] != WALL) {
        player->position.x += movement_dir->x *
            (player->mvt_speed + SPRINT * player->sprint);
        player->pos_f.x = player->position.x / TILE_SIZE;
        player->is_moving = true;
    }
    if (map->int_map[(int)verif->y]
        [(int)(player->position.x / TILE_SIZE)] != WALL) {
        player->position.y += movement_dir->y *
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

    movement_dir.x = player->direction.x * ((player->mvt_speed) / (3 * M_PI));
    movement_dir.y = player->direction.y * ((player->mvt_speed) / (3 * M_PI));
    move(player, map, &movement_dir);
}

void move_backward(player_t *player, map_t *map)
{
    sfVector2f movement_dir = {0};

    movement_dir.x = - player->direction.x * ((player->mvt_speed) / (3 * M_PI));
    movement_dir.y = - player->direction.y * ((player->mvt_speed) / (3 * M_PI));
    move(player, map, &movement_dir);
}

void move_right(player_t *player, map_t *map)
{
    sfVector2f movement_dir = {0};

    movement_dir.x = - player->direction.y * sin((player->mvt_speed));
    movement_dir.y = - player->direction.x * cos((player->mvt_speed));
    move(player, map, &movement_dir);
}

void move_left(player_t *player, map_t *map)
{
    sfVector2f movement_dir = {0};

    movement_dir.x = player->direction.y * sin((player->mvt_speed));
    movement_dir.y = player->direction.x * cos((player->mvt_speed));
    move(player, map, &movement_dir);
}
