/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** generating
*/
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <stdbool.h>
#include "wolf.h"
#include "room.h"

static int array_len(char **line)
{
    size_t i = 0;

    for (; line[i] != NULL; i++);
    return i;
}

rooms_t *init_rooms_tab(rooms_t *rooms)
{
    DIR *dirent;
    struct dirent *entry;
    size_t count = 0;

    if (!rooms)
        return NULL;
    dirent = opendir("rooms");
    if (!dirent)
        return NULL;
    entry = readdir(dirent);
    for (; entry != NULL; entry = readdir(dirent))
        if (entry->d_name[0] != HIDE)
            count++;
    rooms->count = count;
    closedir(dirent);
    rooms->rooms = malloc(sizeof(room_t) * count);
    if (!rooms->rooms)
        return NULL;
    return rooms;
}

static int *get_room(char *line)
{
    char **arr_line = my_str_to_wa(line);
    int *int_line = NULL;
    size_t i = array_len(arr_line);

    int_line = malloc(sizeof(int) * i);
    if (!int_line)
        return NULL;
    for (size_t x = 0; x < i; x++)
        int_line[x] = atoi(arr_line[x]);
    free_array(arr_line);
    return int_line;
}

static room_t *set_room_size(room_t *room, FILE *fp)
{
    char **arr_line = NULL;
    char *line = NULL;
    size_t len = 0;
    int count = 0;

    for (; getline(&line, &len, fp) != -1; count++);
    arr_line = my_str_to_wa(line);
    room->size_w = array_len(arr_line);
    room->size_h = count;
    room->nb_tiles = (count / MUL) * (count / MUL);
    free_array(arr_line);
    free(line);
    return room;
}

room_t *set_map(room_t *room, FILE *fp)
{
    char *line = NULL;
    size_t len = 0;

    room->room = malloc(sizeof(int *) * room->size_h);
    if (!room->room)
        return NULL;
    for (size_t i = 0; getline(&line, &len, fp) != -1; i++){
        room->room[i] = get_room(line);
        if (!room->room[i])
            return NULL;
    }
    free(line);
    return room;
}

room_t set_room(char *file)
{
    room_t room = {0};
    char path[256];
    FILE *fp = NULL;

    snprintf(path, sizeof(path), "rooms/%s", file);
    fp = fopen(path, "r");
    if (fp == NULL)
        return room;
    room = *set_room_size(&room, fp);
    rewind(fp);
    room = *set_map(&room, fp);
    fclose(fp);
    return room;
}

rooms_t *pars_map(rooms_t *rooms, size_t count)
{
    DIR *dirent;
    struct dirent *entry;

    rooms = init_rooms_tab(rooms);
    if (rooms == NULL)
        return NULL;
    dirent = opendir("rooms");
    if (!dirent){
        free(rooms);
        return NULL;
    }
    rooms->rooms[0] = set_room(SPAWN_PATH);
    for (entry = readdir(dirent); entry != NULL; entry = readdir(dirent)){
        if (entry->d_name[0] != HIDE && strcmp(entry->d_name, SPAWN_PATH) != 0){
            rooms->rooms[count] = set_room(entry->d_name);
            count++;
        }
    }
    closedir(dirent);
    return rooms;
}
