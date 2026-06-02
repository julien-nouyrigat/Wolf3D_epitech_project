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
    float dx = 0;
    float dy = 0;

    for (; enemies; enemies = enemies->next){
        dx = enemies->monster->position.x - player->position.x;
        dy = enemies->monster->position.y - player->position.y;
        if (dx > -60 && dx < 60 &&
            dy > -60 && dy < 60){
            take_damage(player, 1);
        }
    }
}
