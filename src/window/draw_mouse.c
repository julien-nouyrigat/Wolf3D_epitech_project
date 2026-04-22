/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** draw_mouse
*/

#include "wolf.h"

void display_cursor(window_t *win)
{
    sfVector2i pos_mouse = sfMouse_getPositionRenderWindow(win->window);
    sfVector2f pos;

    pos.x = pos_mouse.x;
    pos.y = pos_mouse.y;
    sfRenderWindow_drawSprite(win->window, win->menu.s_mouse, NULL);
    sfSprite_setPosition(win->menu.s_mouse, pos);
}
