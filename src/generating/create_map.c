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

static void free_map(int **map, size_t i)
{
    for (size_t k = 0; k < i; k++)
        free(map[k]);
    free(map);
}

int **init_big_map(void)
{
    int **map = malloc(sizeof(int *) * SIZE_MAP);

    if (!map)
        return NULL;
    for (size_t i = 0; i < SIZE_MAP; i++){
        map[i] = malloc(sizeof(int) * SIZE_MAP);
        if (!map[i]){
            free_map(map, i);
            return NULL;
        }
        for (size_t j = 0; j < SIZE_MAP; j++)
            map[i][j] = EMPTY;
    }
    return map;
}

static void set_tile(int room_id, ctx_t *ctx, pos_t *pos, pos_t *s_pos)
{
    if (room_id == NO_ROOM){
        ctx->map[pos->y][pos->x] = 3;
        return;
    }
    ctx->map[pos->y][pos->x] =
        ctx->rooms->rooms[room_id].room[s_pos->y][s_pos->x];
}

static void fill_block(int room_id, ctx_t *ctx,
    pos_t *start)
{
    pos_t pos = {0};
    pos_t small_pos = {0};

    for (size_t i = 0; i < MUL; i++) {
        for (size_t j = 0; j < MUL; j++) {
            pos.y = start->y + i;
            pos.x = start->x + j;
            small_pos.y = i;
            small_pos.x = j;
            set_tile(room_id, ctx, &pos, &small_pos);
        }
    }
}

int **fill_map(int **map, int **smap, rooms_t *rooms)
{
    ctx_t ctx = {map, rooms};
    pos_t start = {0};

    for (int i = 0; i < SIZE_SMAP; i++) {
        for (int j = 0; j < SIZE_SMAP; j++) {
            start.y = i * MUL;
            start.x = j * MUL;
            fill_block(smap[i][j], &ctx, &start);
        }
    }
    return ctx.map;
}

static bool is_solo_doors(int **map, size_t i, size_t j)
{
    int ni = 0;
    int nj = 0;
    int dirs[NB_DIR][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    if (map[i][j] != DOOR)
        return false;
    for (size_t d = 0; d < NB_DIR; d++){
        ni = i + dirs[d][0];
        nj = j + dirs[d][1];
        if (ni < 0 || nj < 0 || ni >= SIZE_MAP || nj >= SIZE_MAP)
            continue;
        if (map[ni][nj] == DOOR)
            return false;
    }
    return true;
}

static void close_doors_loop(int **map, size_t i)
{
    for (size_t j = 0; j < SIZE_MAP; j++){
        if (is_solo_doors(map, i, j) == true)
            map[i][j] = WALL;
    }
}

void close_doors(int **map)
{
    for (size_t i = 0; i < SIZE_MAP; i++)
        close_doors_loop(map, i);
}

int **create_big_map(int **smap, rooms_t *rooms)
{
    int **map = init_big_map();

    if (map == NULL)
        return NULL;
    map = fill_map(map, smap, rooms);
    free_mtrx(smap, SIZE_SMAP);
    free_rooms(rooms);
    close_doors(map);
    return map;
}

int **create_map(size_t nb_rooms)
{
    rooms_t *rooms = malloc(sizeof(rooms_t));
    int **smap = NULL;
    int **map = NULL;

    rooms = pars_map(rooms);
    parsing_door(rooms);
    smap = genrating_map(rooms, nb_rooms);
    map = create_big_map(smap, rooms);
    if (smap == NULL)
        return NULL;
    return map;
}

/*for (int i = 0; i < SIZE_MAP; i++){
        for (int j = 0; j < SIZE_MAP; j++){
            if (map[i][j] == 1){
                 printf("\033[34;01m%i\033[00m", map[i][j]);
                 continue;
            }
            if (map[i][j] == 2){
                 printf("\e[0;31m%i\033[00m", map[i][j]);
                 continue;
            }
            if (map[i][j] == 3){
                 printf("%i", map[i][j]);
                 continue;
            }
            printf("%i", map[i][j]);
        }
        printf("\n");
    }*/
