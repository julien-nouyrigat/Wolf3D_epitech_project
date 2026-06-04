/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** init_lamp
*/

#include "wolf.h"

void init_lamp(window_t *win)
{
    sfVector2u size;

    win->game.lamp = sfSprite_create();
    win->game.t_lamp = sfTexture_createFromFile("./assets/image/lamp.png",
        NULL);
    sfSprite_setTexture(win->game.lamp, win->game.t_lamp, sfTrue);
    sfSprite_setScale(win->game.lamp, (sfVector2f){1, 1});
    win->game.dark = sfSprite_create();
    win->game.t_dark = sfTexture_createFromFile("./assets/image/dl.png",
        NULL);
    sfSprite_setTexture(win->game.dark, win->game.t_dark, sfTrue);
    size = sfTexture_getSize(win->game.t_dark);
    sfSprite_setOrigin(win->game.dark, (sfVector2f){size.x / 2, size.y / 2});
    sfSprite_setPosition(win->game.dark, (sfVector2f){win->size.x / 2, win->size.y / 2});
    win->game.light_of = sfSprite_create();
    win->game.t_light_of =
        sfTexture_createFromFile("./assets/image/behind_inv.png", NULL);
    sfSprite_setTexture(win->game.light_of, win->game.t_light_of, sfTrue);
    sfSprite_setScale(win->game.light_of, (sfVector2f){6, 6});
}
