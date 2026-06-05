/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** inventory
*/
#include "wolf.h"
#include <stdlib.h>

inventory_t *init_inventory(void)
{
    inventory_t *inv = malloc(sizeof(inventory_t));

    if (!inv)
        return NULL;
    inv->pos = (sfVector2f){400, 100};
    inv->s_inventory = sfSprite_create();
    inv->t_inventory =
        sfTexture_createFromFile("assets/image/Inventory.png", NULL);
    sfSprite_setTexture(inv->s_inventory, inv->t_inventory, sfTrue);
    inv->inventory = malloc(sizeof(int) * NB_MAX_ITEM);
    if (!inv->inventory)
        return NULL;
    for (size_t i = 0; i < NB_MAX_ITEM; i++)
        inv->inventory[i] = EMPTY_SLOT;
    inv->player_max_weight = START_WEIGHT;
    inv->player_money = 0;
    inv->player_weight = 0;
    inv->penalty = false;
    return inv;
}

void set_inv(window_t *win, player_t *player, map_t *map)
{
    (void)player;
    (void)map;
}

void display_inventory(window_t *win, player_t *player)
{
    sfSprite_setPosition(player->inventory->s_inventory,
        player->inventory->pos);
    sfRenderWindow_drawSprite(win->window,
        player->inventory->s_inventory, NULL);
}
