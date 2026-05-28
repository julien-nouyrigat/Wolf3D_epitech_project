/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** add_to_entity_list
*/

#include <stdlib.h>
#include "entity_display.h"
#include "wolf.h"

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
