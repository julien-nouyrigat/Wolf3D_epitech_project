/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** init_player
*/

#include <stdlib.h>
#include <math.h>

#include "wolf.h"

static void set_hitbox(player_t *player)
{
    sfVector2f origin = (sfVector2f){PLAYER_SIZE / 2, PLAYER_SIZE / 2};
    sfVector2f size = (sfVector2f){PLAYER_SIZE, PLAYER_SIZE};
    sfVector2f position = (sfVector2f){(player)->pos_x, (player)->pos_y};
    sfColor p_color = sfColor_fromRGB(255, 255, 0);

    (player)->hitbox = sfRectangleShape_create();
    sfRectangleShape_setOrigin((player)->hitbox, origin);
    sfRectangleShape_setSize((player)->hitbox, size);
    sfRectangleShape_setPosition((player)->hitbox, position);
    sfRectangleShape_setFillColor((player)->hitbox, p_color);
}

int init_player(player_t **player)
{
    *player = malloc(sizeof(player_t) * MAXLOG);
    if (!*player)
        return EXIT_FAILURE;
    for (int i = 0; i < MAXLOG; i++) {
        (*player)->pos_x = 4 * TILE_SIZE;
        (*player)->pos_y = 4 * TILE_SIZE;
        (*player)->angle = 0;
        set_hitbox(&(*player)[i]);
        (*player)->delta_x = cos((*player)->angle) * 5;
        (*player)->delta_y = sin((*player)->angle) * 5;
    }
    return EXIT_SUCCESS;
}
