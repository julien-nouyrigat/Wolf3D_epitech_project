/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** generating
*/
#include <time.h>
#include <string.h>
#include <sys/types.h>
#include <stdbool.h>
#include "wolf.h"
#include "room.h"
bool has_door(room_t *room, int x, int y)
{
    for (int i = 0; i < room->nb_doors; i++){
        if (room->door_pos[i][0] == x &&
            room->door_pos[i][1] == y)
            return true;
    }
    return false;
}

bool connect(rooms_t *rooms, int cur, int new, int pos)
{
    room_t *cur_room = &rooms->rooms[cur];
    room_t *new_room = &rooms->rooms[new];

    if (pos == 0)
        return has_door(cur_room, 3, 6) && has_door(new_room, 3, 0);
    if (pos == 1)
        return has_door(cur_room, 6, 3) && has_door(new_room, 0, 3);
    if (pos == 2)
        return has_door(cur_room, 3, 0) && has_door(new_room, 3, 6);
    if (pos == 3)
        return has_door(cur_room, 0, 3) && has_door(new_room, 6, 3);
    return false;
}

void add_room(int **s_map, int x, int y, rooms_t *rooms, int *placed, int max)
{
    int nx = 0;
    int ny = 0;
    int new_room = (rand() % (rooms->count - 1)) + 1;
    int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    if (*placed >= max)
        return;
    for (size_t d = 0; d < 4; d++){
        nx = x + dirs[d][0];
        ny = y + dirs[d][1];
        if (nx < 0 || ny < 0 || nx >= 10 || ny >= 10)
            continue;
        if (s_map[nx][ny] != -1)
            continue;
        if (connect(rooms, s_map[x][y], new_room, d) == false)
            continue;
        s_map[nx][ny] = new_room;
        (*placed)++;
        add_room(s_map, nx, ny, rooms, placed, max);
    }
}

int **genrating_map(rooms_t *rooms, int nb_rooms)
{
    int placed = 1;
    int **small_map = malloc(sizeof(int *) * 10);

    srand(time(NULL));
    if (!small_map)
        return NULL;
    for (size_t i = 0; i < 10; i++){
        small_map[i] = malloc(sizeof(int) * 10);
        if (!small_map[i])
            return NULL;
        for (size_t j = 0; j < 10; j++)
            small_map[i][j] = -1;
    }
    small_map[0][0] = SPAWN;
    add_room(small_map, 0, 0, rooms, &placed, nb_rooms);
    return small_map;
}
