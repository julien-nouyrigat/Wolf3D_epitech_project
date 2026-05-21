/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** init_epoll
*/

#include "network.h"

static int create_epoll(server_t *serv)
{
    serv->fd_epoll = epoll_create1(0);
    if (serv->fd_epoll < 0) {
        printf("[EPOLL] La création du socket a échoué\n");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

int init_epoll(server_t *serv)
{
    struct epoll_event event = {0};

    if (create_epoll(serv) == EXIT_FAILURE)
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
