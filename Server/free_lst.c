/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** free_lst
*/

#include <stdlib.h>
#include "server.h"

void free_lst(room_serv_t *lst)
{
    room_serv_t *tmp = NULL;

    while (lst != NULL) {
        tmp = lst->next;
        free(lst);
        lst = tmp;
    }
}
