/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** manage_keyboard
*/

#include <stddef.h>

#include "input.h"
#include "client.h"
#include "server.h"
#include "wolf.h"

const struct keyboard_fpt_s keyboard_input [] = {
    {sfKeyZ, MOVE_Z},
    {sfKeyQ, MOVE_Q},
    {sfKeyS, MOVE_S},
    {sfKeyD, MOVE_D},
    {sfKeyUnknown, -1}
};

bool manage_keyboard(sfEvent *event, input_enum_t *input)
{
    for (int i = 0; (int)keyboard_input[i].input != -1; i++) {
        if (event->key.code == keyboard_input[i].code) {
            *input = keyboard_input[i].input;
            return true;
        }
    }
    return false;
}
