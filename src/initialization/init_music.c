/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** init_music
*/
#include "wolf.h"

void init_music(window_t *win)
{
    for (size_t i = 0; i < NB_MUSIC; i++){
        win->tab_music[i].music = sfMusic_createFromFile(info_music[i].path);
        win->tab_music[i].func = info_music[i].func;
        win->tab_music[i].tiles = info_music[i].tiles;
        win->tab_music[i].time = 0;
    }
    win->ambiance = sfMusic_createFromFile("./assets/sounds/ambiance.mp3");
    sfMusic_setVolume(win->ambiance, AMBIANCE);
    win->ambiance_started = false;
}
