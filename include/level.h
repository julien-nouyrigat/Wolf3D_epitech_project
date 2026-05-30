/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** level
*/

#ifndef LEVEL_H_
    #define LEVEL_H_

    #include "enemies.h"
    #include "inventory.h"
    #include "textures.h"

    #define FIRST_LEVEL 1
    #define INIT_NB_MOBS 2
    #define INIT_MAX_MONEY 1000
    #define MAX_LEVEL 10
    #define NEXT_LEVEL 1

typedef struct level_s {
    size_t lvl;
    size_t nb_mobs;
    sfTexture **mob_texts;
    struct enemy_s *enemies;
    struct loot_s *loot;
} level_t;

typedef struct {
    size_t lvl;
    size_t nb_rooms;
    size_t nb_mobs;
} level_data_t;

static const level_data_t level_data[MAX_LEVEL] = {
    {1, 20, 2},
    {2, 25, 3},
    {3, 30, 4},
    {4, 35, 4},
    {5, 35, 5},
    {6, 40, 5},
    {7, 45, 5},
    {8, 45, 6},
    {9, 50, 6},
    {10, 50, 7}
};

#endif /* LEVEL_H_ */
