/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** manage_keyboard
*/

#include <stddef.h>

#include "input.h"
#include "wolf.h"

const struct keyboard_fpt_s keyboard_input [] = {
    {sfKeyZ, &move_forward},
    {sfKeyS, &move_backward},
    {sfKeyQ, &move_left},
    {sfKeyD, &move_right},
    {sfKeyLeft, &rotate_left},
    {sfKeyRight, &rotate_right},
    {sfKeyUp, &up_cam},
    {sfKeyDown, &down_cam},
    {sfKeyLShift, &sprint},
    {sfKeyUnknown, NULL}
};

void manage_keyboard(player_t *player, map_t *map, window_t *win)
{
    if (win->event.type == sfEvtMouseButtonPressed)
        if (sfMouse_isButtonPressed(sfMouseLeft) && !win->is_menu)
            win->game.shoot = true;
    if (win->event.type == sfEvtKeyPressed)
        set_inv(player, map);
    for (size_t i = 0; keyboard_input[i].function != NULL; i++) {
        if (sfKeyboard_isKeyPressed(keyboard_input[i].code))
            keyboard_input[i].function(player, map);
    }
}
