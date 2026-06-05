/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** music
*/

#ifndef MUSIC_H_
    #define MUSIC_H_
    #define NB_MUSIC 10
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
    {102, "assets/sounds/02_Lobby.mp3", &play_music},
    {103, "assets/sounds/13_Arctic_Water.mp3", &play_music},
    {104, "assets/sounds/17_Manor_Outside_Metal.mp3", &play_music},
    {105, "assets/sounds/26_Enemy_Near_01.mp3", &play_music},
    {106, "assets/sounds/27_Enemy_Near_02.mp3", &play_music},
    {107, "assets/sounds/28_Enemy_Near_03.mp3", &play_music},
    {111, "assets/sounds/72_Scare_Impact.mp3", &play_music},
    {112, "assets/sounds/monster_footstep.wav", &play_music},
};

#endif /* MUSIC_H_ */
