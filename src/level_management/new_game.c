/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** new_game
*/

#include <stdlib.h>

#include "wolf.h"

static int nb_money(map_t **map)
{
    int money = 0;
    loot_t *tmp_loot = (*map)->level->loot;

    for (; tmp_loot; tmp_loot = tmp_loot->next){
        money += tmp_loot->item->price;
    }
    return money;
}

static int change_items(map_t **map, size_t max_money)
{
    free_items_list(*map);
    (*map)->level->loot = NULL;
    for (size_t i = 0; i <= max_money; i = nb_money(map)) {
        if (create_new_item(map) == EXIT_FAILURE)
            return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

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
    init_player_comp(&player);
    player->stamina = STAM_START;
    player->life = LIFE_START;
    player->max_stamina = STAM_START;
    player->mvt_speed = MOVEMENT_SPEED;
    sfClock_restart(player->p_clock);
}

int new_game(map_t *map, player_t *player)
{
    int lvl_id = 0;

    map->level->lvl_id = lvl_id;
    if (change_map(map, lvl_id) == EXIT_FAILURE)
        return EXIT_FAILURE;
    map->level->nb_mobs = level_data[lvl_id].nb_mobs;
    if (change_monsters(map) == EXIT_FAILURE)
        return EXIT_FAILURE;
    change_items(&map, level_data[map->level->lvl_id].lvl_money * 1.5);
    reinit_player(player);
    return EXIT_SUCCESS;
}
