/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** textures
*/

#ifndef TEXTURES_H_
    #define TEXTURES_H_

    #define FILE_TEXT(file) sfTexture_createFromFile(file, NULL)
    #define TEXT_TYPES 3
    #define CASTLE 1

enum text_enum {
    WALL,
    FLOOR,
    CEILING,
    CASTLE_WALL,
    CASTLE_FLOOR,
    CASTLE_CEILLING,
    END_TEXTS
};

typedef struct textures_s {
    char *texture;
}textures_t;

static const textures_t textures[END_TEXTS - TEXT_TYPES] = {
    {"./assets/rooms/castle_wall.jpg"},
    {"./assets/rooms/castle_floor.jpg"},
    {"./assets/rooms/castle_ceilling.png"},
};

#endif /* TEXTURES_H_ */
