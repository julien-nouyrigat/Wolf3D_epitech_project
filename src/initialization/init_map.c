/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** init_map
*/

#include <stdlib.h>
#include <time.h>

#include "textures.h"
#include "room.h"
#include "level.h"
#include "wolf.h"

static int init_enemies(map_t **map)
{
    (*map)->level->nb_mobs = INIT_NB_MOBS;
    (*map)->level->enemies = NULL;
    for (size_t i = 0; i < (*map)->level->nb_mobs; i++) {
        if (create_new_monster(map) == EXIT_FAILURE)
            return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

static int init_level(map_t **map)
{
    (*map)->level = calloc(sizeof(level_t), 1);
    if ((*map)->level == NULL)
        return EXIT_FAILURE;
    (*map)->level->mob_texts = calloc(sizeof(sfTexture *), NB_ENEMIES);
    if ((*map)->level->mob_texts == NULL) {
        free((*map)->level);
        return EXIT_FAILURE;
    }
    for (size_t i = 0; i < NB_ENEMIES; i++)
        (*map)->level->mob_texts[i] = FILE_TEXT(mob_textures[i].texture);
    if (init_enemies(map) == EXIT_FAILURE) {
        for (size_t i = 0; i < NB_ENEMIES; i++) {
            sfTexture_destroy((*map)->level->mob_texts[i]);
            free((*map)->level->mob_texts);
            free((*map)->level);
            return EXIT_FAILURE;
        }
    }
    (*map)->level->lvl = FIRST_LEVEL;
    return EXIT_SUCCESS;
}

int init_map(map_t **map)
{
    time_t *timer = NULL;

    *map = calloc(sizeof(map_t), 1);
    if (!*map)
        return EXIT_FAILURE;
    if (init_level(map) == EXIT_FAILURE) {
        free(*map);
        return EXIT_FAILURE;
    }
    (*map)->x = SIZE_MAP;
    (*map)->y = SIZE_MAP;
    (*map)->int_map = create_map(20);
    srand(time(timer));
    (*map)->type = rand() % NB_MAPS + 1;
    (*map)->map_pos = (sfVector2i){0, 0};
    return EXIT_SUCCESS;
}
