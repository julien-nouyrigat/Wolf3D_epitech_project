/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** manage_client
*/

#include "network.h"

static void init_pos_client(server_t *serv, int i)
{
    serv->clients[i].state.pos_x = 31 * TILE_SIZE;
    serv->clients[i].state.pos_y = 31 * TILE_SIZE;
    serv->clients[i].state.pos_tile_x = serv->clients[i].state.pos_x /
        TILE_SIZE;
    serv->clients[i].state.pos_tile_y = serv->clients[i].state.pos_y /
        TILE_SIZE;
    serv->clients[i].state.direction_x = -1.0;
    serv->clients[i].state.direction_y = 0.0;
    serv->clients[i].state.mvt_speed = 5;
}

static void send_id(server_t *serv, int fd, int i)
{
    uint8_t id = (uint8_t)i;
    player_state_t state = serv->clients[i].state;

    send(fd, &id, sizeof(id), 0);
    send(fd, &state, sizeof(state), 0);
}

static void add_client(server_t *serv, int fd, struct sockaddr_in *sa_in,
    int i)
{
    struct epoll_event event = {0};

    serv->clients[i].fd_tcp = fd;
    serv->clients[i].sa_in = *sa_in;
    serv->clients[i].id = i;
    init_pos_client(serv, i);
    serv->nb_clients++;
    event.events = EPOLLIN;
    event.data.fd = fd;
    epoll_ctl(serv->fd_epoll, EPOLL_CTL_ADD, fd, &event);
    send_id(serv, fd, i);
}

int accept_client(server_t *serv)
{
    struct sockaddr_in sa_in = {0};
    socklen_t len_sa_in = sizeof(sa_in);
    int fd = accept(serv->sock_tcp, (struct sockaddr *)&sa_in, &len_sa_in);

    if (fd < 0)
        return EXIT_FAILURE;
    fcntl(fd, F_SETFL, O_NONBLOCK);
    for (size_t i = 0; i < MAX_CLIENTS; i++) {
        if (serv->clients[i].fd_tcp <= 0) {
            add_client(serv, fd, &sa_in, i);
            printf("[TCP] Nouveau client id = %zu fd = %d\n", i, fd);
            break;
        }
    }
    return EXIT_SUCCESS;
}

static void remove_client(server_t *serv, int fd, int index)
{
    printf("[EPOLL] Le client %d est deconnecté\n", serv->clients[index].id);
    epoll_ctl(serv->fd_epoll, EPOLL_CTL_DEL, fd, NULL);
    close(fd);
    serv->clients[index].fd_tcp = 0;
    serv->clients[index].is_connected = false;
    serv->clients[index].id = 0;
    if (serv->nb_clients > 0)
        serv->nb_clients--;
}

int manage_client(server_t *serv, int fd)
{
    int index = -1;
    char buff[BUFSIZ];

    for (size_t i = 0; i < MAX_CLIENTS; i++) {
        if (serv->clients[i].fd_tcp == fd) {
            index = i;
            break;
        }
    }
    if (index == -1)
        return EXIT_FAILURE;
    if (recv(fd, buff, BUFSIZ, 0) <= 0) {
        remove_client(serv, fd, index);
        return EXIT_SUCCESS;
    }
    return EXIT_SUCCESS;
}
