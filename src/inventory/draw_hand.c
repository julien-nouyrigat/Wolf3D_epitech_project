/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** draw_hand
*/

#include "wolf.h"

static void animate_hand(player_t *player)
{
    sfTime cooldown = sfClock_getElapsedTime(player->in_hand->w_clock);

    if (player->in_hand->bullets == 0 || cooldown.microseconds / SECOND <
        player->in_hand->stats->cooldown)
        return;
    player->in_hand->bullets -= 1;
    sfClock_restart(player->in_hand->w_clock);
}

void draw_hand(window_t *win, player_t *player)
{
    if (player->in_hand == NULL)
        return;
    sfClock_restart(player->in_hand->animation);
    if (player->shoots) {
        animate_hand(player);
        player->shoots = false;
    }
    sfSprite_setTextureRect(player->in_hand->sprite, player->in_hand->area);
    sfRenderWindow_drawSprite(win->window, player->in_hand->sprite, NULL);
}
