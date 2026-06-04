/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** draw_lamp
*/

#include "wolf.h"

void display_lamp(window_t *win, player_t *player)
{
    sfVector2f pos_light_of = {-240, -100};
    sfVector2f pos_lamp = {90, 676};

    if (!player->is_in_inv){
        sfRenderWindow_drawSprite(win->window, win->game.dark, NULL);
    } else {
        sfSprite_setPosition(win->game.light_of, pos_light_of);
        sfRenderWindow_drawSprite(win->window, win->game.light_of, NULL);
    }
    if (player->life != 0){
        sfSprite_setPosition(win->game.lamp, pos_lamp);
        sfRenderWindow_drawSprite(win->window, win->game.lamp, NULL);
    }
}
