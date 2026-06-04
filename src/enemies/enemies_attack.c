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

void take_damage(window_t *win, player_t *player, size_t damage)
{
    int life = player->life - damage;

    if (life <= 0){
        player->life = 0;
        win->is_single = false;
        win->is_menu = true;
        player->is_moving = false;
        sfMusic_stop(win->footsteps);
        return;
    }
    player->life -= damage;
}

void enemy_attack(player_t *player, map_t *map, window_t *win)
{
    enemy_t *enemies = map->level->enemies;
    float dx = 0;
    float dy = 0;

    for (; enemies; enemies = enemies->next){
        dx = enemies->monster->position.x - player->position.x;
        dy = enemies->monster->position.y - player->position.y;
        if (dx > -60 && dx < 60 &&
            dy > -60 && dy < 60){
            take_damage(win, player, enemies->monster->damage);
        }
    }
}
