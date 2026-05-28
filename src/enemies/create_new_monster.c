/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** create_new_monster
*/

#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#include "enemies.h"
#include "wolf.h"

static bool is_valid_spawn(int x, int y, map_t **map)
{
    if ((*map)->int_map[y][x] != 0)
        return false;
    if ((x >= PLAYER_SPAWN - 10 && x <= PLAYER_SPAWN + 10) ||
        (y >= PLAYER_SPAWN - 10 && y <= PLAYER_SPAWN + 10))
        return false;
    return true;
}

static sfVector2f get_monster_pos(map_t **map)
{
    int x = 0;
    int y = 0;

    x = rand() % MAP_SIZE;
    y = rand() % MAP_SIZE;
    while (!is_valid_spawn(x, y, map)) {
        x = rand() % MAP_SIZE;
        y = rand() % MAP_SIZE;
    }
    return (sfVector2f){x * TILE_SIZE + TILE_SIZE / 2,
        y * TILE_SIZE + TILE_SIZE / 2};
}

static void fill_mob_data(enemy_t **mob, map_t **map)
{
    (*mob)->monster->health = mob_data[(*mob)->type].health;
    (*mob)->monster->damage = mob_data[(*mob)->type].damage;
    (*mob)->monster->range = mob_data[(*mob)->type].range;
    (*mob)->monster->speed = mob_data[(*mob)->type].speed;
    (*mob)->monster->cooldown = mob_data[(*mob)->type].cooldown;
    (*mob)->monster->loot_value = mob_data[(*mob)->type].loot_value;
    (*mob)->monster->can_attack = false;
    (*mob)->monster->position = get_monster_pos(map);
    (*mob)->monster->direction = (sfVector2f){0, 0};
    (*mob)->monster->sprite = sfSprite_create();
    sfSprite_setTexture((*mob)->monster->sprite,
        (*map)->level->mob_texts[(*mob)->type], true);
    (*mob)->monster->mob_clock = sfClock_create();
    (*mob)->monster->sound_effect =
        sfMusic_createFromFile(mob_sounds_effects[(*mob)->type].music);
}

int create_new_monster(map_t **map)
{
    enemy_t *new = calloc(sizeof(enemy_t), 1);

    if (new == NULL)
        return EXIT_FAILURE;
    new->monster = calloc(sizeof(monster_t), 1);
    if (new->monster == NULL) {
        free(new);
        return EXIT_FAILURE;
    }
    new->type = rand() % NB_ENEMIES;
    fill_mob_data(&new, map);
    new->next = (*map)->level->enemies;
    (*map)->level->enemies = new;
    return EXIT_SUCCESS;
}
