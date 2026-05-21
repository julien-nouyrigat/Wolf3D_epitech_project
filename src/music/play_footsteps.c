/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** play_footstep
*/
#include "wolf.h"

void verif_footsteps(player_t *player, window_t *win)
{
    if (!player->is_moving){
        sfMusic_play(win->footsteps);
        sfMusic_setLoop(win->footsteps, sfTrue);
    }
}
