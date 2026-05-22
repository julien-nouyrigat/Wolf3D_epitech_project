/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** attack_enemies
*/

#include <stdlib.h>
#include <sys/param.h>
#include <math.h>

#include "wolf.h"

void take_damage(player_t *player, size_t damage)
{
    if (player->life - damage <= 0)
        return;
    player->life -= damage;
}

void enemy_attack(player_t *player, map_t *map)
{
    enemy_t *enemies = map->level->enemies;

    for (; enemies; enemies = enemies->next){
        if (enemies->monster->position.x - player->position.x < 10 &&
            enemies->monster->position.y - player->position.y < 10){
            take_damage(player, 1);
        }
    }
}
