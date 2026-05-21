/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** main
*/

#include "network.h"

int main(void)
{
    server_t serv = {0};

    serv.map = calloc(1, sizeof(map_network_t));
    if (get_ip(&serv) == EXIT_FAILURE)
        return EXIT_FAILURE;
    if (init_tcp(&serv) == EXIT_FAILURE)
        return EXIT_FAILURE;
    if (init_epoll(&serv) == EXIT_FAILURE)
        return EXIT_FAILURE;
    if (server_loop(&serv) == EXIT_PROG)
        exit(EXIT_SUCCESS);
    return EXIT_SUCCESS;
}
