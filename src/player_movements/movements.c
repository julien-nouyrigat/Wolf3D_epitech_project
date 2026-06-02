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

static void change_pos(map_t *map, player_t *player, sfFloatRect *mov_dir_verif,
    window_t *win)
{
    sfVector2f movement_dir = {mov_dir_verif->left, mov_dir_verif->top};
    sfVector2f verif = {mov_dir_verif->height, mov_dir_verif->width};
    sfVector2f norm = normalize(&movement_dir);

    if (map->int_map[(int)(player->position.y / TILE_SIZE)]
        [(int)verif.x] != WALL) {
        player->position.x += norm.x *
            (player->mvt_speed + SPRINT * player->sprint);
        player->pos_f.x = player->position.x / TILE_SIZE;
        player->is_moving = true;
    }
    if (map->int_map[(int)verif.y]
        [(int)(player->position.x / TILE_SIZE)] != WALL) {
        player->position.y += norm.y *
            (player->mvt_speed + SPRINT * player->sprint);
        player->pos_f.y = player->position.y / TILE_SIZE;
        player->is_moving = true;
    }
    if (win->is_game)
        send_position_to_serv(player, win);
}

static void move(player_t *player, map_t *map, sfVector2f *movement_dir,
    window_t *win)
{
    sfFloatRect mov_dir_verif;

    mov_dir_verif.height = get_verif(player->position.x, movement_dir->x,
        player);
    mov_dir_verif.width = get_verif(player->position.y, movement_dir->y,
        player);
    mov_dir_verif.left = movement_dir->x;
    mov_dir_verif.top = movement_dir->y;
    if (player->is_in_inv)
        return;
    player->bobing += BOBING_COEF * (player->sprint + 1);
    change_pos(map, player, &mov_dir_verif, win);
}

void move_forward(player_t *player, map_t *map, window_t *win)
{
    sfVector2f movement_dir = {0};

    movement_dir.x = player->direction.x;
    movement_dir.y = player->direction.y;
    move(player, map, &movement_dir, win);
}

void move_backward(player_t *player, map_t *map, window_t *win)
{
    sfVector2f movement_dir = {0};

    movement_dir.x = - player->direction.x;
    movement_dir.y = - player->direction.y;
    move(player, map, &movement_dir, win);
}

void move_right(player_t *player, map_t *map, window_t *win)
{
    sfVector2f movement_dir = {0};

    movement_dir.x = player->direction.y;
    movement_dir.y = - player->direction.x;
    move(player, map, &movement_dir, win);
}

void move_left(player_t *player, map_t *map, window_t *win)
{
    sfVector2f movement_dir = {0};

    movement_dir.x = - player->direction.y;
    movement_dir.y = player->direction.x;
    move(player, map, &movement_dir, win);
}
