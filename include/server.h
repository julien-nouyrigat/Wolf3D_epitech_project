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

    #include <sys/socket.h>
    #include <arpa/inet.h>
    #include <sys/epoll.h>
    #include <stdio.h>

typedef struct {
    uint8_t player_fd;
    float pos_x;
    float pos_y;
    float angle;
} state_t;

typedef struct {
    int sock_tcp;
    int sock_udp;
    int fd_epoll;
    int nb_clients;
} servert_t;

#endif
