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
    #define SIZE_ID 6
    #define LOCAL "127.0.0.1"
    #define MAX_PLAYER 6
    #define MAX_CLIENT 67
    #define EPOLL_EVENT 64
    #define USERNAME_SIZE 67
    #define CHAR_ID "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"
    #define EXIT_PROG 67

    #include <sys/socket.h>
    #include <arpa/inet.h>
    #include <sys/epoll.h>
    #include <stdio.h>
    #include <stdbool.h>
    #include "player.h"

typedef enum {
    CREATE_ROOM = 1,
    JOIN_ROOM = 2,
} request_t;

typedef struct {
    uint8_t type;
    char host_name[USERNAME_SIZE];
} req_create_room_t;

typedef struct {
    uint8_t type;
    char id_room[SIZE_ID + 1];
} req_join_room_t;

typedef struct {
    char pseudo[USERNAME_SIZE];
    float pos_x;
    float pos_y;
    float angle;
    float delta_x;
    float delta_y;
} player_info_t;

typedef struct {
    uint8_t id;
    int fd_tcp;
    struct sockaddr_in sa_in;
    bool udp_ready;
    bool in_room;
    char id_room[SIZE_ID];
    player_info_t state;
} client_t;

typedef struct room_serv_s {
    char id_room[SIZE_ID + 1];
    char host_name[USERNAME_SIZE];
    client_t *player[MAX_PLAYER];
    uint8_t nb_players;
    bool is_launch;
    struct room_serv_s *next;
} room_serv_t;

typedef struct {
    char id_room[SIZE_ID + 1];
    char host_name[USERNAME_SIZE];
    uint8_t nb_players;
    bool is_launch;
} room_info_send_t;

typedef struct {
    int sock_tcp;
    int sock_udp;
    int fd_epoll;
    int nb_client;
    client_t clients[MAX_CLIENT];
    char *ip;
    room_serv_t *rooms;
    room_info_send_t room_to_send;
} server_t;

void get_ip(server_t *serv);
int init_server(server_t *serv);
int init_tcp(server_t *serv);
int init_epoll(server_t *serv);
int loop_server(server_t *serv);
int init_room(server_t *serv);
void fill_room_to_send(room_info_send_t *to_send, room_serv_t *room);
void send_room(server_t *serv, int fd);
void manage_client(server_t *serv, int fd);
room_serv_t *new_room(server_t *serv, client_t *host);
void broadcast_rooms(server_t *serv, room_serv_t *room);
void free_lst(room_serv_t *lst);

#endif /* SERVER_H_ */
