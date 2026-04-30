/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** main
*/

#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include "wolf.h"
#include "server.h"

int main(void)
{
    server_t *serv = malloc(sizeof(*serv));

    srand(time(NULL));
    if (serv == NULL)
        return EXIT_FAILURE;
    if (init_server(serv) == EXIT_FAILURE)
        return EXIT_FAILURE;
    if (loop_server(serv) == EXIT_PROG) {
        free_lst(serv->rooms);
        close(serv->fd_epoll);
        close(serv->sock_tcp);
        free(serv->ip);
        free(serv);
    }
    return EXIT_SUCCESS;
}
