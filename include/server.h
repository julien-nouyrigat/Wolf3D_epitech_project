/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** server
*/

#ifndef SERVER_H
    #define SERVER_H

    #define PORT_TCP 8080
    #define PORT_UDP 8081
    #define CLIENT_MAX 7
    #define LOCAL "127.0.0.1"
    #define EPOLL_EVENT 64
    #define USERNAME_SIZE 24
    #define EXIT_PROG -3

    #include <sys/socket.h>
    #include <arpa/inet.h>
    #include <sys/epoll.h>
    #include <stdbool.h>
    #include <stdio.h>

    #include "wolf.h"

typedef struct {
    uint8_t player_fd;
    float pos_x;
    float pos_y;
    float angle;
} state_t;

typedef struct {
    uint8_t client_id;
    struct sockaddr_in sa_in;
    int fd_tcp;
    bool is_host;
} client_t;

typedef struct {
    char ip[BUFSIZ];
    client_t clients[CLIENT_MAX];
    int sock_tcp;
    int sock_udp;
    int fd_epoll;
    int nb_clients;
    bool is_launch;
    map_t *map;
} servert_t;

int init_epoll(servert_t *serv);
int init_tcp(servert_t *serv);
void get_ip(servert_t *serv);
int server_loop(servert_t *serv);
int check_request(servert_t *serv);
int manage_client(servert_t *serv, int fd);
int accept_client(servert_t *serv);

#endif
