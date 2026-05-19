/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** level
*/

#ifndef LEVEL_H_
    #define LEVEL_H_

    #include "map.h"

typedef struct {
    size_t id;
    struct map_t *map;
    size_t nb_mobs;
    struct enemy_t *enemies;
} level_t;

#endif /* LEVEL_H_ */
