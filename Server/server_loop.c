/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** server_loop
*/

#include <stdlib.h>
#include <unistd.h>
#include "wolf.h"
#include "server.h"

static int manage_fd(servert_t *serv, int fd)
{
    if (fd == STDIN_FILENO) {
        if (check_request(serv) == EXIT_PROG)
            return EXIT_PROG;
    } else if (fd == serv->sock_tcp)
        accept_client(serv);
    else
        manage_client(serv, fd);
    return EXIT_SUCCESS;
}

static int event_loop(servert_t *serv, struct epoll_event *event, int fd,
    int n_event)
{
    for (size_t i = 0; i < (size_t)n_event; i++) {
        fd = event[i].data.fd;
        if (manage_fd(serv, fd) == EXIT_PROG)
            return EXIT_PROG;
    }
    return EXIT_SUCCESS;
}

int server_loop(servert_t *serv)
{
    struct epoll_event *event = calloc(EPOLL_EVENT, sizeof(struct epoll_event));
    int n_event = 0;
    int fd = 0;

    printf("\033[31m""IP du serveur : %s\n""\033[0m", serv->ip);
    while (1) {
        n_event = epoll_wait(serv->fd_epoll, event, EPOLL_EVENT, -1);
        if (event_loop(serv, event, fd, n_event) == EXIT_PROG) {
            free(event);
            return EXIT_PROG;
        }
    }
    return EXIT_SUCCESS;
}
