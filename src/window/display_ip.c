/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** display_ip
*/

#include "wolf.h"

void display_ip(window_t *win_wolf)
{
    sfRenderWindow_drawRectangleShape(win_wolf->window, win_wolf->ip->rect,
        NULL);
    sfText_setString(win_wolf->ip->text, win_wolf->ip->ip);
    sfRenderWindow_drawText(win_wolf->window, win_wolf->ip->text, NULL);
}
