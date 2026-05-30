/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** next_level
*/

#include <stdlib.h>

#include "wolf.h"

static int change_monsters(map_t *map)
{
    free_enemies_list(map);
    for (size_t i = 0; i < map->level->nb_mobs; i++) {
        if (create_new_monster(&map) == EXIT_FAILURE)
            return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

static int change_map(map_t *map, size_t lvl_id)
{
    map->int_map = create_map(level_data[lvl_id].nb_rooms);
    if (map->int_map == NULL)
        return EXIT_FAILURE;
    map->type = (rand() % NB_MAPS) + 1;
    map->map_pos = (sfVector2i){0, 0};
    return EXIT_SUCCESS;
}

static void reinit_player(player_t *player)
{
    player->position = (sfVector2f){31 * TILE_SIZE,
        31 * TILE_SIZE};
    player->pos_f.x = player->position.x / TILE_SIZE;
    player->pos_f.y = player->position.y / TILE_SIZE;
    player->direction = (sfVector2f){-1, 0};
    player->stamina = player->max_stamina;
    sfClock_restart(player->p_clock);
}

int new_level(map_t *map, player_t *player)
{
    int lvl_id = 0;

    map->level->lvl += NEXT_LEVEL;
    if (map->level->lvl <= MAX_LEVEL)
        lvl_id = map->level->lvl - 1;
    else
        lvl_id = MAX_LEVEL - 1;
    if (change_map(map, lvl_id) == EXIT_FAILURE)
        return EXIT_FAILURE;
    map->level->nb_mobs = level_data[lvl_id].nb_mobs;
    if (change_monsters(map) == EXIT_FAILURE)
        return EXIT_FAILURE;
    reinit_player(player);
    return EXIT_SUCCESS;
}
