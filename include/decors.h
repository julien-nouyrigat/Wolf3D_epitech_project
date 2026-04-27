/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** decors
*/

#ifndef DECORS_H_
    #define DECORS_H_

    #define FILE_IMG(file) sfImage_createFromFile(file)
    #define DECOR_TYPES 3
    #define CASTLE 1

enum decors_enum {
    WALL,
    FLOOR,
    CEILING,
    CASTLE_WALL,
    CASTLE_FLOOR,
    CASTLE_CEILLING,
    END_DECORS
};

typedef struct decors_s {
    char *decor;
}decors_t;

static const decors_t decors[END_DECORS - DECOR_TYPES] = {
    {"./assets/rooms/castle_wall.jpg"},
    {"./assets/rooms/castle_floor.jpg"},
    {"./assets/rooms/castle_ceilling.png"},
};

#endif /* DECORS_H_ */
