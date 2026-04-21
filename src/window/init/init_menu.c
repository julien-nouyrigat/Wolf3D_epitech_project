/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** init_menu
*/

#include "window.h"
#include "wolf.h"

static void init_text_menu(window_t *win)
{
    win->menu.host = sfText_create();
    win->menu.join = sfText_create();
    win->menu.single = sfText_create();
    win->menu.settings = sfText_create();
    win->menu.quit = sfText_create();
    sfText_setString(win->menu.host, "HOST");
    sfText_setString(win->menu.join, "JOIN");
    sfText_setString(win->menu.single, "SINGLE");
    sfText_setString(win->menu.settings, "SETTINGS");
    sfText_setString(win->menu.quit, "QUIT");
}

int init_menu(window_t *win)
{
}