/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** Room
*/

#ifndef ROOM_H_
    #define ROOM_H_
    #define SPAWN 0
    #define CENTER 4
    #define SIZE_SMAP 10
    #define NO_ROOM -1
    #define NB_DIR 4
    #define VISITED 2
    #define TOP 0
    #define LEFT 0
    #define DOWN 6
    #define RIGHT 6
    #define MID 3
    #define HIDE '.'
    #define MUL 7
    #define SIZE_MAP (SIZE_SMAP * MUL)

    #include <stdlib.h>
typedef enum dir {
    SOUTH,
    EAST,
    WEST,
    NORTH
} dir_t;

typedef enum tiles {
    EMPTY,
    WALLS,
    DOOR
} tiles_t;

typedef struct room {
    int **room;
    int nb_tiles;
    int **door_pos;
    int nb_doors;
    size_t size_h;
    size_t size_w;
} room_t;

typedef struct rooms {
    room_t *rooms;
    size_t count;
} rooms_t;

typedef struct pos {
    int x;
    int y;
} pos_t;

typedef struct new_pos {
    int nx;
    int ny;
} new_pos_t;

typedef struct ctx {
    int **map;
    rooms_t *rooms;
} ctx_t;

int **create_map(size_t nb_rooms);
void free_mtrx(int **mtrx, size_t size);
void free_rooms(rooms_t *rooms);
void free_array(char **line);
char **my_str_to_wa(char *str);
int **genrating_map(rooms_t *rooms, int nb_rooms);
rooms_t *parsing_door(rooms_t *rooms);
rooms_t *pars_map(rooms_t *rooms);
#endif /* ROOM_H_ */
