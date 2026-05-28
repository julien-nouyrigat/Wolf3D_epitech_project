/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** add_to_entity_list
*/

#include <stdlib.h>
#include "entity_display.h"
#include "wolf.h"

int add_monster_entity(enemy_t *mob, entities_t **head,
    player_t *player, map_t *map)
{
    entities_t *new = NULL;

    if (mob->monster->health <= 0)
        return EXIT_SUCCESS;
    new = calloc(sizeof(entities_t), 1);
    if (new == NULL)
        return EXIT_FAILURE;
    new->position = mob->monster->position;
    new->direction = mob->monster->direction;
    new->text = map->level->mob_texts[mob->type];
    new->p_dist = sqrt(
        pow(player->pos_f.x - mob->monster->position.x / TILE_SIZE, 2) +
        pow(player->pos_f.y - mob->monster->position.y / TILE_SIZE, 2));
    new->next = *head;
    *head = new;
    return EXIT_SUCCESS;
}

int add_items_entity(loot_t *loot, entities_t **head,
    player_t *player)
{
    entities_t *new = NULL;

    if (loot->item->is_grab)
        return EXIT_SUCCESS;
    new = calloc(sizeof(entities_t), 1);
    if (new == NULL)
        return EXIT_FAILURE;
    new->position = loot->item->position;
    new->direction = loot->item->direction;
    new->text = loot->item->textures;
    new->p_dist = sqrt(
        pow(player->pos_f.x - loot->item->position.x / TILE_SIZE, 2) +
        pow(player->pos_f.y - loot->item->position.y / TILE_SIZE, 2));
    new->next = *head;
    *head = new;
    return EXIT_SUCCESS;
}

void add_player_entity(entities_t **head, player_t *player,
    window_t *win, size_t i)
{
    entities_t *new_player = calloc(1, sizeof(entities_t));

    if (new_player == NULL)
        return;
    new_player->position = (sfVector2f){win->client->other[i].pos_x,
        win->client->other[i].pos_y};
    new_player->text = win->client->t_player;
    new_player->p_dist = sqrt(
        pow(player->pos_f.x - win->client->other[i].pos_tile_x, 2) +
        pow(player->pos_f.y - win->client->other[i].pos_tile_y, 2));
    new_player->next = *head;
    *head = new_player;
}

void free_entities(entities_t *head)
{
    entities_t *tmp;

    while (head) {
        tmp = head->next;
        free(head);
        head = tmp;
    }
}
