/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** add_room
*/

#include <string.h>
#include <stdlib.h>
#include "server.h"
#include "wolf.h"

static char *gener_id(void)
{
    char *id = malloc(sizeof(char) * (SIZE_ID + 1));

    for (int i = 0; i < SIZE_ID; i++) {
        id[i] = CHAR_ID[rand() % 36];
    }
    id[SIZE_ID] = '\0';
    return id;
}

room_serv_t *new_room(server_t *serv, client_t *host)
{
    room_serv_t *new = malloc(sizeof(*new));
    char *id = NULL;

    if (new == NULL)
        return NULL;
    id = gener_id();
    strncpy(new->id_room, id, SIZE_ID);
    new->id_room[SIZE_ID] = '\0';
    strncpy(new->host_name, host->state.pseudo, USERNAME_SIZE - 1);
    new->host_name[USERNAME_SIZE - 1] = '\0';
    free(id);
    new->player[0] = host;
    new->nb_players = 1;
    new->is_launch = false;
    new->next = serv->rooms;
    serv->rooms = new;
    host->in_room = true;
    return new;
}
