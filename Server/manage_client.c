/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** manage_client
*/

#include <string.h>
#include <unistd.h>
#include "server.h"
#include "wolf.h"

static void client_create_room(server_t *serv, client_t *client)
{
    room_serv_t *room = NULL;

    if (client->in_room)
        return;
    room = new_room(serv, client);
    if (room == NULL)
        return;
    broadcast_rooms(serv, room);
    printf("new room\n");
}

static void check_availability(server_t *serv, room_serv_t *tmp,
    client_t *client)
{
    if (tmp->nb_players >= MAX_PLAYER || tmp->is_launch)
        return;
    tmp->player[tmp->nb_players] = client;
    tmp->nb_players++;
    client->in_room = true;
    memcpy(client->id_room, tmp->id_room, SIZE_ID + 1);
    broadcast_rooms(serv, tmp);
    return;
}

static void client_join_room(server_t *serv, client_t *client,
    req_join_room_t *join)
{
    room_serv_t *tmp = serv->rooms;

    while (tmp != NULL) {
        if (strncmp(tmp->id_room, join->id_room, SIZE_ID) == 0) {
            check_availability(serv, tmp, client);
            return;
        }
        tmp = tmp->next;
    }
}

static void remove_client(server_t *serv, int fd)
{
    for (size_t i = 0; i < MAX_CLIENT; i++) {
        if (serv->clients[i].fd_tcp == fd) {
            epoll_ctl(serv->fd_epoll, EPOLL_CTL_DEL, fd, NULL);
            close(fd);
            serv->clients[i].fd_tcp = 0;
            serv->nb_client--;
        }
    }
}

void manage_client(server_t *serv, int fd)
{
    uint8_t buff[BUFSIZ];
    int nb_bytes = recv(fd, buff, BUFSIZ - 1, 0);
    client_t *client = NULL;

    if (nb_bytes <= 0) {
        remove_client(serv, fd);
        return;
    }
    for (size_t i = 0; i < MAX_CLIENT; i++) {
        if (serv->clients[i].fd_tcp == fd) {
            client = &serv->clients[i];
            break;
        }
    }
    if (client == NULL)
        return;
    if (buff[0] == CREATE_ROOM)
        client_create_room(serv, client);
    if (buff[0] == JOIN_ROOM)
        client_join_room(serv, client, (req_join_room_t *)buff);
}
