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
    {sfKeyNum1, &inv_one},
    {sfKeyNum2, &inv_two},
    {sfKeyNum3, &inv_three},
    {sfKeyTab, &display_minimap},
    {sfKeyUnknown, NULL}
};

static void manage_tabulation(player_t *player, window_t *win)
{
    if (win->event.type == sfEvtKeyReleased)
        if (win->event.key.code == sfKeyTab) {
            win->is_lamp = true;
            win->is_gun = true;
            player->mvt_speed = 3;
        }
}

void dead_menu(window_t *win, player_t *player, map_t *map)
{
    if (!player->new_game)
        return;
    if (win->event.type == sfEvtKeyPressed &&
        win->event.key.code == sfKeyA) {
        sfMusic_stop(win->footsteps);
        sfMusic_play(win->menu.music);
        win->is_single = false;
        win->is_menu = true;
        new_game(map, player);
        player->new_game = false;
    }
}

void manage_keyboard(player_t *player, map_t *map, window_t *win)
{
    if (win->event.type == sfEvtKeyPressed) {
        set_inv(win, player, map);
        dead_menu(win, player, map);
        if (sfKeyboard_isKeyPressed(sfKeyL))
            new_level(map, player);
        if (sfKeyboard_isKeyPressed(sfKeyE))
            grab_object(player, map);
    }
    for (size_t i = 0; keyboard_input[i].function != NULL; i++) {
        if (sfKeyboard_isKeyPressed(keyboard_input[i].code))
            keyboard_input[i].function(player, map, win);
    }
    manage_tabulation(player, win);
}
