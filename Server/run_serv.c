/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** run_serv
*/

#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include "server.h"
#include "wolf.h"

static void broadcast_tcp(server_t *serv, char *msg, int sender_fd)
{
    for (int i = 0; i < serv->nb_client; i++) {
        if (serv->client[i].fd != sender_fd)
            write(serv->client[i].fd, msg, strlen(msg));
    }
}

static int epoll_add(int epoll_fd, int fd_client)
{
    struct epoll_event event = {0};

    event.events = EPOLLIN;
    event.data.fd = fd_client;
    return epoll_ctl(epoll_fd, EPOLL_CTL_ADD, fd_client, &event);
}

static void manage_client_tcp(server_t *serv, int fd)
{
    char buff[128] = {0};
    int n = read(fd, buff, sizeof(buff) - 1);

    if (n <= 0) {
        printf("\033[31m""[TCP] Client déconnecté fd=%d\n""\033[0m", fd);
        epoll_ctl(serv->fd_epoll, EPOLL_CTL_DEL, fd, NULL);
        close(fd);
        return;
    }
}

static void init_client(clients_t *client, int accept_res, server_t *serv)
{
    client->fd = accept_res;
    client->id = serv->nb_client;
    client->is_host = (serv->nb_client == 0);
    client->udp_ready = false;
}

static void accept_client(server_t *serv)
{
    struct sockaddr_in sa_in = {0};
    socklen_t len_sa_in = sizeof(sa_in);
    int accept_res = 0;
    clients_t *client = &serv->client[serv->nb_client];
    char msg[32] = {0};

    if (serv->nb_client >= MAXLOG)
        return;
    accept_res = accept(serv->fd_server, (struct sockaddr *)&sa_in, &len_sa_in);
    if (accept_res < 0)
        return;
    fcntl(accept_res, F_SETFL, O_NONBLOCK);
    epoll_add(serv->fd_epoll, accept_res);
    init_client(client, accept_res, serv);
    printf("\033[34m""[TCP] Client %d connecté\n""\033[0m", client->id);
    serv->nb_client++;
    snprintf(msg, sizeof(msg), "ID %d\n", client->id);
    write(client->fd, msg, strlen(msg));
}

static void manage_stdin(server_t *server)
{
    char buff[64] = {0};
    int n = read(STDIN_FILENO, buff, sizeof(buff) - 1);

    if (n <= 0)
        return;
    buff[n] = '\0';
    if (strncmp(buff, "start", 5) != 0)
        return;
    if (server->game_started) {
        printf("[TCP] Partie déjà lancée\n");
        return;
    }
    printf("\033[32m[TCP] Lancement de la partie\n\033[0m");
    broadcast_tcp(server, "START\n", -1);
    server->game_started = true;
    open_udp(server);
    epoll_add(server->fd_epoll, server->fd_udp);
}

void manage_serv(server_t *serv, int fd)
{
    if (fd == serv->fd_server) {
        accept_client(serv);
        return;
    }
    if (fd == STDIN_FILENO) {
        manage_stdin(serv);
        return;
    }
    if (!serv->game_started || fd != serv->fd_udp) {
        manage_client_tcp(serv, fd);
        return;
    }
    manage_udp(serv, serv->players);
}

void run_serv(server_t *serv)
{
    struct epoll_event event[EPOLL_EVENT];
    int n_event;
    int fd;

    serv->nb_client = 0;
    while (1) {
        n_event = epoll_wait(serv->fd_epoll, event, EPOLL_EVENT, -1);
        for (int i = 0; i < n_event; i++) {
            fd = event[i].data.fd;
            manage_serv(serv, fd);
        }
    }
}
