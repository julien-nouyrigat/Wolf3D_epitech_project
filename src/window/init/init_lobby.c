/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** init_lobby
*/

#include "wolf.h"

static void set_color(window_t *win)
{
    sfColor orange = sfColor_fromRGB(255, 156, 38);
    sfColor grey = sfColor_fromRGB(143, 143, 143);

    sfText_setColor(win->lobby.lobby, orange);
    sfText_setColor(win->lobby.leave, grey);
    sfText_setColor(win->lobby.settings, grey);
}

static void init_text(window_t *win)
{
    sfFont *teko = sfFont_createFromFile("./assets/fonts/teko.ttf");
    sfFont *buckwheat = sfFont_createFromFile("./assets/fonts/buckwheat.otf");

    win->lobby.leave = sfText_create();
    win->lobby.lobby = sfText_create();
    win->lobby.settings = sfText_create();
    sfText_setFont(win->lobby.lobby, buckwheat);
    sfText_setFont(win->lobby.leave, teko);
    sfText_setFont(win->lobby.settings, teko);
    sfText_setString(win->lobby.leave, "LEAVE");
    sfText_setString(win->lobby.settings, "SETTINGS");
    sfText_setString(win->lobby.lobby, "LOBBY");
    sfText_setCharacterSize(win->lobby.leave, 80);
    sfText_setCharacterSize(win->lobby.settings, 80);
    sfText_setCharacterSize(win->lobby.lobby, 270);
    sfText_setPosition(win->lobby.leave, (sfVector2f){85, 800});
    sfText_setPosition(win->lobby.settings, (sfVector2f){300, 800});
    sfText_setPosition(win->lobby.lobby, (sfVector2f){200, -60});
}

static void init_back(window_t *win)
{
    win->lobby.s_back = sfSprite_create();
    win->lobby.t_back = sfTexture_createFromFile(
        "./assets/image/back_lobby.png", NULL);
    sfSprite_setTexture(win->lobby.s_back, win->lobby.t_back, sfTrue);
    sfSprite_setScale(win->lobby.s_back, (sfVector2f){1.6, 1.35});
    sfSprite_setPosition(win->lobby.s_back, (sfVector2f){50, 240});
}

int init_lobby(window_t *win)
{
    init_text(win);
    init_back(win);
    set_color(win);
    win->lobby.leave_bound = sfText_getGlobalBounds(win->lobby.leave);
    win->lobby.settings_bound = sfText_getGlobalBounds(win->lobby.settings);
    return EXIT_SUCCESS;
}
