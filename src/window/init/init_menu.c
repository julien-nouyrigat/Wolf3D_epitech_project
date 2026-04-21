/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** init_menu
*/

#include "window.h"
#include "wolf.h"

static void init_text_menu(window_t *win, sfColor *grey)
{
    win->menu.host = sfText_create();
    win->menu.join = sfText_create();
    win->menu.single = sfText_create();
    win->menu.settings = sfText_create();
    win->menu.quit = sfText_create();
    sfText_setString(win->menu.host, "HOST");
    sfText_setString(win->menu.join, "JOIN");
    sfText_setString(win->menu.single, "SINGLE");
    sfText_setString(win->menu.settings, "SETTINGS");
    sfText_setString(win->menu.quit, "QUIT");
    sfText_setPosition(win->menu.host, (sfVector2f){100, 700});
    sfText_setPosition(win->menu.join, (sfVector2f){100, 800});
    sfText_setPosition(win->menu.single, (sfVector2f){100, 900});
    sfText_setPosition(win->menu.settings, (sfVector2f){100, 1000});
    sfText_setPosition(win->menu.quit, (sfVector2f){100, 1100});
    sfText_setColor(win->menu.host, *grey);
    sfText_setColor(win->menu.join, *grey);
    sfText_setColor(win->menu.single, *grey);
    sfText_setColor(win->menu.settings, *grey);
    sfText_setColor(win->menu.quit, *grey);
}

static void init_title(window_t *win)
{
    win->menu.s_title = sfSprite_create();
    win->menu.t_title = sfTexture_createFromFile("./assets/image/title.png",
        NULL);
    sfSprite_setTexture(win->menu.s_title, win->menu.t_title, sfTrue);
    sfSprite_setScale(win->menu.s_title, (sfVector2f){1, 1});
}

int init_menu(window_t *win)
{
    sfColor grey = sfColor_fromRGB(117, 117, 117);

    win->is_menu = true;
    win->is_lobby = false;
    win->is_game = false;
    win->is_param = false;
    win->is_single = false;
    init_text_menu(win, &grey);
    init_title(win);
    return EXIT_SUCCESS;
}
