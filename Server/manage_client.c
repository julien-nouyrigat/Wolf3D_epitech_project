/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** manage_client
*/

#include "server.h"
#include "wolf.h"

static void fill_client(servert_t *serv, int fd, struct sockaddr_in *sa_in,
    int i)
{
    struct epoll_event event = {0};

    serv->clients[i].fd_tcp = fd;
    serv->clients[i].sa_in = *sa_in;
    serv->clients[i].client_id = i;
    serv->nb_clients++;
    event.events = EPOLLIN;
    event.data.fd = fd;
    epoll_ctl(serv->fd_epoll, EPOLL_CTL_ADD, fd, &event);
}

int accept_client(servert_t *serv)
{
    struct sockaddr_in sa_in = {0};
    socklen_t len_sa_in = sizeof(sa_in);
    int fd = accept(serv->sock_tcp, (struct sockaddr *)&sa_in, &len_sa_in);

    if (fd < 0)
        return EXIT_FAILURE;
    for (size_t i = 0; i < CLIENT_MAX; i++) {
        if (serv->clients[i].fd_tcp <= 0) {
            fill_client(serv, fd, &sa_in, i);
        }
    }
    return EXIT_SUCCESS;
}

int manage_client(servert_t *serv, int fd)
{
    return EXIT_SUCCESS;
}
