/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** udp
*/

#include <math.h>
#include <fcntl.h>
#include "player.h"
#include "server.h"
#include "wolf.h"

static void apply_input_side(player_t *player, int input, int id)
{
    if (input == MOVE_Q) {
        player->angle -= 0.1;
        if (player->angle < 0)
            player->angle += 2 * M_PI;
        player->delta_x = cos(player->angle) * 5;
        player->delta_y = sin(player->angle) * 5;
        printf("\033[1;96m""[UDP] Client %d appuie sur Q\n""\033[0m", id);
    }
    if (input == MOVE_D) {
        player->angle += 0.1;
        if (player->angle > 2 * M_PI)
            player->angle = 0;
        player->delta_x = cos(player->angle) * 5;
        player->delta_y = sin(player->angle) * 5;
        printf("\033[1;96m""[UDP] Client %d appuie sur D\n""\033[0m", id);
    }
}

static void apply_input(player_t *player, int input, int id)
{
    if (input == MOVE_Z) {
        player->pos_x += player->delta_x;
        player->pos_y += player->delta_y;
        printf("\033[1;96m""[UDP] Client %d appuie sur Z\n""\033[0m", id);
    }
    if (input == MOVE_S) {
        player->pos_x -= player->delta_x;
        player->pos_y -= player->delta_y;
        printf("\033[1;96m""[UDP] Client %d appuie sur S\n""\033[0m", id);
    }
    apply_input_side(player, input, id);
}

static void broadcast_new_state(server_t *serv, player_t *player, uint8_t id)
{
    state_t state = {.player_id = id, .pos_x = player->pos_x,
        .pos_y = player->pos_y, .angle = player->angle};

    for (int i = 0; i < serv->nb_client; i++) {
        if (serv->client[i].udp_ready == true) {
            sendto(serv->fd_udp, &state, sizeof(state), 0, (struct sockaddr *)
                &serv->client[i].sa_in, sizeof(serv->client[i].sa_in));
        }
    }
}

void manage_udp(server_t *serv, player_t players[])
{
    input_t input;
    struct sockaddr_in sa_in = {0};
    socklen_t len_sa_in = sizeof(sa_in);
    int n_byte = recvfrom(serv->fd_udp, &input, sizeof(input), 0,
        (struct sockaddr *)&sa_in, &len_sa_in);
    uint8_t id;

    if (n_byte != sizeof(input))
        return;
    id = input.player_id;
    if (id >= serv->nb_client)
        return;
    if (!serv->client[id].udp_ready) {
        serv->client[id].sa_in = sa_in;
        serv->client[id].udp_ready = true;
        for (int i = 0; i < MAXLOG; i++)
            broadcast_new_state(serv, &players[i], i);
    }
    apply_input(&players[id], input.input, id);
    broadcast_new_state(serv, &players[id], id);
}

void open_udp(server_t *serv)
{
    struct sockaddr_in sa_in = {0};

    serv->fd_udp = socket(AF_INET, SOCK_DGRAM, 0);
    sa_in.sin_family = AF_INET;
    sa_in.sin_port = htons(PORT_UDP);
    sa_in.sin_addr.s_addr = INADDR_ANY;
    bind(serv->fd_udp, (struct sockaddr *)&sa_in, sizeof(sa_in));
    fcntl(serv->fd_udp, F_SETFL, O_NONBLOCK);
    printf("\033[33m""[UDP] Socket ouvert sur port %d\n""\033[0m", PORT_UDP);
}
