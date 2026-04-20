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
    {sfKeyZ, &moove_forward},
    {sfKeyQ, &rotate_left},
    {sfKeyS, &moove_backward},
    {sfKeyD, &rotate_right},
    {sfKeyUnknown, NULL}
};

void manage_keyboard(sfEvent *event, player_t *player, map_t *map)
{
    for (size_t i = 0; keyboard_input[i].function != NULL; i++) {
        if (event->key.code == keyboard_input[i].code)
            keyboard_input[i].function(player, map);
    }
}
