/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** init_visor
*/

#include "wolf.h"

void init_visor(player_t **player, window_t *win)
{
    (*player)->visor = sfCircleShape_create();
    sfCircleShape_setRadius((*player)->visor, R_VISOR);
    sfCircleShape_setOrigin((*player)->visor,
        (sfVector2f){R_VISOR / 2, R_VISOR / 2});
    sfCircleShape_setFillColor((*player)->visor, VISOR_COLOR);
    sfCircleShape_setPosition((*player)->visor,
        (sfVector2f){win->size.x / 2, win->size.y / 2});
}
