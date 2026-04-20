/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** server
*/

#include <stdlib.h>
#include <stdio.h>
#include <ifaddrs.h>
#include <unistd.h>
#include <fcntl.h>
#include <math.h>
#include <string.h>
#include "wolf.h"
#include "server.h"

int init_server(server_t *serv)
{
    int opt = 1;

    serv->fd_server = socket(PF_INET, SOCK_STREAM, 0);
    if (serv->fd_server < 0)
        return EXIT_FAILURE;
    setsockopt(serv->fd_server, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    serv->sa_in.sin_family = AF_INET;
    serv->sa_in.sin_port = htons(PORT);
    serv->sa_in.sin_addr.s_addr = INADDR_ANY;
    if (bind(serv->fd_server, (struct sockaddr *)&serv->sa_in,
            sizeof(serv->sa_in)) < 0)
        return EXIT_FAILURE;
    fcntl(serv->fd_server, F_SETFL, O_NONBLOCK);
    if (listen(serv->fd_server, MAXLOG) < 0)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

int init_epoll(server_t *serv)
{
    struct epoll_event event = {0};

    serv->fd_epoll = epoll_create1(0);
    if (serv->fd_epoll < 0)
        return EXIT_FAILURE;
    event.events = EPOLLIN;
    event.data.fd = serv->fd_server;
    if (epoll_ctl(serv->fd_epoll, EPOLL_CTL_ADD, serv->fd_server, &event) < 0)
        return EXIT_FAILURE;
    event.events = EPOLLIN;
    event.data.fd = STDIN_FILENO;
    if (epoll_ctl(serv->fd_epoll, EPOLL_CTL_ADD, STDIN_FILENO, &event) < 0)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

static int init_epoll_server(server_t *serv)
{
    if (init_server(serv) != EXIT_SUCCESS)
        return EXIT_FAILURE;
    if (init_epoll(serv) != EXIT_SUCCESS)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

static void write_ip(char **ip_buff, struct ifaddrs *ifaddr)
{
    struct sockaddr_in *sa_in;
    char *type = ifaddr->ifa_name;

    sa_in = (struct sockaddr_in *)ifaddr->ifa_addr;
    if (strcmp(type, "lo") != 0 && strncmp(type, "docker",
            strlen("docker")) != 0) {
        *ip_buff = inet_ntoa(sa_in->sin_addr);
        return;
    }
    return;
}

static void get_ip(void)
{
    struct ifaddrs *ifaddr;
    struct ifaddrs *tmp;
    char *ip_buff = malloc(INET_ADDRSTRLEN);

    if (!ip_buff)
        return;
    if (getifaddrs(&ifaddr) == -1)
        return;
    tmp = ifaddr;
    while (tmp != NULL) {
        if (tmp->ifa_addr != NULL && tmp->ifa_addr->sa_family == AF_INET) {
            write_ip(&ip_buff, tmp);
        }
        tmp = tmp->ifa_next;
    }
    printf("IP du serveur : %s\n", ip_buff);
    freeifaddrs(ifaddr);
}

int main(void)
{
    server_t *serv = malloc(sizeof(*serv));

    if (!serv)
        return EXIT_FAILURE;
    serv->game_started = false;
    if (init_epoll_server(serv) != EXIT_SUCCESS)
        return EXIT_FAILURE;
    if (init_map(&serv->map) == EXIT_FAILURE)
        return EXIT_FAILURE;
    get_ip();
    for (int i = 0; i < MAXLOG; i++) {
        serv->players[i].pos_x = 100 + i * 20;
        serv->players[i].pos_y = 100;
        serv->players[i].angle = 0;
        serv->players[i].delta_x = cos(0) * 5;
        serv->players[i].delta_y = sin(0) * 5;
    }
    printf("\033[33m""[TCP] Server en écoute:%d\n""\033[0m", PORT);
    run_serv(serv);
    return EXIT_SUCCESS;
}
