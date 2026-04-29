/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** create_hud
*/

#include "wolf.h"

void create_hud(window_t *win)
{
    win->hud.life = sfText_create();
    win->hud.max_life = sfText_create();
    win->hud.stamina = sfText_create();
    win->hud.max_stamina = sfText_create();
    sfText_setFont(win->hud.life, win->font);
    sfText_setFont(win->hud.max_life, win->font);
    sfText_setFont(win->hud.stamina, win->font);
    sfText_setFont(win->hud.max_stamina, win->font);
    sfText_setColor(win->hud.life, sfColor_fromRGB(82, 252, 123));
    sfText_setColor(win->hud.max_life, sfColor_fromRGB(82, 252, 123));
    sfText_setColor(win->hud.stamina, sfColor_fromRGB(234, 255, 33));
    sfText_setColor(win->hud.max_stamina, sfColor_fromRGB(234, 255, 33));
}
