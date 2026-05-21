/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** init_param
*/

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

static void init_graphic(window_t *win)
{
    (void)win;
}

static void init_audio(window_t *win)
{
    (void)win;
}

static void init_controls(window_t *win)
{
    (void)win;
}

int init_param(window_t *win)
{
    init_tab(win);
    init_graphic(win);
    init_audio(win);
    init_controls(win);
    return EXIT_SUCCESS;
}
