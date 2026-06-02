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
    sfSprite_setScale(inv->s_inventory, (sfVector2f){2, 2});
    sfSprite_setTexture(inv->s_inventory, inv->t_inventory, sfTrue);
    inv->inventory = malloc(sizeof(int) * NB_MAX_ITEM);
    if (!inv->inventory)
        return NULL;
    for (size_t i = 0; i < NB_MAX_ITEM; i++)
        inv->inventory[i] = EMPTY_SLOT;
    return inv;
}

void set_inv(window_t *win, player_t *player, map_t *map)
{
    (void)player;
    (void)map;
    if (sfKeyboard_isKeyPressed(sfKeyI)){
        if (player->is_in_inv){
            player->is_in_inv = false;
            return;
        }
        if (!player->is_in_inv){
            player->is_in_inv = true;
            return;
        }
    }
    if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
        if (win->is_param) {
            win->is_param = false;
            return;
        }
        if (!win->is_param)
            win->is_param = true;
    }
}

void display_inventory(window_t *win, player_t *player)
{
    sfSprite_setPosition(player->inventory->s_inventory,
        player->inventory->pos);
    sfRenderWindow_drawSprite(win->window,
        player->inventory->s_inventory, NULL);
}
