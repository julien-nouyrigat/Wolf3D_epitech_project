/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** free_items_list
*/

#include <stdlib.h>

#include "wolf.h"

static void free_item(item_t *item)
{
    sfTexture_destroy(item->textures);
    free(item);
}

void free_items_list(map_t *map)
{
    loot_t *prec = NULL;

    while (map->level->loot != NULL) {
        prec = map->level->loot;
        map->level->loot = map->level->loot->next;
        free_item(prec->item);
        free(prec);
    }
    map->level->loot = NULL;
}
