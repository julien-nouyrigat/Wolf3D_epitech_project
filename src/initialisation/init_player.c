/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** init_player
*/

#include <stdlib.h>
#include <math.h>

#include "wolf.h"

static void set_hitbox(player_t **player)
{
    sfVector2f origin = (sfVector2f){PLAYER_SIZE / 2, PLAYER_SIZE / 2};
    sfVector2f size = (sfVector2f){PLAYER_SIZE, PLAYER_SIZE};
    sfColor p_color = sfColor_fromRGB(255, 255, 0);

    (*player)->hitbox = sfRectangleShape_create();
    sfRectangleShape_setOrigin((*player)->hitbox, origin);
    sfRectangleShape_setSize((*player)->hitbox, size);
    sfRectangleShape_setPosition((*player)->hitbox, (*player)->position);
    sfRectangleShape_setFillColor((*player)->hitbox, p_color);
}

int init_player(player_t **player)
{
    *player = malloc(sizeof(player_t));
    if (!*player)
        return EXIT_FAILURE;
    (*player)->position = (sfVector2f){4 * TILE_SIZE, 4 * TILE_SIZE};
    (*player)->direction = (sfVector2f){-1, 0};
    (*player)->camera_plane = (sfVector2f){0, 0.66};
    (*player)->camera = (sfVector2f){0, 0};
    set_hitbox(player);
    (*player)->delta_x = 0;
    (*player)->delta_y = 0;
    (*player)->mvt_speed = 5;
    return EXIT_SUCCESS;
}
