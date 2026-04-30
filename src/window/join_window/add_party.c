/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** add_room
*/

#include <stdlib.h>
#include <string.h>
#include "wolf.h"

void add_party(lst_room_t **rooms, room_recv_t *room_recv)
{
    lst_room_t *new = malloc(sizeof(*new));

    if (new == NULL)
        return;
    strncpy(new->host_name, room_recv->host_name, USERNAME_SIZE);
    new->host_name[USERNAME_SIZE - 1] = '\0';
    strncpy(new->id_room, room_recv->id_room, SIZE_ID);
    new->id_room[SIZE_ID - 1] = '\0';
    new->is_launch = room_recv->is_launch;
    new->nb_players = room_recv->nb_players;
    new->next = *rooms;
    *rooms = new;
}

void manage_update_room(lst_room_t **rooms, room_recv_t *room_recv)
{
    lst_room_t *tmp = *rooms;

    while (tmp != NULL) {
        if (strncmp(tmp->id_room, room_recv->id_room, SIZE_ID) == 0) {
            tmp->nb_players = room_recv->nb_players;
            tmp->is_launch = room_recv->is_launch;
            return;
        }
        tmp = tmp->next;
    }
    add_party(rooms, room_recv);
}
