/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** draw_lamp
*/

#include "wolf.h"

void display_lamp(window_t *win)
{
    sfVector2f pos_lamp = {150, 676};
    sfVector2f pos_dark = {-200, -600};

    sfRenderWindow_drawSprite(win->window, win->game.lamp, NULL);
    sfSprite_setPosition(win->game.lamp, pos_lamp);
    sfRenderWindow_drawSprite(win->window, win->game.dark, NULL);
    sfSprite_setPosition(win->game.dark, pos_dark);
}
