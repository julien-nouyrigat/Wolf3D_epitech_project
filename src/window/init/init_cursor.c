/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** init_cursor
*/

#include "wolf.h"

void init_cursor(window_t *win)
{
    win->menu.s_mouse = sfSprite_create();
    win->menu.t_mouse = sfTexture_createFromFile("./assets/image/cursor.png",
        NULL);
    sfSprite_setTexture(win->menu.s_mouse, win->menu.t_mouse, sfTrue);
    sfSprite_setScale(win->menu.s_mouse, (sfVector2f){0.6, 0.6});
}
