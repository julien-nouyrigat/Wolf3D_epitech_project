/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** handle_enderman
*/

#include "wolf.h"

void handle_enderman(monster_t *mob, player_t *player,
    map_t __attribute_maybe_unused__ *map)
{
    sfTime time = sfClock_getElapsedTime(mob->mob_clock);
    float sec = time.microseconds / SECOND;

    if (sec >= mob->cooldown) {
        mob->position.x = player->position.x +
            (PLAYER_SIZE * MIN_DIST) * player->direction.x;
        mob->position.y = player->position.y +
            (PLAYER_SIZE * MIN_DIST) * player->direction.y;
        sfMusic_play(mob->sound_effect);
        sfClock_restart(mob->mob_clock);
    }
}
