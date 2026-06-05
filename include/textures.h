/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** textures
*/

#ifndef TEXTURES_H_
    #define TEXTURES_H_

    #define FILE_TEXT(file) sfTexture_createFromFile(file, NULL)
    #define TEXT_TYPES 6
    #define NB_MAPS 3
    #define TOTAL_TEXTURES (END_TEXTS - TEXT_TYPES)
    #define MAP_WALL 1
    #define MAP_WALL1 4
    #define MAP_EX 5
    #define MAP_WALL2 6

enum types_of_maps {
    CASTLE = 1,
    LAB,
    MANOR
};

enum text_enum {
    WALL,
    WALL1,
    WALL2,
    EX,
    FLOOR,
    CEILING,
    CASTLE_WALL,
    CASTLE_WALL1,
    CASTLE_WALL2,
    CASTLE_EX,
    CASTLE_FLOOR,
    CASTLE_CEILLING,
    LAB_WALL,
    LAB_WALL1,
    LAB_WALL2,
    LAB_EX,
    LAB_FLOOR,
    LAB_CEILLING,
    MANOR_WALL,
    MANOR_WALL1,
    MANOR_WALL2,
    MANOR_EX,
    MANOR_FLOOR,
    MANOR_CEILLING,
    HEALTH_ICON,
    STAMINA_ICON,
    END_TEXTS
};

typedef struct textures_s {
    char *texture;
} textures_t;

static const textures_t textures[TOTAL_TEXTURES] = {
    {"./assets/rooms/castle_wall.jpg"},
    {"./assets/rooms/castle_wall1.png"},
    {"./assets/rooms/castle_wall2.png"},
    {"./assets/rooms/castle_wall_extract.png"},
    {"./assets/rooms/castle_floor.jpg"},
    {"./assets/rooms/castle_ceilling.png"},
    {"./assets/rooms/lab_wall.jpg"},
    {"./assets/rooms/lab_wall1.png"},
    {"./assets/rooms/lab_wall2.png"},
    {"./assets/rooms/lab_wall_extract.png"},
    {"./assets/rooms/lab_floor.jpg"},
    {"./assets/rooms/lab_ceilling.jpg"},
    {"./assets/rooms/manor_wall.jpg"},
    {"./assets/rooms/manor_wall1.png"},
    {"./assets/rooms/manor_wall2.png"},
    {"./assets/rooms/manor_wall_extract.png"},
    {"./assets/rooms/manor_floor.png"},
    {"./assets/rooms/manor_ceilling.jpg"},
    {"./assets/image/health_cross.png"},
    {"./assets/image/stamina_ligthning.png"}
};

#endif /* TEXTURES_H_ */
