/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** manage_hand_inventory
*/

#include <stdlib.h>

#include "wolf.h"

void inv_three(player_t *player, map_t __attribute_maybe_unused__ *map,
    __attribute_maybe_unused__ window_t *win)
{
    player->cursor = 2;
}

void inv_two(player_t *player, map_t __attribute_maybe_unused__ *map,
    __attribute_maybe_unused__ window_t *win)
{
    player->cursor = 1;
}

void inv_one(player_t *player, map_t __attribute_maybe_unused__ *map,
    __attribute_maybe_unused__ window_t *win)
{
    player->cursor = 0;
}

void inv_inf(player_t *player, map_t __attribute_maybe_unused__ *map)
{
    player->cursor = (abs(player->cursor - 1 + 3)) % 3;
}

void inv_sup(player_t *player, map_t __attribute_maybe_unused__ *map)
{
    player->cursor = (abs(player->cursor + 1)) % 3;
}
