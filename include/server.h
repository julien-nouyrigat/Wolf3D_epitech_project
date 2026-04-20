/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** server
*/

#ifndef SERVER_H
    #define SERVER_H

    #include <sys/socket.h>
    #include <arpa/inet.h>
    #include <sys/epoll.h>
    #include <stdbool.h>
    #include "map.h"

    #define PORT 8080
    #define PORT_UDP 8081
    #define LOCAL "127.0.0.1"
    #define MAXLOG 6
    #define EPOLL_EVENT 64

    #include "player.h"

typedef enum {
    MOVE_Z,
    MOVE_S,
    MOVE_Q,
    MOVE_D
} input_enum_t;

typedef struct {
    uint8_t player_id;
    uint8_t input;
} input_t;

typedef struct {
    uint8_t player_id;
    float pos_x;
    float pos_y;
    float angle;
} state_t;

typedef struct {
    int fd;
    struct sockaddr_in sa_in;
    uint8_t id;
    uint8_t is_host;
    bool udp_ready;
} clients_t;

typedef struct {
    int fd_server;
    int fd_udp;
    int fd_epoll;
    clients_t client[MAXLOG];
    int nb_client;
    bool game_started;
    player_t players[MAXLOG];
    struct sockaddr_in sa_in;
    map_t *map;
} server_t;

void run_serv(server_t *serv);
void open_udp(server_t *serv);
void manage_udp(server_t *serv, player_t players[]);

#endif /* SERVER_H_ */
