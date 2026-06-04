/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** init_param
*/

#include <string.h>
#include "wolf.h"

static void init_tab(window_t *win)
{
    sfColor grey = sfColor_fromRGB(143, 143, 143);
    int y_rect = 300;

    for (int i = 0; i < NB_TAB_PARAM; i++) {
        win->param.tab[i].tab = sfText_create();
        sfText_setFont(win->param.tab[i].tab, win->font);
        sfText_setColor(win->param.tab[i].tab, grey);
        sfText_setPosition(win->param.tab[i].tab, (sfVector2f){200, y_rect});
        y_rect += 150;
        sfText_setCharacterSize(win->param.tab[i].tab, 100);
    }
    sfText_setString(win->param.tab[0].tab, "GRAPHICS");
    sfText_setString(win->param.tab[1].tab, "AUDIO");
    sfText_setString(win->param.tab[2].tab, "CONTROLS");
    sfText_setString(win->param.tab[3].tab, "BACK");
    sfText_setPosition(win->param.tab[3].tab, (sfVector2f){200, 825});
    for (int i = 0; i < NB_TAB_PARAM; i++)
        win->param.tab[i].boud = sfText_getGlobalBounds(win->param.tab[i].tab);
}

static void init_controls(window_t *win)
{
    (void)win;
}

static void init_back(window_t *win)
{
    win->param.s_bg = sfSprite_create();
    win->param.s_bg_tab = sfSprite_create();
    win->param.s_filter = sfSprite_create();
    win->param.t_bg = sfTexture_createFromFile("./assets/image/back_lobby.png",
        NULL);
    win->param.t_filter = sfTexture_createFromFile("./assets/image/filter.png",
        NULL);
    sfSprite_setTexture(win->param.s_bg, win->param.t_bg, sfTrue);
    sfSprite_setPosition(win->param.s_bg, (sfVector2f){100, 100});
    sfSprite_setScale(win->param.s_bg, (sfVector2f){1.25, 1.9});
    sfSprite_setTexture(win->param.s_bg_tab, win->param.t_bg, sfTrue);
    sfSprite_setPosition(win->param.s_bg_tab, (sfVector2f){800, 100});
    sfSprite_setScale(win->param.s_bg_tab, (sfVector2f){1.8, 1.9});
    sfSprite_setTexture(win->param.s_filter, win->param.t_filter, sfTrue);
    sfSprite_setPosition(win->param.s_filter, (sfVector2f){0, 0});
    sfSprite_setScale(win->param.s_filter, (sfVector2f){10, 10});
}

static void init_title(window_t *win)
{
    sfColor orange = sfColor_fromRGB(255, 165, 0);

    win->param.settings = sfText_create();
    sfText_setFont(win->param.settings, win->font);
    sfText_setCharacterSize(win->param.settings, 180);
    sfText_setPosition(win->param.settings, (sfVector2f){170, 95});
    sfText_setString(win->param.settings, "SETTINGS");
    sfText_setColor(win->param.settings, orange);
}

int init_param(window_t *win)
{
    init_tab(win);
    init_graphics(win);
    init_audio(win);
    init_controls(win);
    init_back(win);
    init_title(win);
    win->param.is_audio = false;
    win->param.is_controls = false;
    win->param.is_graphics = false;
    return EXIT_SUCCESS;
}
