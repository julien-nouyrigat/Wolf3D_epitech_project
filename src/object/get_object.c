/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** get_object
*/

#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#include <math.h>

#include "wolf.h"

void set_item(item_t *item, player_t *player, inventory_t *inv)
{
    if (item->weight + inv->player_weight
        > inv->player_max_weight)
        return;
    if (inv->player_weight > inv->player_max_weight / 2 && !inv->penalty){
        player->mvt_speed -= (int)(player->mvt_speed / 2);
        inv->penalty = true;
    }
    item->is_grab = true;
    inv->player_money += item->price;
    inv->player_weight += item->weight;
    printf("%d\n", player->mvt_speed);
    printf("weight = %zu money = %zu\n", inv->player_weight, inv->player_money);
}

void grab_object(player_t *player, map_t *map)
{
    loot_t *loot_tmp = map->level->loot;
    float dx = 0;
    float dy = 0;

    for (; loot_tmp; loot_tmp = loot_tmp->next){
        if (loot_tmp->item->is_grab)
            continue;
        dx = loot_tmp->item->position.x - player->position.x;
        dy = loot_tmp->item->position.y - player->position.y;
        if (dx > -60 && dx < 60 && dy > -60 && dy < 60)
            return set_item(loot_tmp->item, player, player->inventory);
    }
}
