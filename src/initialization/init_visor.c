/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** init_visor
*/

#include "wolf.h"

void init_visor(player_t **player, window_t *win)
{
    (*player)->visor = sfText_create();
    sfText_setFont((*player)->visor, win->font);
    sfText_setString((*player)->visor, ".");
    sfText_setPosition((*player)->visor,
        (sfVector2f){win->size.x / 2 - 5, win->size.y / 2 - 25});
    sfText_setColor((*player)->visor, VISOR_COLOR);
    sfText_setScale((*player)->visor, (sfVector2f){2, 2});
}
