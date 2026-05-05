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
    {sfKeyC, &sprint},
    {sfKeyUnknown, NULL}
};

void manage_keyboard(player_t *player, map_t *map)
{
    for (size_t i = 0; keyboard_input[i].function != NULL; i++) {
        if (sfKeyboard_isKeyPressed(keyboard_input[i].code))
            keyboard_input[i].function(player, map);
    }
}
