/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** client
*/

#ifndef CLIENT_H
    #define CLIENT_H

    #define PORT 8080
    #define PORT_UDP 8081
    #define LOCAL "127.0.0.1"

    #include <sys/socket.h>
    #include <arpa/inet.h>
    #include <stdbool.h>
    #include "server.h"

typedef struct {
    int fd;
    int fd_udp;
    int player_id;
    char pseudo[BUFSIZ];
    struct sockaddr_in sa_in;
    bool is_started;
    char ip[BUFSIZ];
} client_t;

void send_input(client_t *client, input_enum_t *enum_input);
void recv_states(client_t *client, player_t player[]);
void init_udp(client_t *client);

#endif
