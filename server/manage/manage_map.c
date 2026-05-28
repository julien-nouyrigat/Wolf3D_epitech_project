/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** manage_map
*/

#include "network.h"

static int broadcast_map(server_t *serv)
{
    if (serv->map == NULL)
        return EXIT_FAILURE;
    for (uint8_t i = 0; i < MAX_CLIENTS; i++) {
        if (serv->clients[i].fd_tcp > 0)
            send(serv->clients[i].fd_tcp, serv->map, sizeof(*serv->map), 0);
    }
    return EXIT_SUCCESS;
}

static int fill_map_net(server_t *serv, map_t *map)
{
    if (map->int_map == NULL)
        return EXIT_FAILURE;
    serv->nb_rooms += ROOM_NEXT;
    serv->map->type = map->type;
    for (size_t i = 0; i < SIZE_MAP; i++) {
        if (map->int_map[i] == NULL)
            return EXIT_FAILURE;
        for (size_t j = 0; j < SIZE_MAP; j++) {
            serv->map->map[i][j] = map->int_map[i][j];
        }
    }
    return EXIT_SUCCESS;
}

static void free_level(map_t **map)
{
    for (size_t i = 0; (*map)->int_map[i] != NULL; i++) {
        free((*map)->int_map[i]);
    }
}

static int create_level(map_t **map)
{
    if ((*map)->int_map != NULL)
        free_level(map);
    if (init_map(map) == EXIT_FAILURE)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

int manage_map(server_t *serv)
{
    map_t *map = calloc(1, sizeof(*map));

    if (map == NULL)
        return EXIT_FAILURE;
    if (serv->map == NULL)
        serv->map = calloc(1, sizeof(map_network_t));
    if (create_level(&map) == EXIT_FAILURE)
        return EXIT_FAILURE;
    fill_map_net(serv, map);
    broadcast_map(serv);
    free(map);
    return EXIT_SUCCESS;
}
