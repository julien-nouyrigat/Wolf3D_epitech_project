/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** graphics
*/

#include "wolf.h"

static void change_resolution(window_t *win)
{
    (void)win;
}

void display_graphics(window_t *win)
{
    sfRenderWindow_drawText(win->window, win->graphics.title, NULL);
    for (size_t i = 0; i < NB_RESOLUTION; i++) {
        sfRenderWindow_drawText(win->window, win->graphics.tab[i].text, NULL);
    }
    change_resolution(win);
}
