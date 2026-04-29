/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** display_hud
*/

#include "wolf.h"

void display_hud(window_t *win, player_t *player)
{
    sfText_setString(win->hud.life, my_itoa(player->life));
    sfText_setString(win->hud.max_life, my_itoa(player->max_life));
    sfText_setString(win->hud.stamina, my_itoa(player->stamina));
    sfText_setString(win->hud.max_stamina, my_itoa(player->max_stamina));
    sfRenderWindow_drawText(win->window, win->hud.life, NULL);
    sfRenderWindow_drawText(win->window, win->hud.max_life, NULL);
    sfRenderWindow_drawText(win->window, win->hud.stamina, NULL);
    sfRenderWindow_drawText(win->window, win->hud.max_stamina, NULL);
}
