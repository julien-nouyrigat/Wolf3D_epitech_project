/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** init_server
*/

#include <string.h>
#include <stdlib.h>
#include "server.h"
#include "wolf.h"

int init_server(server_t *serv)
{
    memset(serv, 0, sizeof(server_t));
    get_ip(serv);
    if (init_tcp(serv) == EXIT_FAILURE)
        return EXIT_FAILURE;
    if (init_epoll(serv) == EXIT_FAILURE)
        return EXIT_FAILURE;
    init_room(serv);
    memset(serv->clients, 0, sizeof(serv->clients));
    return EXIT_SUCCESS;
}
