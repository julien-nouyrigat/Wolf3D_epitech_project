/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** client_udp
*/

#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include "server.h"
#include "client.h"
#include "wolf.h"

void init_udp(client_t *client)
{
    input_enum_t start = MOVE_Z;

    client->fd_udp = socket(AF_INET, SOCK_DGRAM, 0);
    fcntl(client->fd_udp, F_SETFL, O_NONBLOCK);
    printf("\033[33m""[UDP] Socket client prêt\n""\033[0m");
    send_input(client, &start);
}

void send_input(client_t *client, input_enum_t *enum_input)
{
    struct sockaddr_in sa_in = {0};
    input_t input;

    input.player_id = client->player_id;
    input.input = *enum_input;
    sa_in.sin_family = AF_INET;
    sa_in.sin_port = htons(PORT_UDP);
    inet_pton(AF_INET, LOCAL, &sa_in.sin_addr);
    sendto(client->fd_udp, &input, sizeof(input), 0,
        (struct sockaddr *)&sa_in, sizeof(sa_in));
}

void recv_states(client_t *client, player_t player[])
{
    state_t state;
    int n = 0;

    while (1) {
        n = recvfrom(client->fd_udp, &state, sizeof(state), 0, NULL, NULL);
        if (n != sizeof(state))
            break;
        if (state.player_id >= MAXLOG)
            continue;
        player[state.player_id].pos_x = state.pos_x;
        player[state.player_id].pos_y = state.pos_y;
        player[state.player_id].angle = state.angle;
    }
}
