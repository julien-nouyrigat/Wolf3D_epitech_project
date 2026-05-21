/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** init_footstep
*/

#include "wolf.h"

void init_footstep(window_t *win)
{
    win->footsteps =
        sfMusic_createFromFile("assets/sounds/player_footstep.mp3");
    sfMusic_setVolume(win->footsteps, win->param.audio.volume);
}
