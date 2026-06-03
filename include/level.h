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
    #define INIT_MAX_MONEY 10000
    #define MAX_LEVEL 10
    #define NEXT_LEVEL 1

typedef struct level_s {
    size_t lvl;
    size_t nb_mobs;
    sfTexture **mob_texts;
    struct enemy_s *enemies;
    struct loot_s *loot;
    size_t cur_money;
    size_t lvl_id;
} level_t;

typedef struct {
    size_t lvl;
    size_t nb_rooms;
    size_t nb_mobs;
    size_t lvl_money;
} level_data_t;

static const level_data_t level_data[MAX_LEVEL] = {
    {1, 20, 2, 300},
    {2, 25, 3, 11300},
    {3, 30, 4, 300},
    {4, 35, 4, 300},
    {5, 35, 5, 300},
    {6, 40, 5, 300},
    {7, 45, 5, 300},
    {8, 45, 6, 300},
    {9, 50, 6, 300},
    {10, 50, 7, 300}
};

#endif /* LEVEL_H_ */
