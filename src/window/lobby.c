/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** lobby
*/

#include "window.h"
#include "wolf.h"

void display_lobby(window_t *win)
{
    sfRenderWindow_drawText(win->window, win->lobby.lobby, NULL);
}
