/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** sprint
*/

#include "wolf.h"

void sprint(player_t *player, __attribute_maybe_unused__ map_t *map)
{
    if (player->stamina > 0) {
        player->sprint = true;
    } else {
        player->sprint = false;
    }
}

void stop_sprint(window_t *win, player_t *player,
    __attribute_maybe_unused__ map_t *map)
{
    if (win->event.key.code == sfKeyC) {
        player->sprint = false;
    }
}
