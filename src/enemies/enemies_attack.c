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
        player->new_game = true;
        player->mvt_speed = 0;
        sfMusic_stop(win->footsteps);
        return;
    }
    player->life -= damage;
}

void verif_cooldown(window_t *win, map_t __attribute_maybe_unused__ *map,
    player_t *player, enemy_t *enemies)
{
    sfTime time = sfClock_getElapsedTime(win->clock.broad_clock);
    float t1 = enemies->monster->last_attack;
    float t2 = time.microseconds / SECOND;

    if (t2 - t1 < enemies->monster->cooldown && t1 != 0)
        return;
    enemies->monster->last_attack = t2;
    take_damage(win, player, enemies->monster->damage);
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
            verif_cooldown(win, map, player, enemies);
            return;
        }
    }
}
