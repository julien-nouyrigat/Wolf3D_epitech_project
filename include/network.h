/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** network
*/

#ifndef NETWORK_H
    #define NETWORK_H

    #include <sys/socket.h>
    #include <sys/epoll.h>
    #include <arpa/inet.h>
    #include <fcntl.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <stdint.h>
    #include <stdbool.h>
    #include "room.h"
    #include "wolf.h"

    #define LOCAL "127.0.0.1"
    #define PORT_TCP 8080
    #define PORT_UDP 8081
    #define MAX_EVENTS 64
    #define ROOM_NEXT 5
    #define EXIT_PROG -84

typedef struct {
    uint8_t id;
    uint8_t key;
} key_network_t;

typedef struct pos_network_s {
    uint8_t id;
    player_state_t state;
} pos_network_t;

typedef struct {
    int map[SIZE_MAP][SIZE_MAP];
    int type;
} map_network_t;

typedef struct {
    int id;
} client_info_start_t;

typedef struct {
    int fd_tcp;
    struct sockaddr_in sa_in;
    struct sockaddr_in sa_in_udp;
    uint8_t id;
    char pseudo[BUFSIZ];
    bool is_host;
    bool is_connected;
    player_state_t state;
} client_network_t;

typedef struct {
    char ip[BUFSIZ];
    client_network_t clients[MAX_CLIENTS];
    int sock_tcp;
    int sock_udp;
    int fd_epoll;
    int nb_clients;
    bool is_launch;
    size_t level;
    size_t nb_rooms;
    map_network_t *map;
    key_network_t key;
} server_t;

int get_ip(server_t *serv);
int init_epoll(server_t *serv);
int init_tcp(server_t *serv);
int manage_map(server_t *serv);
int manage_stdin(server_t *serv);
int server_loop(server_t *serv);
int accept_client(server_t *serv);
int init_udp(server_t *serv);
int manage_client(server_t *serv, int fd);
int manage_udp(server_t *serv);
int connect_client(window_t *win, player_t *player);
int init_client(window_t *win);

#endif
