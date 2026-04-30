/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** send_rooms
*/

#include <string.h>
#include "server.h"
#include "wolf.h"

void fill_room_to_send(room_info_send_t *to_send, room_serv_t *room)
{
    strncpy(to_send->id_room, room->id_room, SIZE_ID);
    to_send->id_room[SIZE_ID] = '\0';
    strncpy(to_send->host_name, room->host_name, USERNAME_SIZE);
    to_send->host_name[USERNAME_SIZE - 1] = '\0';
    to_send->nb_players = room->nb_players;
    to_send->is_launch = room->is_launch;
}

void send_room(server_t *serv, int fd)
{
    room_serv_t *tmp = serv->rooms;

    while (tmp != NULL) {
        fill_room_to_send(&serv->room_to_send, tmp);
        send(fd, &serv->room_to_send, sizeof(room_info_send_t), 0);
        tmp = tmp->next;
    }
}
