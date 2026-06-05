/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** init_player
*/

#include <stdlib.h>
#include <math.h>
#include <unistd.h>

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

static void init_life_and_stamina(player_t **player)
{
    (*player)->life = LIFE_START;
    (*player)->max_life = LIFE_START;
    (*player)->stamina = STAM_START;
    (*player)->max_stamina = STAM_START;
}

void init_player_comp(player_t **player)
{
    (*player)->position = (sfVector2f){31 * TILE_SIZE,
        31 * TILE_SIZE};
    (*player)->pos_f.x = (*player)->position.x / TILE_SIZE;
    (*player)->pos_f.y = (*player)->position.y / TILE_SIZE;
    (*player)->direction = (sfVector2f){-1, 0};
    (*player)->camera_plane = (sfVector2f){0, FOV};
    (*player)->y_camera = FOV;
    (*player)->camera = (sfVector2f){0, 0};
    (*player)->delta_x = 0;
    (*player)->delta_y = 0;
    (*player)->shoots = false;
    (*player)->new_game = false;
}

static void init_hand(player_t **player)
{
    (*player)->cursor = 0;
    (*player)->in_hand = (*player)->hand_inv->w_one;
}

static void init_clocks(player_t **player)
{
    (*player)->p_clock = sfClock_create();
    (*player)->enderman = sfClock_create();
}

int init_player(player_t **player)
{
    *player = calloc(sizeof(player_t), 1);
    if (*player == NULL)
        return EXIT_FAILURE;
    (*player)->hand_inv = calloc(sizeof(hand_inv_t), 1);
    if ((*player)->hand_inv == NULL) {
        free(player);
        return EXIT_FAILURE;
    }
    set_hitbox(player);
    init_player_comp(player);
    init_hand(player);
    (*player)->mvt_speed = MOVEMENT_SPEED;
    (*player)->sprint = false;
    (*player)->is_moving = false;
    (*player)->bobing = 0;
    init_life_and_stamina(player);
    init_clocks(player);
    (*player)->inventory = init_inventory();
    (*player)->is_in_inv = false;
    return EXIT_SUCCESS;
}
