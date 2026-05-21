/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** get_ip
*/

#include <ifaddrs.h>
#include <string.h>
#include "network.h"

static void fill_ip(server_t *serv, struct ifaddrs *ifa)
{
    struct sockaddr_in *sa_in;
    char *name = ifa->ifa_name;
    char *ip;

    sa_in = (struct sockaddr_in *)ifa->ifa_addr;
    if (strcmp(name, "lo") != 0 &&
        strncmp(name, "docker", strlen("docker")) != 0) {
        ip = inet_ntoa(sa_in->sin_addr);
        strcpy(serv->ip, ip);
    }
}

int get_ip(server_t *serv)
{
    struct ifaddrs *ifa;
    struct ifaddrs *tmp;

    if (getifaddrs(&ifa) == -1)
        return EXIT_FAILURE;
    tmp = ifa;
    while (tmp != NULL) {
        if (tmp->ifa_addr && tmp->ifa_addr->sa_family == AF_INET)
            fill_ip(serv, tmp);
        tmp = tmp->ifa_next;
    }
    freeifaddrs(ifa);
    return EXIT_SUCCESS;
}
