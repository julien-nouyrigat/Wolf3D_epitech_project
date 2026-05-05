/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** stamina_regen
*/

#include "wolf.h"

void stamina_regen(player_t *player)
{
    sfTime time;
    float sec = 0;

    time = sfClock_getElapsedTime(player->p_clock);
    sec = time.microseconds / SECOND;
    if ((!player->sprint || !player->is_moving) && sec >= 1.f &&
        player->stamina < player->max_stamina) {
        player->stamina += 1;
        sfClock_restart(player->p_clock);
    }
}
