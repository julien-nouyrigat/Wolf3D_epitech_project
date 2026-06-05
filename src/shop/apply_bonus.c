/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** apply_bonus
*/

#include "wolf.h"
#include "boutique.h"

void apply_regen_25(player_t *player)
{
    player->life += 25;
    if (player->life > player->max_life)
        player->life = player->max_life;
}

void apply_regen_50(player_t *player)
{
    player->life += 50;
    if (player->life > player->max_life)
        player->life = player->max_life;
}

void apply_regen_100(player_t *player)
{
    player->life = player->max_life;
}

void apply_stamina_20(player_t *player)
{
    player->max_stamina += 20;
}

void apply_life_20(player_t *player)
{
    player->max_life += 20;
}

void apply_nothing(player_t __attribute_maybe_unused__ *player)
{
}
