/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** load_save
*/

#include <sys/stat.h>
#include "room.h"
#include <fcntl.h>
#include <unistd.h>
#include "wolf.h"

static void replace_map(map_t *map, char **line, int index)
{
    for (size_t i = 0; line[i] != NULL; i++) {
        map->int_map[index][i] = atoi(line[i]);
    }
}

static void load_info_map(map_t *map)
{
    struct stat st;
    int check_file = open("./save/map_info.save", O_RDONLY);
    FILE *file = fopen("./save/map_info.save", "r");
    char *line = NULL;
    size_t len = 0;

    stat("./save/map_info.save", &st);
    if (st.st_size <= 0)
        return;
    if (check_file == -1)
        return;
    getline(&line, &len, file);
    map->type = atoi(line);
    fclose(file);
}

static void load_map(map_t *map)
{
    struct stat st;
    int check_file = open("./save/map.save", O_RDONLY);
    FILE *file = fopen("./save/map.save", "r");
    char *line = NULL;
    char **complete_line = NULL;
    size_t len = 0;
    int index = 0;

    stat("./save/map.save", &st);
    if (st.st_size <= 0)
        return;
    if (check_file == -1)
        return;
    while (getline(&line, &len, file) != EOF) {
        complete_line = my_str_to_wa(line);
        replace_map(map, complete_line, index);
        index++;
    }
    fclose(file);
}

static void load_pos(player_t *player)
{
    struct stat st;
    int check_file = open("./save/pos.save", O_RDONLY);
    FILE *file = fopen("./save/pos.save", "r");
    char *line = NULL;
    size_t len = 0;

    stat("./save/pos.save", &st);
    if (st.st_size <= 0)
        return;
    if (check_file == -1)
        return;
    getline(&line, &len, file);
    player->position.x = atoi(line);
    getline(&line, &len, file);
    player->position.y = atoi(line);
    getline(&line, &len, file);
    player->pos_f.x = atoi(line);
    getline(&line, &len, file);
    player->pos_f.y = atoi(line);
    fclose(file);
}

static void load_stat(player_t *player)
{
    struct stat st;
    int check_file = open("./save/info.save", O_RDONLY);
    FILE *file = fopen("./save/info.save", "r");
    char *line = NULL;
    size_t len = 0;

    stat("./save/info.save", &st);
    if (st.st_size <= 0)
        return;
    if (check_file == -1)
        return;
    getline(&line, &len, file);
    player->life = (size_t)atoi(line);
    getline(&line, &len, file);
    player->stamina = (size_t)atoi(line);
    fclose(file);
}

void load_save(player_t *player, map_t *map)
{
    load_map(map);
    load_info_map(map);
    load_pos(player);
    load_stat(player);
}
