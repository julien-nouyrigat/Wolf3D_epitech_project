/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** window_ip
*/

#include "wolf.h"

void window_ip(window_t *wolf_win)
{
    if (wolf_win->event.type == sfEvtTextEntered) {
        if ((wolf_win->event.text.unicode >= '0' &&
                wolf_win->event.text.unicode <= '9') ||
            wolf_win->event.text.unicode >= 'a') {
            wolf_win->ip->ip[wolf_win->ip->index_ip] =
                wolf_win->event.text.unicode;
            wolf_win->ip->index_ip++;
        }
    }
    if (wolf_win->event.type == sfEvtKeyPressed) {
        if (wolf_win->event.key.code == sfKeyBack) {
            wolf_win->ip->index_ip = wolf_win->ip->index_ip <= 0 ?
                0 : wolf_win->ip->index_ip - 1;
            wolf_win->ip->ip[wolf_win->ip->index_ip] = '\0';
        }
    }
}
