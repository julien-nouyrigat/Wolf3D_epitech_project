/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** handle_enderman
*/

#include "wolf.h"

static void check_attack(monster_t *mob, player_t *player, window_t *win)
{
    float x = (mob->position.x - player->position.x) / TILE_SIZE;
    float y = (mob->position.y - player->position.y) / TILE_SIZE;
    float dist = sqrt(x * x + y * y);
    sfTime seen;

    if (dist <= SEEING_DIST && is_in_axis(win, mob)) {
        seen = sfClock_getElapsedTime(player->enderman);
        if (seen.microseconds / SECOND >= 2) {
            take_damage(win, player, mob->damage);
        }
    } else {
        sfClock_restart(player->enderman);
    }
}

void handle_enderman(monster_t *mob, player_t *player,
    map_t __attribute_maybe_unused__ *map, window_t *win)
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
    check_attack(mob, player, win);
}
