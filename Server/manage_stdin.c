/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** manage_stdin
*/

#include <unistd.h>
#include <string.h>
#include "server.h"
#include "wolf.h"

int check_request(servert_t *serv)
{
    char input[BUFSIZ];
    int n_bytes = read(STDIN_FILENO, input, BUFSIZ - 1);

    if (n_bytes <= 0)
        return EXIT_FAILURE;
    input[n_bytes] = '\0';
    if (strncmp(input, "ip", strlen("ip")) == 0)
        printf("\033[31m""IP du serveur : %s\n""\033[0m", serv->ip);
    if (strncmp(input, "list", strlen("list")) == 0)
        printf("faut afficher la liste des joueurs\n");
    if (strncmp(input, "", strlen("exit")) == 0)
        return EXIT_PROG;
    return EXIT_SUCCESS;
}
