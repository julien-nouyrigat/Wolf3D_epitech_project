/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** shoot_weapon
*/

#include "wolf.h"

static void reset_state(player_t *player)
{
    player->in_hand->area.left =
        weapons_data[player->in_hand->type].area.left;
    player->in_hand->area.top =
        weapons_data[player->in_hand->type].area.top;
    player->shoots = false;
}

void animate_hand(player_t *player)
{
    sfTime anim = sfClock_getElapsedTime(player->in_hand->animation);

    if (!player->shoots)
        return;
    if (anim.microseconds / SECOND >= 0.2) {
        sfClock_restart(player->in_hand->animation);
        player->in_hand->area.left += player->in_hand->stats->d_left;
        player->in_hand->frame += 1;
        if (player->in_hand->frame > 0 && player->in_hand->frame % 3 == 2) {
            player->in_hand->area.left =
                weapons_data[player->in_hand->type].area.left;
            player->in_hand->area.top += player->in_hand->stats->d_top;
        }
        if (player->in_hand->frame > 8) {
            reset_state(player);
        }
        sfSprite_setTextureRect(player->in_hand->sprite,
            player->in_hand->area);
    }
}

void shoot_weapon(window_t *win, player_t *player, map_t *map)
{
    player->in_hand->bullets -= 1;
    player->in_hand->frame = 0;
    //shoot();
}
