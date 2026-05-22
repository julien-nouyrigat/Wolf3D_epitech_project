/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** save
*/

#include "wolf.h"

static void save_pos(player_t *player)
{
    FILE *file = fopen("./save/pos.save", "w");

    fprintf(file, "%f\n", player->position.x);
    fprintf(file, "%f\n", player->position.y);
    fprintf(file, "%f\n", player->pos_f.x);
    fprintf(file, "%f\n", player->pos_f.y);
    fclose(file);
}

static void save_info(player_t *player)
{
    FILE *file = fopen("./save/info.save", "w");

    fprintf(file, "%zu\n", player->life);
    fprintf(file, "%zu\n", player->stamina);
    fclose(file);
}

static void save_map(map_t *map)
{
    FILE *file = fopen("./save/map.save", "w");

    for (size_t i = 0; i < MAP_SIZE; i++) {
        for (size_t j = 0; j < MAP_SIZE; j++) {
            fprintf(file, "%d ", map->int_map[i][j]);
        }
        fprintf(file, "%s", "\n");
    }
    fclose(file);
}

void save_in_file(player_t *player, map_t *map)
{
    save_map(map);
    save_pos(player);
    save_info(player);
}
