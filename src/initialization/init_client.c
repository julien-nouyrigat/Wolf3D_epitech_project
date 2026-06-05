/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** init_client
*/

#include "network.h"

static void recv_infos(window_t *win, player_t *player)
{
    uint8_t id = 0;
    player_state_t state = {0};

    recv(win->client->sock_tcp, &id, sizeof(id), MSG_WAITALL);
    recv(win->client->sock_tcp, &state, sizeof(state), MSG_WAITALL);
    win->client->id = id;
    player->position.x = state.pos_x;
    player->position.y = state.pos_y;
    player->pos_f.x = state.pos_x / TILE_SIZE;
    player->pos_f.y = state.pos_y / TILE_SIZE;
    player->direction.x = state.direction_x;
    player->direction.y = state.direction_y;
    player->mvt_speed = state.mvt_speed;
}

int connect_client(window_t *win, player_t *player)
{
    win->client->sock_tcp = socket(AF_INET, SOCK_STREAM, 0);
    win->client->sock_udp = socket(AF_INET, SOCK_DGRAM, 0);
    win->client->sa_in_tcp.sin_family = AF_INET;
    win->client->sa_in_tcp.sin_port = htons(PORT_TCP);
    if (win->client->sock_tcp < 0 || win->client->sock_udp < 0) {
        printf("La création du socket a échoué\n");
        return EXIT_FAILURE;
    }
    inet_pton(AF_INET, "10.94.109.158", &win->client->sa_in_tcp.sin_addr);
    if (connect(win->client->sock_tcp, (struct sockaddr *)
            &win->client->sa_in_tcp, sizeof(win->client->sa_in_tcp)) < 0)
        return EXIT_FAILURE;
    recv_infos(win, player);
    win->client->sa_in_udp.sin_family = AF_INET;
    win->client->sa_in_udp.sin_port = htons(PORT_UDP);
    inet_pton(AF_INET, "10.94.109.158", &win->client->sa_in_udp.sin_addr);
    fcntl(win->client->sock_tcp, F_SETFL, O_NONBLOCK);
    fcntl(win->client->sock_udp, F_SETFL, O_NONBLOCK);
    printf("Le client est bien connecté\n");
    return EXIT_SUCCESS;
}

int init_client(window_t *win)
{
    win->client = calloc(1, sizeof(*win->client));
    if (win->client == NULL)
        return EXIT_FAILURE;
    win->client->id = 0;
    win->client->sock_tcp = 0;
    win->client->sock_udp = 0;
    win->client->t_player = sfTexture_createFromFile("./assets/image/perso.png",
        NULL);
    return EXIT_SUCCESS;
}
