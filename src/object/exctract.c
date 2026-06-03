/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** exctract
*/

#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#include <math.h>

#include "wolf.h"

void exctract(map_t *map, player_t *player, inventory_t *inv)
{
    if (map->int_map[(int)player->pos_f.y][(int)player->pos_f.x] == 9){
        map->level->cur_money += inv->player_money;
        inv->player_money = 0;
        inv->player_weight = 0;
        player->mvt_speed = MOVEMENT_SPEED;
        if (map->level->cur_money == level_data[map->level->lvl_id].lvl_money){
            new_level(map, player);
            map->level->cur_money = 0;
        }
        if (map->level->cur_money > level_data[map->level->lvl_id].lvl_money){
            inv->player_money =
                map->level->cur_money - level_data[map->level->lvl_id].lvl_money;
            new_level(map, player);
            map->level->cur_money = 0;
        }
    }
}
