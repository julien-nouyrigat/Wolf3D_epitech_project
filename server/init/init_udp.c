/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** init_udp
*/

#include "network.h"

int init_udp(server_t *serv)
{
    struct sockaddr_in sa_in = {0};

    serv->sock_udp = socket(AF_INET, SOCK_DGRAM, 0);
    sa_in.sin_family = AF_INET;
    sa_in.sin_port = htons(PORT_UDP);
    sa_in.sin_addr.s_addr = INADDR_ANY;
    if (bind(serv->sock_udp, (struct sockaddr *)&sa_in, sizeof(sa_in)) < 0) {
        printf("[UDP] Le bind a échoué\n");
        return EXIT_FAILURE;
    }
    fcntl(serv->sock_udp, F_SETFL, O_NONBLOCK);
    printf("[UDP] Socket ouvert sur le port %d\n", PORT_UDP);
    return EXIT_SUCCESS;
}
