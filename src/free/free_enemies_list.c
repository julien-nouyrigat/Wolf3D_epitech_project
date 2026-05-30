/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** free_enemies_list
*/

#include <stdlib.h>

#include "wolf.h"

static void free_monster(monster_t *mob)
{
    sfSprite_destroy(mob->sprite);
    sfClock_destroy(mob->mob_clock);
    free(mob);
}

void free_enemies_list(map_t *map)
{
    enemy_t *prec = NULL;

    while (map->level->enemies != NULL) {
        prec = map->level->enemies;
        map->level->enemies = map->level->enemies->next;
        free_monster(prec->monster);
        free(prec);
    }
}
