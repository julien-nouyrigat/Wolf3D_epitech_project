/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** manage_controller
*/

#include <math.h>

#include "wolf.h"

static void check_movements(player_t *player, map_t *map, window_t *win,
    sfVector2f *joystick0)
{
    if (fabsf(joystick0->x) > DEAD_ZONE) {
        if (joystick0->x > 0)
            move_right(player, map, win);
        else
            move_left(player, map, win);
    }
    if (fabsf(joystick0->y) > DEAD_ZONE) {
        if (joystick0->y > 0)
            move_backward(player, map, win);
        else
            move_forward(player, map, win);
    }
}

void manage_controller(player_t *player, map_t *map, window_t *win)
{
    sfVector2f joystick0 = {0};

    if (win->event.type == sfEvtJoystickDisconnected ||
        !sfJoystick_isConnected(0))
        return;
    joystick0.x = sfJoystick_getAxisPosition(0, sfJoystickX);
    joystick0.y = sfJoystick_getAxisPosition(0, sfJoystickY);
    check_movements(player, map, win, &joystick0);
}
