/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** main
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "wolf.h"
#include "client.h"

static int stay_start(client_t *client)
{
    char buff[64] = {0};

    recv(client->fd, buff, sizeof(buff) - 1, 0);
    sscanf(buff, "ID %d", &client->player_id);
    printf("[TCP]: Mon ID : %d\n", client->player_id);
    memset(buff, 0, sizeof(buff));
    while (strncmp(buff, "START", 5) != 0) {
        memset(buff, 0, sizeof(buff));
        recv(client->fd, buff, sizeof(buff) - 1, 0);
    }
    printf("\033[33m""[TCP] START recu, lancement de la partie\n""\033[0m");
    client->is_started = true;
    return EXIT_SUCCESS;
}

static int init_client(client_t *client)
{
    client->fd = socket(AF_INET, SOCK_STREAM, 0);
    if (client->fd < 0)
        return EXIT_FAILURE;
    client->sa_in.sin_family = AF_INET;
    client->sa_in.sin_port = htons(PORT);
    if (inet_pton(AF_INET, LOCAL, &(client->sa_in.sin_addr)) != 1)
        return EXIT_FAILURE;
    if (connect(client->fd, (struct sockaddr *)&client->sa_in,
            sizeof(client->sa_in)) != 0) {
        printf("\033[31m""[TCP] La connexion au serveur a échoué\n""\033[0m");
        return EXIT_FAILURE;
    }
    printf("\033[33m""Connecté au serveur\n""\033[0m");
    stay_start(client);
    return EXIT_SUCCESS;
}

int main(int ac, char **av)
{
    client_t *client = malloc(sizeof(*client));

    if (!client)
        return EXIT_FAILURE;
    if (ac > 2)
        return EXIT_FAILURE;
    if (ac == 2 && strcmp(av[2], "-h") == 0)
        return flag_h();
    if (init_client(client) != EXIT_SUCCESS)
        return EXIT_FAILURE;
    return wolf(client);
}
