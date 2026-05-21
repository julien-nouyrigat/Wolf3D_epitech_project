/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** music
*/

#ifndef MUSIC_H_
    #define MUSIC_H_
    #define NB_MUSIC 2
    #include <SFML/Audio.h>

typedef void(*func_music_t)(sfMusic *music, float *t1, float t2);

typedef struct music {
    int tiles;
    float time;
    sfMusic *music;
    func_music_t func;
} music_t;

typedef struct {
    int tiles;
    char *path;
    func_music_t func;
} info_music_t;

void play_music(sfMusic *music, float *t1, float t2);

static const info_music_t info_music[NB_MUSIC] = {
    {100, "assets/sounds/67_Cymbal.mp3", &play_music},
    {101, "assets/sounds/74_Scare_Sighting.mp3", &play_music},
};

#endif /* MUSIC_H_ */
