/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** loop_serv
*/

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "server.h"
#include "wolf.h"

static void display_ip(server_t *serv)
{
    printf("\033[31m""IP du serveur : %s\n""\033[0m", serv->ip);
}

static void displa_list(server_t *serv)
{
    room_serv_t *tmp = serv->rooms;

    if (tmp == NULL)
        return;
    while (tmp != NULL) {
        for (size_t i = 0; i < tmp->nb_players; i++) {
            printf("\033[33m""Room[%s]:\n""\033[0m", tmp->id_room);
            printf("\033[37m""  - %s\n""\033[33m",
                tmp->player[i]->state.pseudo);
        }
        tmp = tmp->next;
    }
}

static int check_request(server_t *serv)
{
    char input[BUFSIZ];
    int n_bytes = read(STDIN_FILENO, input, BUFSIZ - 1);

    if (n_bytes <= 0)
        return EXIT_FAILURE;
    input[n_bytes] = '\0';
    if (strncmp(input, "ip", strlen("ip")) == 0)
        display_ip(serv);
    if (strncmp(input, "list", strlen("list")) == 0)
        displa_list(serv);
    if (strncmp(input, "exit", strlen("exit")) == 0)
        return EXIT_PROG;
    return EXIT_SUCCESS;
}

static void fill_client(server_t *serv, int fd, struct sockaddr_in *sa_in,
    int i)
{
    struct epoll_event event = {0};

    serv->clients[i].fd_tcp = fd;
    serv->clients[i].sa_in = *sa_in;
    serv->clients[i].id = i;
    serv->nb_client++;
    event.events = EPOLLIN;
    event.data.fd = fd;
    epoll_ctl(serv->fd_epoll, EPOLL_CTL_ADD, fd, &event);
    send_room(serv, fd);
}

static void accept_client(server_t *serv)
{
    struct sockaddr_in sa_in;
    socklen_t len_sa_in = sizeof(sa_in);
    int fd = accept(serv->sock_tcp, (struct sockaddr *)&sa_in, &len_sa_in);

    if (fd < 0)
        return;
    for (int i = 0; i < MAX_CLIENT; i++) {
        if (serv->clients[i].fd_tcp <= 0) {
            fill_client(serv, fd, &sa_in, i);
            return;
        }
    }
    close(fd);
}

static int manage_fd(server_t *serv, int fd)
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

static int event_loop(server_t *serv, struct epoll_event *event, int fd,
    int n_event)
{
    for (int i = 0; i < n_event; i++) {
        fd = event[i].data.fd;
        if (manage_fd(serv, fd) == EXIT_PROG)
            return EXIT_PROG;
    }
    return EXIT_SUCCESS;
}

int loop_server(server_t *serv)
{
    struct epoll_event *event = calloc(EPOLL_EVENT, sizeof(struct epoll_event));
    int n_event;
    int fd = 0;

    while (1) {
        n_event = epoll_wait(serv->fd_epoll, event, EPOLL_EVENT, -1);
        if (event_loop(serv, event, fd, n_event) == EXIT_PROG) {
            free(event);
            return EXIT_PROG;
        }
    }
    return EXIT_SUCCESS;
}
