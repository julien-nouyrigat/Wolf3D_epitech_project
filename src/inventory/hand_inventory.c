/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** hand_inventory
*/

#include "wolf.h"

static void set_rectangles(player_t **player, window_t *win)
{
    sfRectangleShape_setFillColor((*player)->hand_inv->one, INV_COLOR);
    sfRectangleShape_setSize((*player)->hand_inv->one,
        (sfVector2f){HAND_INV_SIZE, HAND_INV_SIZE});
    sfRectangleShape_setPosition((*player)->hand_inv->one,
        (sfVector2f){win->size.x / 2 - HAND_INV_SIZE / 2 - 200,
            EMPTY_HAND_INV});
    sfRectangleShape_setFillColor((*player)->hand_inv->two, INV_COLOR);
    sfRectangleShape_setSize((*player)->hand_inv->two,
        (sfVector2f){HAND_INV_SIZE, HAND_INV_SIZE});
    sfRectangleShape_setPosition((*player)->hand_inv->two,
        (sfVector2f){win->size.x / 2 - HAND_INV_SIZE / 2, EMPTY_HAND_INV});
    sfRectangleShape_setFillColor((*player)->hand_inv->three, INV_COLOR);
    sfRectangleShape_setSize((*player)->hand_inv->three,
        (sfVector2f){HAND_INV_SIZE, HAND_INV_SIZE});
    sfRectangleShape_setPosition((*player)->hand_inv->three,
        (sfVector2f){win->size.x / 2 - HAND_INV_SIZE / 2 + 200,
            EMPTY_HAND_INV});
}

static void create_texts(player_t **player)
{
    (*player)->hand_inv->t_one = sfText_create();
    sfText_setFont((*player)->hand_inv->t_one, inv_font);
    (*player)->hand_inv->t_two = sfText_create();
    sfText_setFont((*player)->hand_inv->t_two, inv_font);
    (*player)->hand_inv->t_three = sfText_create();
    sfText_setFont((*player)->hand_inv->t_three, inv_font);
}

void init_hand_inv(player_t **player, window_t *win)
{
    sfFont *inv_font = sfFont_createFromFile(INV_FONT);

    (*player)->hand_inv->one = sfRectangleShape_create();
    (*player)->hand_inv->two = sfRectangleShape_create();
    (*player)->hand_inv->three = sfRectangleShape_create();
    (*player)->hand_inv->w_one = NULL;
    (*player)->hand_inv->w_two = NULL;
    (*player)->hand_inv->w_three = NULL;
    set_rectangles(player, win);
    create_texts(player);
}

void display_hand_inv(window_t *win, player_t *player)
{
    sfRenderWindow_drawRectangleShape(win->window, player->hand_inv->one, NULL);
    sfRenderWindow_drawRectangleShape(win->window, player->hand_inv->two, NULL);
    sfRenderWindow_drawRectangleShape(win->window, player->hand_inv->three,
        NULL);
}
