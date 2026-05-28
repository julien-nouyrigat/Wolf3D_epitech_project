/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** generating
*/
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <sys/types.h>
#include <stdbool.h>
#include "wolf.h"
#include "room.h"

static int *set_pathlist(rooms_t *rooms)
{
    size_t n = rooms->count - 1;
    int *path = malloc(sizeof(int) * n);
    int j = 0;
    int tmp = 0;

    if (!path)
        return NULL;
    for (size_t i = 0; i < n; i++)
        path[i] = i + 1;
    for (int i = n - 1; i > 0; i--) {
        j = rand() % (i + 1);
        tmp = path[i];
        path[i] = path[j];
        path[j] = tmp;
    }
    return path;
}

static bool has_door(room_t *room, int x, int y)
{
    for (int i = 0; i < room->nb_doors; i++){
        if (room->door_pos[i][0] == x &&
            room->door_pos[i][1] == y)
            return true;
    }
    return false;
}

static bool connect_rooms(rooms_t *rooms, int cur, int new, int pos)
{
    room_t *cur_room = &rooms->rooms[cur];
    room_t *new_room = &rooms->rooms[new];

    if (cur_room->nb_doors == new_room->nb_doors)
        return false;
    if (cur_room->nb_doors < 3 && new_room->nb_doors == 1)
        return false;
    if (pos == SOUTH)
        return has_door(cur_room, MID, DOWN) && has_door(new_room, MID, TOP);
    if (pos == EAST)
        return has_door(cur_room, RIGHT, MID) && has_door(new_room, LEFT, MID);
    if (pos == WEST)
        return has_door(cur_room, MID, LEFT) && has_door(new_room, MID, RIGHT);
    if (pos == NORTH)
        return has_door(cur_room, TOP, MID) && has_door(new_room, DOWN, MID);
    return false;
}

static bool all_verif(int dirs[4][2])
{
    for (int i = 0; i < NB_DIR; i++){
        if (dirs[i][0] != VISITED)
            return true;
    }
    return false;
}

int can_add(pos_t *npos, int **s_map)
{
    int nx = npos->x;
    int ny = npos->y;

    if (nx < 0 || ny < 0 || nx >= SIZE_SMAP || ny >= SIZE_SMAP)
        return false;
    if (s_map[nx][ny] != NO_ROOM)
        return false;
    return true;
}

int tries_rooms(rooms_t *rooms, int **s_map, int d, pos_t *pos_dup)
{
    int *path = set_pathlist(rooms);
    size_t res = 0;

    for (size_t index = 0; index != rooms->count - 1; index++){
        if (connect_rooms(rooms, s_map[pos_dup->x][pos_dup->y],
                path[index], d) == true){
            res = path[index];
            free(path);
            return res;
        }
    }
    free(path);
    return res;
}

void take_dirs(pos_t *npos, pos_t *pos_dup, int dirs[NB_DIR][2], int d)
{
    npos->x = pos_dup->x + dirs[d][0];
    npos->y = pos_dup->y + dirs[d][1];
    dirs[d][0] = VISITED;
}

void add_room(int **s_map, pos_t *pos, rooms_t *rooms, int *placed)
{
    pos_t new = {0};
    pos_t pos_dup = *pos;
    int index = 0;
    int dirs[NB_DIR][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    for (size_t d = rand() % NB_DIR; all_verif(dirs); d = rand() % NB_DIR){
        if (dirs[d][0] == VISITED)
            continue;
        take_dirs(&new, &pos_dup, dirs, d);
        if (can_add(&new, s_map) == false)
            continue;
        if (*placed == 1)
            return;
        index = tries_rooms(rooms, s_map, d, &pos_dup);
        if (index != 0){
            s_map[new.x][new.y] = index;
            (*placed)--;
            add_room(s_map, &new, rooms, placed);
        }
    }
}

static int **init_smap(void)
{
    int **small_map = malloc(sizeof(int *) * SIZE_SMAP);

    if (!small_map)
        return NULL;
    for (size_t i = 0; i < SIZE_SMAP; i++){
        small_map[i] = malloc(sizeof(int) * SIZE_SMAP);
        if (!small_map[i])
            return NULL;
        for (size_t j = 0; j < SIZE_SMAP; j++)
            small_map[i][j] = NO_ROOM;
    }
    small_map[CENTER][CENTER] = SPAWN;
    return small_map;
}

int **genrating_map(rooms_t *rooms, int nb_rooms)
{
    pos_t pos = {CENTER, CENTER};
    int **small_map = init_smap();

    if (small_map == NULL)
        return NULL;
    add_room(small_map, &pos, rooms, &nb_rooms);
    return small_map;
}
