/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** enemies
*/

#ifndef ENEMIES_H_
    #define ENEMIES_H_

    #include "wolf.h"

typedef enum {
    CLOWN,
    NUN,
    HEADMAN,
    WITCH,
    CYCLOP,
    CHEF,
    ENDERMAN
} monster_type_t;

typedef struct monster_s {
    size_t life;
    size_t damage;
    size_t range;
    size_t speed;
    sfVector2f position;
    sfVector2f direction;
    sfSprite *sprite;
} monster_t;

typedef struct enemy_s {
    size_t type;
    struct monster_t *monster;
    struct enemy_s *next;
} enemy_t;

#endif /* ENEMIES_H_ */
