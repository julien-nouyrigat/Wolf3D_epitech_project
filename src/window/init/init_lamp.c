/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** init_lamp
*/

#include "wolf.h"

void init_lamp(window_t *win)
{
    win->game.lamp = sfSprite_create();
    win->game.t_lamp = sfTexture_createFromFile("./assets/image/lamp.png",
        NULL);
    sfSprite_setTexture(win->game.lamp, win->game.t_lamp, sfTrue);
    sfSprite_setScale(win->game.lamp, (sfVector2f){1, 1});
    win->game.dark = sfSprite_create();
    win->game.t_dark = sfTexture_createFromFile("./assets/image/dl.png",
        NULL);
    sfSprite_setTexture(win->game.dark, win->game.t_dark, sfTrue);
    sfSprite_setScale(win->game.dark, (sfVector2f){1.3, 1.3});
}
