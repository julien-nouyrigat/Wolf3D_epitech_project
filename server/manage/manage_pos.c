/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** manage_pos
*/

#include "network.h"

static void broadcast_pos(server_t *serv, pos_network_t *pos_net)
{
    for (size_t i = 0; i < MAX_CLIENTS; i++) {
        if (serv->clients[i].id == pos_net->id)
            continue;
        if (serv->clients[i].fd_tcp > 0 &&
            serv->clients[i].sa_in_udp.sin_port > 0) {
            sendto(serv->sock_udp, pos_net, sizeof(*pos_net), 0,
                (struct sockaddr *)&serv->clients[i].sa_in_udp,
                sizeof(serv->clients[i].sa_in_udp));
        }
    }
}

int manage_udp(server_t *serv)
{
    pos_network_t pos_net = {0};
    struct sockaddr_in sa_in;
    socklen_t len_sa_in = sizeof(sa_in);
    ssize_t n_bytes = recvfrom(serv->sock_udp, &pos_net, sizeof(pos_net), 0,
        (struct sockaddr *)&sa_in, &len_sa_in);

    if (n_bytes < (ssize_t)sizeof(pos_net))
        return EXIT_FAILURE;
    if (serv->clients[pos_net.id].fd_tcp <= 0)
        return EXIT_FAILURE;
    if (serv->clients[pos_net.id].sa_in_udp.sin_port == 0)
        serv->clients[pos_net.id].sa_in_udp = sa_in;
    broadcast_pos(serv, &pos_net);
    return EXIT_SUCCESS;
}
