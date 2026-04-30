/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** init_lobby
*/

#include "wolf.h"

static void init_text(window_t *win)
{
    sfFont *teko = sfFont_createFromFile("./assets/fonts/teko.ttf");

    win->lobby.leave = sfText_create();
    win->lobby.lobby = sfText_create();
    win->lobby.settings = sfText_create();
    sfText_setFont(win->lobby.lobby, teko);
    sfText_setString(win->lobby.leave, "LEAVE");
    sfText_setString(win->lobby.settings, "SETTINGS");
    sfText_setString(win->lobby.lobby, "LOBBY");
    sfText_setCharacterSize(win->lobby.leave, 100);
    sfText_setCharacterSize(win->lobby.settings, 100);
    sfText_setCharacterSize(win->lobby.lobby, 100);
    sfText_setPosition(win->lobby.leave, (sfVector2f){100, 700});
    sfText_setPosition(win->lobby.settings, (sfVector2f){100, 700});
    sfText_setPosition(win->lobby.lobby, (sfVector2f){100, 700});
}

int init_lobby(window_t *win)
{
    init_text(win);
    return EXIT_SUCCESS;
}
