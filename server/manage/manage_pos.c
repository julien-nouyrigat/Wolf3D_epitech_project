/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** manage_pos
*/

#include "network.h"

static void apply_movement(player_t *player, map_t *map, key_enum_t key)
{
    if (key == KEY_Z) {
        move_forward(player, map);
    }
    if (key == KEY_S) {
        move_backward(player, map);
    }
    if (key == KEY_Q) {
        move_left(player, map);
    }
    if (key == KEY_D) {
        move_right(player, map);
    }
    if (key == KEY_LEFT) {
        rotate_left(player, map);
    }
    if (key == KEY_RIGHT) {
        rotate_right(player, map);
    }
}

static void broadcast_pos(server_t *serv, uint8_t id)
{
    pos_network_t pos_net;

    pos_net.id = id;
    pos_net.state = serv->clients[id].state;
    for (size_t i = 0; i < MAX_CLIENTS; i++) {
        if (serv->clients[i].fd_tcp > 0 &&
            serv->clients[i].sa_in_udp.sin_port > 0) {
            sendto(serv->sock_udp, &pos_net, sizeof(pos_net), 0,
                (struct sockaddr *)&serv->clients[i].sa_in_udp,
                sizeof(serv->clients[i].sa_in_udp));
        }
    }
}

static void init_tmp_player(player_t *tmp, player_state_t *state)
{
    tmp->position.x = state->pos_x;
    tmp->position.y = state->pos_y;
    tmp->direction.x = state->direction_x;
    tmp->direction.y = state->direction_y;
    tmp->mvt_speed = state->mvt_speed;
    tmp->sprint = false;
}

static void apply_pos(player_t *tmp, player_state_t *state)
{
    state->pos_x = tmp->position.x;
    state->pos_y = tmp->position.y;
    state->direction_x = tmp->direction.x;
    state->direction_y = tmp->direction.y;
    state->pos_tile_x = tmp->pos_f.x;
    state->pos_tile_y = tmp->pos_f.y;
}

static void manage_map_move(server_t *serv, key_network_t *key, player_t *tmp)
{
    map_t tmp_map = {0};

    tmp_map.int_map = calloc(SIZE_MAP + 1, sizeof(int *));
    if (tmp_map.int_map == NULL)
        return;
    for (size_t i = 0; i < SIZE_MAP; i++) {
        tmp_map.int_map[i] = serv->map->map[i];
    }
    apply_movement(tmp, &tmp_map, key->key);
    free(tmp_map.int_map);
}

int manage_udp(server_t *serv)
{
    key_network_t key = {0};
    player_t tmp_player = {0};
    struct sockaddr_in sa_in = {0};
    socklen_t len_sa_in = sizeof(sa_in);
    ssize_t n_bytes = recvfrom(serv->sock_udp, &key, sizeof(key), 0,
        (struct sockaddr *)&sa_in, &len_sa_in);

    if (n_bytes < (ssize_t)sizeof(key) || key.id >= MAX_CLIENTS)
        return EXIT_FAILURE;
    if (serv->clients[key.id].fd_tcp <= 0)
        return EXIT_FAILURE;
    serv->clients[key.id].sa_in_udp = sa_in;
    init_tmp_player(&tmp_player, &serv->clients[key.id].state);
    manage_map_move(serv, &key, &tmp_player);
    apply_pos(&tmp_player, &serv->clients[key.id].state);
    broadcast_pos(serv, key.id);
    return EXIT_SUCCESS;
}
