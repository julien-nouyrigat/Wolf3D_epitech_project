/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** manage_enemies
*/

#include <math.h>

#include "wolf.h"

static bool is_wall(monster_t *mob, player_t *player,
    sfVector2f *to_player_dir)
{
    (void)mob;
    (void)player;
    (void)to_player_dir;
    return false;
}

static sfVector2f get_to_player_dir(monster_t *mob, player_t *player)
{
    float x = player->position.x - mob->position.x;
    float y = player->position.y - mob->position.y;
    float len = sqrt(x * x + y * y);
    sfVector2f to_player_dir = (sfVector2f){x / len, y / len};

    return to_player_dir;
}

static int get_verif(float pos, float dir, monster_t *mob)
{
    int res = (int)((pos + dir * mob->speed) / TILE_SIZE);

    return res;
}

static void move_mob(monster_t *mob, map_t *map, sfVector2f *movement_dir)
{
    sfVector2f verif = {0, 0};

    verif.x = get_verif(mob->position.x, movement_dir->x, mob);
    verif.y = get_verif(mob->position.y, movement_dir->y, mob);
    if (map->int_map[(int)(mob->position.y / TILE_SIZE)]
        [(int)verif.x] != WALL) {
        mob->position.x += movement_dir->x * mob->speed;
    }
    if (map->int_map[(int)verif.y]
        [(int)(mob->position.x / TILE_SIZE)] != WALL) {
        mob->position.y += movement_dir->y * mob->speed;
    }
}

static void handle_mob_movements(monster_t *mob, player_t *player, map_t *map)
{
    sfVector2f to_player_dir = get_to_player_dir(mob, player);
    float to_player_dist = sqrt(
        pow(player->position.x - mob->position.x, 2) +
        pow(player->position.y - mob->position.y, 2));

    if (to_player_dist <= PLAYER_SIZE * MIN_DIST)
        return;
    if (to_player_dist / TILE_SIZE <= SEEING_DIST &&
        !is_wall(mob, player, &to_player_dir))
        move_mob(mob, map, &to_player_dir);
}

static void define_mob_comportment(enemy_t *mob, player_t *player, map_t *map)
{
    if (mob->type == ENDERMAN)
        handle_enderman(mob->monster, player, map);
    else
        handle_mob_movements(mob->monster, player, map);
}

void manage_enemies(window_t __attribute_maybe_unused__ *win, player_t *player,
    map_t *map)
{
    enemy_t *tmp = map->level->enemies;

    for (; tmp != NULL; tmp = tmp->next) {
        if (tmp->monster->health > 0)
            define_mob_comportment(tmp, player, map);
    }
}
