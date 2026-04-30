/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** connect_to_server
*/

#include <sys/socket.h>
#include <arpa/inet.h>
#include "wolf.h"

int connect_to_server(client_info_t *client, char *ip)
{
    struct sockaddr_in sa_in;

    client->sock_tcp = socket(AF_INET, SOCK_STREAM, 0);
    if (client->sock_tcp < 0)
        return EXIT_FAILURE;
    sa_in.sin_family = AF_INET;
    sa_in.sin_port = htons(8080);
    if (inet_pton(AF_INET, ip, &sa_in.sin_addr.s_addr) < 0)
        return EXIT_FAILURE;
    if (connect(client->sock_tcp, (struct sockaddr *)&sa_in,
            (socklen_t)sizeof(sa_in)) < 0) {
        printf("Can't connect to server\n");
        return EXIT_FAILURE;
    }
    printf("Connected to server\n");
    return EXIT_SUCCESS;
}
