/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** manage_controller
*/

#include <math.h>

#include "wolf.h"

static void check_movements(player_t *player, map_t *map, window_t *win,
    sfVector2f *joystickL)
{
    if (fabsf(joystickL->x) > DEAD_ZONE) {
        if (joystickL->x > 0)
            move_right(player, map, win);
        else
            move_left(player, map, win);
    }
    if (fabsf(joystickL->y) > DEAD_ZONE) {
        if (joystickL->y > 0)
            move_backward(player, map, win);
        else
            move_forward(player, map, win);
    }
}

static void check_rotation(player_t *player, map_t *map, window_t *win,
    sfVector2f *joystickD)
{
    if (fabsf(joystickD->x) > DEAD_ZONE) {
        if (joystickD->x > 0)
            rotate_right(player, map, win);
        else
            rotate_left(player, map, win);
    }
    if (fabsf(joystickD->y) > DEAD_ZONE) {
        if (joystickD->y > 0)
            down_cam(player, map, win);
        else
            up_cam(player, map, win);
    }
}

void manage_controller(player_t *player, map_t *map, window_t *win)
{
    sfVector2f joystickL = {0};
    sfVector2f joystickR = {0};

    if (win->event.type == sfEvtJoystickDisconnected ||
        !sfJoystick_isConnected(0))
        return;
    joystickL.x = sfJoystick_getAxisPosition(0, sfJoystickX);
    joystickL.y = sfJoystick_getAxisPosition(0, sfJoystickY);
    joystickR.x = sfJoystick_getAxisPosition(0, sfJoystickU);
    joystickR.y = sfJoystick_getAxisPosition(0, sfJoystickV);
    check_movements(player, map, win, &joystickL);
    check_rotation(player, map, win, &joystickR);
}
