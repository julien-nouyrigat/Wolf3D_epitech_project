/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** server_loop
*/

#include "network.h"

static int manage_fd(int fd, server_t *serv)
{
    if (fd == STDIN_FILENO) {
        if (manage_stdin(serv) == EXIT_PROG)
            return EXIT_PROG;
    } else if (fd == serv->sock_tcp) {
        accept_client(serv);
    } else {
        manage_client(serv, fd);
    }
    return EXIT_SUCCESS;
}

static int event_loop(server_t *serv, struct epoll_event *event, int fd,
    int n_event)
{
    for (size_t i = 0; i < (size_t)n_event; i++) {
        fd = event[i].data.fd;
        if (manage_fd(fd, serv) == EXIT_PROG)
            return EXIT_PROG;
    }
    if (serv->is_launch == true) {
        manage_udp(serv);
    }
    return EXIT_SUCCESS;
}

int server_loop(server_t *serv)
{
    struct epoll_event *event = calloc(MAX_EVENTS, sizeof(*event));
    int n_event = 0;
    int fd = 0;

    printf("\033[33m""IP DU SERV : %s\n""\033[0m", serv->ip);
    while (1) {
        n_event = epoll_wait(serv->fd_epoll, event, MAX_EVENTS, -1);
        if (event_loop(serv, event, fd, n_event) == EXIT_PROG)
            return EXIT_PROG;
    }
    return EXIT_SUCCESS;
}
