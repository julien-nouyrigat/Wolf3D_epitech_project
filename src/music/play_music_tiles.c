/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** play_music_tiles
*/
#include "wolf.h"

void verif_play_sound(player_t *player, map_t *map, window_t *win)
{
    sfTime time = sfClock_getElapsedTime(win->clock.broad_clock);

    for (size_t i = 0; i < NB_MUSIC; i++){
        if (map->int_map[(int)player->pos_f.y][(int)player->pos_f.x] ==
            win->tab_music[i].tiles){
            sfMusic_setVolume(win->tab_music[i].music, win->param.audio.volume);
            return win->tab_music[i].func(win->tab_music[i].music,
                &win->tab_music[i].time, time.microseconds / SECOND);
        }
    }
}

void play_music(sfMusic *music, float *t1, float t2)
{
    if (t2 - (*t1) < 20 && (*t1) != 0)
        return;
    (*t1) = t2;
    sfMusic_play(music);
}
