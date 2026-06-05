/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** manage_controller
*/

#include <math.h>

#include "input.h"
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

const struct joystick_fpt_s joystick_input [] = {
    {11, &sprint},
    {3, &inv_one},
    {0, &inv_two},
    {1, &inv_three},
    {4, &display_minimap},
    {-1, NULL}
};
static void check_buttons(player_t *player, map_t *map, window_t *win)
{
    for (size_t i = 0; joystick_input[i].function != NULL; i++) {
        if (sfJoystick_isButtonPressed(0, joystick_input[i].code))
            joystick_input[i].function(player, map, win);
    }
    if (sfJoystick_isButtonPressed(0, 2))
        grab_object(player, map);
    if (sfJoystick_isButtonPressed(0, 7) && can_shoot(player)) {
        player->shoots = true;
        sfClock_restart(player->in_hand->animation);
        shoot_weapon(win, player, map);
        sfClock_restart(player->in_hand->w_clock);
    }
}

void check_joystick_arrows(player_t *player, map_t *map,
    window_t __attribute_maybe_unused__ *win)
{
    float pov_x = sfJoystick_getAxisPosition(0, sfJoystickPovX);
    float pov_y = sfJoystick_getAxisPosition(0, sfJoystickPovY);

    if (pov_x < 0)
        inv_inf(player, map);
    if (pov_x > 0)
        inv_sup(player, map);
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
    check_buttons(player, map, win);
}
