/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** init_tcp
*/

#include "network.h"

static int listen_tcp(server_t *serv)
{
    if (listen(serv->sock_tcp, MAX_CLIENTS) < 0) {
        printf("[TCP] L'écoute a échoué\n");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

static int bind_tcp(server_t *serv)
{
    struct sockaddr_in sa_in = {0};
    int opt = 1;

    setsockopt(serv->sock_tcp, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    sa_in.sin_family = AF_INET;
    sa_in.sin_port = htons(PORT_TCP);
    sa_in.sin_addr.s_addr = INADDR_ANY;
    if (bind(serv->sock_tcp, (struct sockaddr *)&sa_in, sizeof(sa_in)) < 0) {
        printf("[TCP] Le bind a échoué\n");
        return EXIT_FAILURE;
    }
    fcntl(serv->sock_tcp, F_SETFL, O_NONBLOCK);
    return EXIT_SUCCESS;
}

static int init_socket_tcp(server_t *serv)
{
    serv->sock_tcp = socket(AF_INET, SOCK_STREAM, 0);
    if (serv->sock_tcp < 0) {
        printf("[TCP] La création du socket a échoué\n");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

int init_tcp(server_t *serv)
{
    if (init_socket_tcp(serv) == EXIT_FAILURE)
        return EXIT_FAILURE;
    if (bind_tcp(serv) == EXIT_FAILURE)
        return EXIT_FAILURE;
    if (listen_tcp(serv) == EXIT_FAILURE)
        return EXIT_FAILURE;
    printf("[TCP] Socket ouvert sur le port %d\n", PORT_TCP);
    return EXIT_SUCCESS;
}
