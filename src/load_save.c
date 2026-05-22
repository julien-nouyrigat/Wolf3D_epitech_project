/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** load_save
*/

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
    int check_file = open("./save/map_info.save", O_RDONLY);
    FILE *file = fopen("./save/map_info.save", "r");
    char *line = NULL;
    size_t len = 0;

    if (check_file == -1)
        return;
    getline(&line, &len, file);
    map->type = atoi(line);
    fclose(file);
}

static void load_map(map_t *map)
{
    int check_file = open("./save/map.save", O_RDONLY);
    FILE *file = fopen("./save/map.save", "r");
    char *line = NULL;
    char **complete_line = NULL;
    size_t len = 0;
    int index = 0;

    if (check_file == -1)
        return;
    while (getline(&line, &len, file) != EOF) {
        complete_line = my_str_to_wa(line);
        replace_map(map, complete_line, index);
        index++;
    }
    fclose(file);
}

void load_save(player_t *player, map_t *map)
{
    load_map(map);
    load_info_map(map);
}
