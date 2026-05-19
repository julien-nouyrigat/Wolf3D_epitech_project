/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** manage_client
*/

#include "network.h"

void send_key_move(key_enum_t key, window_t *win)
{
    key_network_t key_to_send;

    key_to_send.id = win->client->id;
    key_to_send.key = key;
    sendto(win->client->sock_udp, &key_to_send, sizeof(key_to_send), 0,
        (struct sockaddr *)&win->client->sa_in_udp,
        sizeof(win->client->sa_in_udp));
}

static void set_state_win(window_t *win)
{
    win->is_lobby = false;
    win->is_game = true;
    win->is_single = true;
}

static void recv_map_tcp(window_t *win, map_t *map)
{
    map_network_t net_map = {0};
    size_t total_bytes = 0;
    uint8_t *buff = (uint8_t *)&net_map;
    ssize_t n_bytes;

    n_bytes = recv(win->client->sock_tcp, buff + total_bytes,
        sizeof(map_network_t) - total_bytes, 0);
    if (n_bytes <= 0)
        return;
    total_bytes += n_bytes;
    if (total_bytes < sizeof(map_network_t))
        return;
    map->type = net_map.type;
    for (size_t i = 0; i < SIZE_MAP; i++) {
        for (size_t j = 0; j < SIZE_MAP; j++) {
            map->int_map[i][j] = net_map.map[i][j];
        }
    }
    set_state_win(win);
    total_bytes = 0;
}

static void recv_pos_udp(window_t *win, player_t *player)
{
    pos_network_t net_pos = {0};
    struct sockaddr_in sa_in = {0};
    socklen_t len_sa_in = sizeof(sa_in);
    ssize_t n_bytes = recvfrom(win->client->sock_udp, &net_pos, sizeof(net_pos),
        0, (struct sockaddr *)&sa_in, &len_sa_in);

    if (n_bytes >= (ssize_t)sizeof(net_pos)) {
        player->position.x = net_pos.state.pos_x;
        player->position.y = net_pos.state.pos_y;
        player->pos_f.x = net_pos.state.pos_tile_x;
        player->pos_f.y = net_pos.state.pos_tile_y;
        player->direction.x = net_pos.state.direction_x;
        player->direction.y = net_pos.state.direction_y;
    }
}

void manage_client_network(window_t *win, player_t *player, map_t *map)
{
    if (win->client->sock_tcp < 0)
        return;
    if (win->is_lobby == true) {
        recv_map_tcp(win, map);
    }
    if (win->is_game == true) {
        recv_pos_udp(win, player);
    }
}
