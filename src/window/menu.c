/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** menu
*/

#include "wolf.h"

void display_menu(window_t *win)
{
    display_background_menu(win);
    sfRenderWindow_drawSprite(win->window, win->menu.s_title, NULL);
    sfRenderWindow_drawText(win->window, win->menu.host, NULL);
    sfRenderWindow_drawText(win->window, win->menu.join, NULL);
    sfRenderWindow_drawText(win->window, win->menu.single, NULL);
    sfRenderWindow_drawText(win->window, win->menu.settings, NULL);
    sfRenderWindow_drawText(win->window, win->menu.quit, NULL);
}
