/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** recv_rooms
*/

#include <string.h>
#include <stdlib.h>
#include "server.h"
#include "wolf.h"

void send_create_room(client_info_t *client)
{
    req_create_room_t req = {0};

    req.type = CREATE_ROOM;
    send(client->sock_tcp, &req, sizeof(req), 0);
}

void send_join_room(client_info_t *client, char *id_room)
{
    req_join_room_t req = {0};

    req.type = JOIN_ROOM;
    strncpy(req.id_room, id_room, SIZE_ID);
    req.id_room[SIZE_ID] = '\0';
    send(client->sock_tcp, &req, sizeof(req), 0);
}

void recv_rooms(client_info_t *client)
{
    room_recv_t *buff = malloc(sizeof(*buff));
    int n_bytes = recv(client->sock_tcp, buff, sizeof(*buff), MSG_DONTWAIT);

    if (client->rooms == NULL)
        return;
    if (buff == NULL)
        return;
    if (n_bytes <= 0)
        return;
    manage_update_room(&client->rooms, buff);
}
