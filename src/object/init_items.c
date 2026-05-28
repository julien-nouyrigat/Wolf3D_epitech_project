/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** loot
*/

#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#include <math.h>

#include "wolf.h"

static bool is_valid_spawn(int x, int y, map_t **map)
{
    if ((*map)->int_map[y][x] != 0)
        return false;
    if ((x >= PLAYER_SPAWN - 3 && x <= PLAYER_SPAWN + 3) ||
        (y >= PLAYER_SPAWN - 3 && y <= PLAYER_SPAWN + 3))
        return false;
    return true;
}

static sfVector2f get_item_pos(map_t **map)
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

static void fill_item_data(loot_t **loot, map_t **map)
{
    (*loot)->item->durability = item_data[(*loot)->type].durability;
    (*loot)->item->price = item_data[(*loot)->type].price;
    (*loot)->item->weight = item_data[(*loot)->type].weight;
    (*loot)->item->position = get_item_pos(map);
    (*loot)->item->direction = (sfVector2f){0, 0};
    (*loot)->item->textures =
        sfTexture_createFromFile(item_data[(*loot)->type].asset_path, NULL);
    (*loot)->item->is_grab = false;
}

int create_new_item(map_t **map)
{
    loot_t *new = calloc(sizeof(loot_t), 1);

    if (new == NULL)
        return EXIT_FAILURE;
    new->item = calloc(sizeof(item_t), 1);
    if (new->item == NULL) {
        free(new);
        return EXIT_FAILURE;
    }
    new->type = rand() % NB_ITEMS;
    fill_item_data(&new, map);
    new->next = (*map)->level->loot;
    (*map)->level->loot = new;
    return EXIT_SUCCESS;
}
