/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** create_new_monster
*/

#include <time.h>
#include <stdlib.h>

#include "enemies.h"
#include "wolf.h"

static void fill_mob_data(enemy_t **mob, map_t **map)
{
    (*mob)->monster->health = mob_data[(*mob)->type].health;
    (*mob)->monster->damage = mob_data[(*mob)->type].damage;
    (*mob)->monster->range = mob_data[(*mob)->type].range;
    (*mob)->monster->speed = mob_data[(*mob)->type].speed;
    (*mob)->monster->cooldown = mob_data[(*mob)->type].cooldown;
    (*mob)->monster->loot_value = mob_data[(*mob)->type].loot_value;
    (*mob)->monster->can_attack = false;
    (*mob)->monster->position = (sfVector2f){31 * TILE_SIZE, 31 * TILE_SIZE};
    // à changer après, prédef pout le moment *émoji fusée*
    (*mob)->monster->sprite = sfSprite_create();
    sfSprite_setTexture((*mob)->monster->sprite,
        (*map)->level->mob_texts[(*mob)->type], true);
}

int create_new_monster(map_t **map)
{
    enemy_t *new = calloc(sizeof(enemy_t), 1);
    time_t *timer = NULL;

    if (new == NULL)
        return EXIT_FAILURE;
    new->monster = calloc(sizeof(monster_t), 1);
    if (new->monster == NULL) {
        free(new);
        return EXIT_FAILURE;
    }
    srand(time(timer));
    new->type = rand() % NB_ENEMIES;
    fill_mob_data(&new, map);
    new->next = (*map)->level->enemies;
    (*map)->level->enemies = new;
    return EXIT_SUCCESS;
}
