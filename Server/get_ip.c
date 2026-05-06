/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** get_ip
*/

#include <ifaddrs.h>
#include <string.h>
#include <stdlib.h>
#include "server.h"
#include "wolf.h"

static void fill_ip_buff(char **ip_buff, struct ifaddrs *ifaddr)
{
    struct sockaddr_in *sa_in;
    char *name = ifaddr->ifa_name;

    sa_in = (struct sockaddr_in *)ifaddr->ifa_addr;
    if (strcmp(name, "lo") != 0 && strncmp(name, "docker",
            strlen("docker")) != 0) {
        *ip_buff = inet_ntoa(sa_in->sin_addr);
        return;
    }
    return;
}

void get_ip(servert_t *serv)
{
    struct ifaddrs *ifaddr;
    struct ifaddrs *tmp;
    char *ip_buff = NULL;

    if (getifaddrs(&ifaddr) == -1)
        return;
    tmp = ifaddr;
    while (tmp != NULL) {
        if (tmp->ifa_addr != NULL && tmp->ifa_addr->sa_family == AF_INET)
            fill_ip_buff(&ip_buff, tmp);
        tmp = tmp->ifa_next;
    }
    strcpy(serv->ip, ip_buff);
    freeifaddrs(ifaddr);
}
