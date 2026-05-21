/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** manage_stdin
*/

#include <string.h>
#include "network.h"

static void display_player(server_t *serv)
{
    printf("LISTE DES CLIENTS :\n");
    for (size_t i = 0; i < MAX_CLIENTS; i++) {
        if (serv->clients[i].fd_tcp > 0) {
            printf("%s  id: %d  fd: %d\n", serv->clients[i].pseudo,
                serv->clients[i].id, serv->clients[i].fd_tcp);
        }
    }
}

static void launch_game(server_t *serv)
{
    struct epoll_event events = {0};

    serv->is_launch = true;
    manage_map(serv);
    init_udp(serv);
    events.events = EPOLLIN;
    events.data.fd = serv->sock_udp;
    epoll_ctl(serv->fd_epoll, EPOLL_CTL_ADD, serv->sock_udp, &events);
    printf("serv lancé\n");
}

int manage_stdin(server_t *serv)
{
    char input[BUFSIZ];
    int n_bytes = read(STDIN_FILENO, input, BUFSIZ - 1);

    if (n_bytes <= 0)
        return EXIT_FAILURE;
    input[n_bytes] = '\0';
    if (strncmp(input, "ip", strlen("ip")) == 0)
        printf("\033[33m""IP DU SERV : %s\n""\033[0m", serv->ip);
    if (strncmp(input, "list", strlen("list")) == 0)
        display_player(serv);
    if (strncmp(input, "start", strlen("start")) == 0) {
        launch_game(serv);
    }
    if (strncmp(input, "exit", strlen("exit")) == 0)
        return EXIT_PROG;
    return EXIT_SUCCESS;
}
