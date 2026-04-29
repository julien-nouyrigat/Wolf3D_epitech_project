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
    #define NB_MAPS 3
    #define ELEMENTS 2

enum types_of_maps {
    CASTLE = 1,
    LAB,
    MANOR,
};

enum text_enum {
    WALL,
    FLOOR,
    CEILING,
    CASTLE_WALL,
    CASTLE_FLOOR,
    CASTLE_CEILLING,
    LAB_WALL,
    LAB_FLOOR,
    LAB_CEILLING,
    MANOR_WALL,
    MANOR_FLOOR,
    MANOR_CEILLING,
    HEALTH_CROSS,
    STAMINA_LIGHTNING,
    END_TEXTS
};

typedef struct textures_s {
    char *texture;
}textures_t;

static const textures_t textures[END_TEXTS - TEXT_TYPES + ELEMENTS] = {
    {"./assets/rooms/castle_wall.jpg"},
    {"./assets/rooms/castle_floor.jpg"},
    {"./assets/rooms/castle_ceilling.png"},
    {"./assets/rooms/lab_wall.jpg"},
    {"./assets/rooms/lab_floor.jpg"},
    {"./assets/rooms/lab_ceilling.jpg"},
    {"./assets/rooms/manor_wall.jpg"},
    {"./assets/rooms/manor_floor.png"},
    {"./assets/rooms/manor_ceilling.jpg"},
    {"./assets/image/health_cross.png"},
    {"./assets/image/stamina_ligthning.png"}
};

#endif /* TEXTURES_H_ */
