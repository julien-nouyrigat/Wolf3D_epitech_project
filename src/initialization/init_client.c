/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** init_client
*/

#include "network.h"

static void fill_id(window_t *win)
{
    uint8_t recv_id = 0;

    if (win->client != NULL) {
        if (recv(win->client->sock_tcp, &recv_id, sizeof(uint8_t), 0) > 0) {
            win->client->id = recv_id;
            printf("Le client est bien connecté id = %d\n", win->client->id);
        }
    }
}

int connect_client(window_t *win)
{
    win->client->sock_tcp = socket(AF_INET, SOCK_STREAM, 0);
    win->client->sock_udp = socket(AF_INET, SOCK_DGRAM, 0);
    win->client->sa_in_tcp.sin_family = AF_INET;
    win->client->sa_in_tcp.sin_port = htons(PORT_TCP);
    if (win->client->sock_tcp < 0 || win->client->sock_udp < 0) {
        printf("La création du socket a échoué\n");
        return EXIT_FAILURE;
    }
    inet_pton(AF_INET, LOCAL, &win->client->sa_in_tcp.sin_addr);
    if (connect(win->client->sock_tcp, (struct sockaddr *)
            &win->client->sa_in_tcp, sizeof(win->client->sa_in_tcp)) < 0)
        return EXIT_FAILURE;
    fill_id(win);
    win->client->sa_in_udp.sin_family = AF_INET;
    win->client->sa_in_udp.sin_port = htons(PORT_UDP);
    inet_pton(AF_INET, LOCAL, &win->client->sa_in_udp.sin_addr);
    fcntl(win->client->sock_tcp, F_SETFL, O_NONBLOCK);
    fcntl(win->client->sock_udp, F_SETFL, O_NONBLOCK);
    return EXIT_SUCCESS;
}

int init_client(window_t *win)
{
    win->client = malloc(sizeof(*win->client));
    if (win->client == NULL)
        return EXIT_FAILURE;
    win->client->id = 0;
    win->client->sock_tcp = 0;
    win->client->sock_udp = 0;
    return EXIT_SUCCESS;
}
