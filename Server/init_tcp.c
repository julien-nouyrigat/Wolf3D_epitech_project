/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** init_tcp
*/

#include <fcntl.h>
#include "wolf.h"
#include "server.h"

static int listen_tcp(servert_t *serv)
{
    if (listen(serv->sock_tcp, CLIENT_MAX) < 0) {
        printf("L'écoute a échoué\n");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

static int bind_tcp(servert_t *serv)
{
    struct sockaddr_in sa_in;
    int opt = 1;

    setsockopt(serv->sock_tcp, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    sa_in.sin_family = AF_INET;
    sa_in.sin_port = htons(PORT_TCP);
    sa_in.sin_addr.s_addr = INADDR_ANY;
    if (bind(serv->sock_tcp, (struct sockaddr *)&sa_in, sizeof(sa_in)) < 0) {
        printf("Le bind a échoué\n");
        return EXIT_FAILURE;
    }
    fcntl(serv->sock_tcp, F_SETFL, O_NONBLOCK);
    return EXIT_SUCCESS;
}

static int sock_tcp(servert_t *serv)
{
    serv->sock_tcp = socket(AF_INET, SOCK_STREAM, 0);
    if (serv->sock_tcp < 0) {
        printf("La création du socket a échoué\n");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

int init_tcp(servert_t *serv)
{
    if (sock_tcp(serv) == EXIT_FAILURE)
        return EXIT_FAILURE;
    if (bind_tcp(serv) == EXIT_FAILURE)
        return EXIT_FAILURE;
    if (listen_tcp(serv) == EXIT_FAILURE)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}
