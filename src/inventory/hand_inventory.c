/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** hand_inventory
*/

#include "wolf.h"

static void set_rectangles(player_t **player, window_t const *win)
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

static void format_text(player_t **player, window_t const *win)
{
    sfText_setScale((*player)->hand_inv->t_one, (sfVector2f){1.5, 1.5});
    sfText_setColor((*player)->hand_inv->t_one, sfWhite);
    sfText_setPosition((*player)->hand_inv->t_one,
        (sfVector2f){win->size.x / 2 - HAND_INV_SIZE - 55,
            EMPTY_HAND_INV + 10});
    sfText_setScale((*player)->hand_inv->t_two, (sfVector2f){1.5, 1.5});
    sfText_setColor((*player)->hand_inv->t_two, sfWhite);
    sfText_setPosition((*player)->hand_inv->t_two,
        (sfVector2f){win->size.x / 2 - 5, EMPTY_HAND_INV + 10});
    sfText_setScale((*player)->hand_inv->t_three, (sfVector2f){1.5, 1.5});
    sfText_setColor((*player)->hand_inv->t_three, sfWhite);
    sfText_setPosition((*player)->hand_inv->t_three,
        (sfVector2f){win->size.x / 2 + HAND_INV_SIZE + 45,
            EMPTY_HAND_INV + 10});
}

static void create_texts(player_t **player, window_t const *win)
{
    sfFont *inv_font = sfFont_createFromFile(INV_FONT);

    (*player)->hand_inv->t_one = sfText_create();
    sfText_setFont((*player)->hand_inv->t_one, inv_font);
    sfText_setString((*player)->hand_inv->t_one, "1");
    (*player)->hand_inv->t_two = sfText_create();
    sfText_setFont((*player)->hand_inv->t_two, inv_font);
    sfText_setString((*player)->hand_inv->t_two, "2");
    (*player)->hand_inv->t_three = sfText_create();
    sfText_setFont((*player)->hand_inv->t_three, inv_font);
    sfText_setString((*player)->hand_inv->t_three, "3");
    format_text(player, win);
}

void init_hand_inv(player_t **player, window_t const *win)
{
    (*player)->hand_inv->one = sfRectangleShape_create();
    (*player)->hand_inv->two = sfRectangleShape_create();
    (*player)->hand_inv->three = sfRectangleShape_create();
    (*player)->hand_inv->w_one = win->weapons_tab[GUN];
    (*player)->hand_inv->w_two = win->weapons_tab[SHOTGUN];
    (*player)->hand_inv->w_three = win->weapons_tab[PHOTON_BLASTER];
    set_rectangles(player, win);
    create_texts(player, win);
}

static sfVector2f get_pos(window_t const *win, int offset)
{
    sfVector2f pos = (sfVector2f){win->size.x / 2 - HAND_INV_SIZE / 2 + offset,
        EMPTY_HAND_INV};

    return pos;
}

static void draw_last_hand(window_t const *win, player_t const *player)
{
    if (player->hand_inv->w_three == NULL)
        sfRenderWindow_drawText(win->window, player->hand_inv->t_three, NULL);
    else {
        sfSprite_setPosition(player->hand_inv->w_three->icon,
            get_pos(win, 240));
        sfRenderWindow_drawSprite(win->window,
            player->hand_inv->w_three->icon, NULL);
    }
}

static void draw_hand_content(window_t const *win, player_t const *player)
{
    if (player->hand_inv->w_one == NULL)
        sfRenderWindow_drawText(win->window, player->hand_inv->t_one, NULL);
    else {
        sfSprite_setPosition(player->hand_inv->w_one->icon, get_pos(win, -160));
        sfRenderWindow_drawSprite(win->window, player->hand_inv->w_one->icon,
            NULL);
    }
    if (player->hand_inv->w_two == NULL)
        sfRenderWindow_drawText(win->window, player->hand_inv->t_two, NULL);
    else {
        sfSprite_setPosition(player->hand_inv->w_two->icon, get_pos(win, 40));
        sfRenderWindow_drawSprite(win->window, player->hand_inv->w_two->icon,
            NULL);
    }
    draw_last_hand(win, player);
}

void display_hand_inv(window_t const *win, player_t const *player)
{
    sfRenderWindow_drawRectangleShape(win->window, player->hand_inv->one, NULL);
    sfRenderWindow_drawRectangleShape(win->window, player->hand_inv->two, NULL);
    sfRenderWindow_drawRectangleShape(win->window, player->hand_inv->three,
        NULL);
    draw_hand_content(win, player);
}
