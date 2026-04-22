/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** generating
*/
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <stdbool.h>
#include "wolf.h"
#include "room.h"

int is_door(room_t *room, int j, int i)
{
    if (room->room[j][i] == DOOR)
        return 1;
    return 0;
}

bool get_door(room_t *room, size_t *j, size_t y, int **doors)
{
    for (size_t k = 0; k < room->size_w; k++){
        if (is_door(room, y, k) != 1)
            continue;
        doors[*j] = malloc(sizeof(int) * 2);
        if (!doors[*j])
            return false;
        doors[*j][0] = y;
        doors[*j][1] = k;
        (*j)++;
    }
    return true;
}

size_t nb_doors(room_t *room)
{
    size_t nb_doors = 0;

    for (size_t j = 0; j < room->size_h; j++){
        for (size_t i = 0; i < room->size_w; i++){
            nb_doors += is_door(room, j, i);
        }
    }
    return nb_doors;
}

int **get_all_doors(room_t *room)
{
    size_t nb = nb_doors(room);
    int **doors = NULL;
    size_t j = 0;

    doors = malloc(sizeof(int *) * nb);
    if (!doors)
        return NULL;
    for (size_t y = 0; y < room->size_h; y++){
        if (get_door(room, &j, y, doors) == false)
            return NULL;
    }
    room->nb_doors = nb;
    return doors;
}

rooms_t *parsing_door(rooms_t *rooms)
{
    for (size_t i = 0; i < rooms->count; i++){
        rooms->rooms[i].door_pos = get_all_doors(&rooms->rooms[i]);
        if (rooms->rooms[i].door_pos == NULL)
            return NULL;
    }
    return rooms;
}
