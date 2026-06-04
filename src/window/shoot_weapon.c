/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** shoot_weapon
*/

#include "wolf.h"

static void reset_state(player_t *player)
{
    player->in_hand->area.left = AREA.left;
    player->in_hand->area.top = AREA.top;
    player->shoots = false;
}

void animate_hand(player_t *player)
{
    sfTime anim = sfClock_getElapsedTime(player->in_hand->animation);
    int col = 0;
    int row = 0;

    if (!player->shoots)
        return;
    col = player->in_hand->frame % 3;
    row = player->in_hand->frame / 3;
    if (anim.microseconds / SECOND >= 0.025) {
        sfClock_restart(player->in_hand->animation);
        player->in_hand->area.left = AREA.left + col * SIZE;
        player->in_hand->area.top = AREA.top + row * SIZE;
        player->in_hand->frame += 1;
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
    shoot(win, player, map);
}
