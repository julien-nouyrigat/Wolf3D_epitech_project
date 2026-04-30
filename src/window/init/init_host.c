/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** init_host
*/

#include "wolf.h"

static void set_string(window_t *win)
{
    sfColor orange = sfColor_fromRGB(255, 156, 38);
    sfColor grey = sfColor_fromRGB(143, 143, 143);

    sfText_setString(win->host.back, "< GO BACK");
    sfText_setString(win->host.new, "NEW GAME");
    sfText_setString(win->host.title, "MULTIPLAYER MODE");
    sfText_setColor(win->host.back, orange);
    sfText_setColor(win->host.new, grey);
    sfText_setColor(win->host.title, orange);
    sfText_setPosition(win->host.back, (sfVector2f) {200, 140});
    sfText_setPosition(win->host.new, (sfVector2f) {200, 310});
    sfText_setPosition(win->host.title, (sfVector2f) {750, 0});
    sfText_setCharacterSize(win->host.back, 70);
    sfText_setCharacterSize(win->host.new, 70);
    sfText_setCharacterSize(win->host.title, 70);
}

static void init_text(window_t *win, sfFont *teko)
{
    win->host.back = sfText_create();
    win->host.new = sfText_create();
    win->host.title = sfText_create();
    sfText_setFont(win->host.back, teko);
    sfText_setFont(win->host.new, teko);
    sfText_setFont(win->host.title, teko);
    set_string(win);
}

static void init_back(window_t *win)
{
    win->host.s_back = sfSprite_create();
    win->host.t_back = sfTexture_createFromFile(
        "./assets/image/fond_bombe2.png", NULL);
    sfSprite_setTexture(win->host.s_back, win->host.t_back, sfTrue);
    sfSprite_setScale(win->host.s_back, (sfVector2f){2.2, 1.76});
}

int init_host(window_t *win)
{
    sfFont *teko = sfFont_createFromFile("./assets/fonts/teko.ttf");

    init_text(win, teko);
    init_back(win);
    win->host.back_bound = sfText_getGlobalBounds(win->host.back);
    win->host.new_bound = sfText_getGlobalBounds(win->host.new);
    return EXIT_SUCCESS;
}
