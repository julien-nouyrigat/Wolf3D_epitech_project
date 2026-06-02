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

void grab_object(player_t *player, map_t *map)
{
    loot_t *loot_tmp = map->level->loot;
    float dx = 0;
    float dy = 0;

    for (; loot_tmp; loot_tmp = loot_tmp->next){
        dx = loot_tmp->item->position.x - player->position.x;
        dy = loot_tmp->item->position.y - player->position.y;
        if (dx > -60 && dx < 60 &&
            dy > -60 && dy < 60){
            loot_tmp->item->is_grab = true;
            return;
        }
    }
}
