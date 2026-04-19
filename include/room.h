/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** Room
*/

#ifndef ROOM_H_
    #define ROOM_H_
    #define SPAWN 0

typedef enum tiles {
    EMPTY,
    WALL,
    DOOR
} tiles_t;

typedef struct room {
    int **room;
    int nb_tiles;
    int **door_pos;
    int nb_doors;
    size_t size_h;
    size_t size_w;
    char *name;
} room_t;

typedef struct rooms {
    room_t *rooms;
    size_t count;
} rooms_t;

int **genrating_map(rooms_t *rooms, int nb_rooms);
rooms_t *parsing_door(rooms_t *rooms);
rooms_t *pars_map(rooms_t *rooms);
#endif /* ROOM_H_ */
