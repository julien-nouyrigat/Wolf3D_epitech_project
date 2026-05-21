/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** param
*/

#include "wolf.h"

static void check_tab(window_t *win, sfVector2i *pos_mouse)
{
}

static void check_back(window_t *win, sfVector2i *pos_mouse)
{
    sfColor grey = sfColor_fromRGB(143, 143, 143);

    if (sfFloatRect_contains(&win->param.tab[3].boud, pos_mouse->x,
            pos_mouse->y)) {
        sfSprite_setPosition(win->menu.s_rect_back,
            sfText_getPosition(win->param.tab[3].tab));
        sfSprite_setScale(win->menu.s_rect_back, (sfVector2f){1.32, 1.2});
        sfText_setColor(win->param.tab[3].tab, sfWhite);
        sfRenderWindow_drawSprite(win->window, win->menu.s_rect_back, NULL);
        if (win->event.type == sfEvtMouseButtonPressed) {
            win->is_param = false;
            win->is_clickable = true;
        }
    } else
        sfText_setColor(win->param.tab[3].tab, grey);
}

void display_param(window_t *win)
{
    sfVector2i pos_mouse = sfMouse_getPositionRenderWindow(win->window);

    sfRenderWindow_drawSprite(win->window, win->param.s_bg, NULL);
    for (int i = 0; i < NB_TAB_PARAM; i++) {
        sfRenderWindow_drawText(win->window, win->param.tab[i].tab, NULL);
    }
    sfRenderWindow_drawText(win->window, win->param.settings, NULL);
    check_back(win, &pos_mouse);
    display_cursor(win);
}
