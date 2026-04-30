/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** broadcast
*/

#include "server.h"
#include "wolf.h"

void broadcast_rooms(server_t *serv, room_serv_t *room)
{
    fill_room_to_send(&serv->room_to_send, room);
    for (size_t i = 0; i < (size_t)serv->nb_client; i++) {
        if (serv->clients[i].fd_tcp > 0)
            send(serv->clients[i].fd_tcp, &serv->room_to_send,
                sizeof(room_info_send_t), 0);
    }
}
