/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** enemies
*/

#ifndef ENEMIES_H_
    #define ENEMIES_H_

    #include "textures.h"
    #include "wolf.h"

    #define FOG_COEF 1000

    #define INFINITE_RANGE 10000000000

    #define SMALL_LOOT 2000
    #define MEDIUM_LOOT 4000
    #define LARGE_LOOT 6000

    #define MEDIUM_HEALTH 150
    #define LARGE_HEALTH 250
    #define VERY_LARGE_HEALTH 500

    #define SEEING_DIST 5
    #define MIN_DIST 8

typedef enum {
    CLOWN,
    NUN,
    HEADMAN,
    WITCH,
    CYCLOPS,
    CHEF,
    ENDERMAN,
    NB_ENEMIES
} monster_type_t;

static const textures_t mob_textures[NB_ENEMIES] = {
    {"./assets/monsters/clown.png"},
    {"./assets/monsters/nun.png"},
    {"./assets/monsters/headman.png"},
    {"./assets/monsters/witch.png"},
    {"./assets/monsters/cyclops.png"},
    {"./assets/monsters/chef.png"},
    {"./assets/monsters/enderman.png"}
};

typedef struct monster_s {
    size_t health;
    size_t damage;
    size_t range;
    size_t speed;
    float cooldown;
    size_t loot_value;
    bool can_attack;
    sfVector2f position;
    sfVector2f direction;
    sfSprite *sprite;
    float order_dist;
} monster_t;

typedef struct enemy_s {
    size_t type;
    monster_t *monster;
    struct enemy_s *next;
} enemy_t;

typedef struct mob_data_s {
    size_t type;
    size_t health;
    size_t damage;
    size_t range;
    size_t speed;
    float cooldown;
    size_t loot_value;
} mob_data_t;

typedef struct {
    int screen_x;
    int width;
    int height;
    int start_x;
    int end_x;
    int start_y;
    int end_y;
    sfTexture *mob_text;
    float dist;
} sprite_proj_t;

static const mob_data_t mob_data[NB_ENEMIES] = {
    {CLOWN, LARGE_HEALTH, 100, INFINITE_RANGE, 5, 7.0, LARGE_LOOT},
    {NUN, LARGE_HEALTH, 100, 15, 6, 3.0, LARGE_LOOT},
    {HEADMAN, LARGE_HEALTH, 50, 15, 6, 3.0, LARGE_LOOT},
    {WITCH, VERY_LARGE_HEALTH, 125, 15, 5, 4.0, LARGE_LOOT},
    {CYCLOPS, VERY_LARGE_HEALTH, 100, 20, 3, 6.0, LARGE_LOOT},
    {CHEF, MEDIUM_HEALTH, 10, 15, 5, 0.5, MEDIUM_LOOT},
    {ENDERMAN, MEDIUM_HEALTH, 200, INFINITE_RANGE, 0, 3.5, SMALL_LOOT}
};

enemy_t *sort_enemies(enemy_t *head);

#endif /* ENEMIES_H_ */
