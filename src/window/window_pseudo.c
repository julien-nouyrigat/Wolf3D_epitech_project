/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** window_pseudo
*/

#include "wolf.h"

void window_pseudo(window_t *wolf_win)
{
    if (wolf_win->event.type == sfEvtTextEntered) {
        if ((wolf_win->event.text.unicode >= 'A' &&
                wolf_win->event.text.unicode <= 'Z') ||
            (wolf_win->event.text.unicode >= 'a' &&
                wolf_win->event.text.unicode <= 'z') ||
            wolf_win->event.text.unicode == '_') {
            wolf_win->pseudo->pseudo[wolf_win->pseudo->index_pseudo] =
                wolf_win->event.text.unicode;
            wolf_win->pseudo->index_pseudo = wolf_win->pseudo->index_pseudo <
                15 ? wolf_win->pseudo->index_pseudo + 1 : 15;
        }
    }
    if (wolf_win->event.type == sfEvtKeyPressed) {
        if (wolf_win->event.key.code == sfKeyBack) {
            wolf_win->pseudo->index_pseudo = wolf_win->pseudo->index_pseudo <= 0
                ? 0 : wolf_win->pseudo->index_pseudo - 1;
            wolf_win->pseudo->pseudo[wolf_win->pseudo->index_pseudo] = '\0';
        }
    }
}
