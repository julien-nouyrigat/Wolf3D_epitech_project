/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** main
*/

#include "wolf.h"
#include "server.h"

int main(void)
{
    servert_t serv = {0};

    serv.fd_epoll = 0;
    serv.nb_clients = 0;
    serv.sock_tcp = 0;
    serv.sock_udp = 0;
    if (init_tcp(&serv) == EXIT_FAILURE)
        return EXIT_FAILURE;
    if (init_epoll(&serv) == EXIT_FAILURE)
        return EXIT_FAILURE;
    get_ip(&serv);
    server_loop(&serv);
    return EXIT_SUCCESS;
}
