/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** sprint
*/

#include "wolf.h"

void sprint(player_t *player, __attribute_maybe_unused__ map_t *map,
    __attribute_maybe_unused__ window_t *win)
{
    sfTime time;
    float sec = 0;

    time = sfClock_getElapsedTime(player->p_clock);
    sec = time.microseconds / SECOND;
    if (player->stamina > 0) {
        player->sprint = true;
        if (sec >= 0.25f && player->stamina > 0 && player->is_moving) {
            player->stamina -= 1;
            sfClock_restart(player->p_clock);
        }
    } else {
        player->sprint = false;
    }
}

void stop_sprint(window_t *win, player_t *player,
    __attribute_maybe_unused__ map_t *map)
{
    if (win->event.key.code == sfKeyLShift ||
        win->event.joystickButton.button == 11) {
        player->sprint = false;
    }
}
