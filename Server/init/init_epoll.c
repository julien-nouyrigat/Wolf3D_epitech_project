/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** init_udp
*/

#include <fcntl.h>
#include <unistd.h>
#include "server.h"
#include "wolf.h"

int init_epoll(server_t *serv)
{
    struct epoll_event event = {0};

    serv->fd_epoll = epoll_create1(0);
    if (serv->fd_epoll < 0)
        return EXIT_FAILURE;
    event.events = EPOLLIN;
    event.data.fd = serv->sock_tcp;
    if (epoll_ctl(serv->fd_epoll, EPOLL_CTL_ADD, serv->sock_tcp, &event) < 0)
        return EXIT_FAILURE;
    event.events = EPOLLIN;
    event.data.fd = STDIN_FILENO;
    if (epoll_ctl(serv->fd_epoll, EPOLL_CTL_ADD, STDIN_FILENO, &event) < 0)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}
