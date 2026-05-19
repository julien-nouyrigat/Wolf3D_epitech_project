/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** movements
*/

#include <math.h>

#include "wolf.h"

static void move(player_t *player, map_t *map, sfVector2f *movement_dir)
{
    int x_verif =
        (int)((player->position.x + movement_dir->x * (player->mvt_speed +
                SPRINT * player->sprint + PLAYER_SIZE / 2)) / TILE_SIZE);
    int y_verif =
        (int)((player->position.y + movement_dir->y * (player->mvt_speed +
                SPRINT * player->sprint + PLAYER_SIZE / 2)) / TILE_SIZE);

    if (map->int_map[(int)(player->position.y / TILE_SIZE)][x_verif] != WALL) {
        player->position.x += movement_dir->x *
            (player->mvt_speed + SPRINT * player->sprint);
        player->pos_f.x = player->position.x / TILE_SIZE;
        player->is_moving = true;
    }
    if (map->int_map[y_verif][(int)(player->position.x / TILE_SIZE)] != WALL) {
        player->position.y += movement_dir->y *
            (player->mvt_speed + SPRINT * player->sprint);
        player->pos_f.y = player->position.y / TILE_SIZE;
        player->is_moving = true;
    }
}

void move_forward(player_t *player, map_t *map)
{
    sfVector2f movement_dir = {0};

    player->bobing += 0.3f;
    movement_dir.x = player->direction.x * ((player->mvt_speed) / (3 * M_PI));
    movement_dir.y = player->direction.y * ((player->mvt_speed) / (3 * M_PI));
    move(player, map, &movement_dir);
}

void move_backward(player_t *player, map_t *map)
{
    sfVector2f movement_dir = {0};

    player->bobing += 0.3f;
    movement_dir.x = - player->direction.x * ((player->mvt_speed) / (3 * M_PI));
    movement_dir.y = - player->direction.y * ((player->mvt_speed) / (3 * M_PI));
    move(player, map, &movement_dir);
}

void move_right(player_t *player, map_t *map)
{
    sfVector2f movement_dir = {0};

    player->bobing += 0.3f;
    movement_dir.x = - player->direction.y * sin((player->mvt_speed));
    movement_dir.y = - player->direction.x * cos((player->mvt_speed));
    move(player, map, &movement_dir);
}

void move_left(player_t *player, map_t *map)
{
    sfVector2f movement_dir = {0};

    player->bobing += 0.3f;
    movement_dir.x = player->direction.y * sin((player->mvt_speed));
    movement_dir.y = player->direction.x * cos((player->mvt_speed));
    move(player, map, &movement_dir);
}
