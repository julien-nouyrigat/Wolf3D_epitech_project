/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** generating
*/
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "wolf.h"
#include "room.h"

void free_mtrx(int **mtrx, size_t size)
{
    for (size_t i = 0; i < size; i++)
        free(mtrx[i]);
    free(mtrx);
}

void free_rooms(rooms_t *rooms)
{
    for (size_t i = 0; i < rooms->count; i++){
        free_mtrx(rooms->rooms[i].door_pos, rooms->rooms[i].nb_doors);
        free_mtrx(rooms->rooms[i].room, rooms->rooms[i].size_h);
    }
    free(rooms->rooms);
    free(rooms);
}
