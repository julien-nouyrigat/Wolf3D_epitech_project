/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** level
*/

#ifndef LEVEL_H_
    #define LEVEL_H_

    #include "enemies.h"
    #include "textures.h"

    #define FIRST_LEVEL 1
    #define INIT_NB_MOBS 2

typedef struct level_s {
    size_t lvl;
    size_t nb_mobs;
    sfTexture **mob_texts;
    struct enemy_s *enemies;
} level_t;

#endif /* LEVEL_H_ */
