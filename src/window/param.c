/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** param
*/

#include "wolf.h"

static void check_controls(window_t *win, sfVector2i *pos_mouse)
{
    sfColor grey = sfColor_fromRGB(143, 143, 143);

    if (sfFloatRect_contains(&win->param.tab[2].boud, pos_mouse->x,
            pos_mouse->y)) {
        sfSprite_setPosition(win->menu.s_rect_back, (sfVector2f){185, 612});
        sfSprite_setScale(win->menu.s_rect_back, (sfVector2f){1.14, 1.2});
        sfText_setColor(win->param.tab[2].tab, sfWhite);
        sfRenderWindow_drawSprite(win->window, win->menu.s_rect_back, NULL);
        sfRenderWindow_drawText(win->window, win->param.tab[2].tab, NULL);
        if (win->event.type == sfEvtMouseButtonPressed) {
            win->param.is_audio = false;
            win->param.is_controls = true;
            win->param.is_graphics = false;
        }
    } else
        sfText_setColor(win->param.tab[2].tab, grey);
}

static void check_audio(window_t *win, sfVector2i *pos_mouse)
{
    sfColor grey = sfColor_fromRGB(143, 143, 143);

    if (sfFloatRect_contains(&win->param.tab[1].boud, pos_mouse->x,
            pos_mouse->y)) {
        sfSprite_setPosition(win->menu.s_rect_back, (sfVector2f){190, 462});
        sfSprite_setScale(win->menu.s_rect_back, (sfVector2f){0.7, 1.2});
        sfRenderWindow_drawSprite(win->window, win->menu.s_rect_back, NULL);
        sfText_setColor(win->param.tab[1].tab, sfWhite);
        sfRenderWindow_drawText(win->window, win->param.tab[1].tab, NULL);
        if (win->event.type == sfEvtMouseButtonPressed) {
            win->param.is_audio = true;
            win->param.is_controls = false;
            win->param.is_graphics = false;
        }
    } else
        sfText_setColor(win->param.tab[1].tab, grey);
}

static void check_graphic(window_t *win, sfVector2i *pos_mouse)
{
    sfColor grey = sfColor_fromRGB(143, 143, 143);

    if (sfFloatRect_contains(&win->param.tab[0].boud, pos_mouse->x,
            pos_mouse->y)) {
        sfSprite_setPosition(win->menu.s_rect_back, (sfVector2f){185, 312});
        sfSprite_setScale(win->menu.s_rect_back, (sfVector2f){1.12, 1.2});
        sfRenderWindow_drawSprite(win->window, win->menu.s_rect_back, NULL);
        sfText_setColor(win->param.tab[0].tab, sfWhite);
        sfRenderWindow_drawText(win->window, win->param.tab[0].tab, NULL);
        if (win->event.type == sfEvtMouseButtonPressed) {
            win->param.is_audio = false;
            win->param.is_controls = false;
            win->param.is_graphics = true;
        }
    } else
        sfText_setColor(win->param.tab[0].tab, grey);
}

static void check_back(window_t *win, sfVector2i *pos_mouse)
{
    sfColor grey = sfColor_fromRGB(143, 143, 143);

    if (sfFloatRect_contains(&win->param.tab[3].boud, pos_mouse->x,
            pos_mouse->y)) {
        sfSprite_setPosition(win->menu.s_rect_back, (sfVector2f){190, 842});
        sfSprite_setScale(win->menu.s_rect_back, (sfVector2f){0.62, 1.2});
        sfRenderWindow_drawSprite(win->window, win->menu.s_rect_back, NULL);
        sfText_setColor(win->param.tab[3].tab, sfWhite);
        sfRenderWindow_drawText(win->window, win->param.tab[3].tab, NULL);
        if (win->event.type == sfEvtMouseButtonPressed) {
            win->is_param = false;
            win->is_clickable = true;
        }
    } else
        sfText_setColor(win->param.tab[3].tab, grey);
}

static void manage_tab(window_t *win)
{
    if (win->param.is_audio)
        display_audio(win);
    if (win->param.is_graphics)
        display_graphics(win);
}

void display_param(window_t *win)
{
    sfVector2i pos_mouse = sfMouse_getPositionRenderWindow(win->window);

    sfRenderWindow_drawSprite(win->window, win->param.s_filter, NULL);
    sfRenderWindow_drawSprite(win->window, win->param.s_bg, NULL);
    sfRenderWindow_drawSprite(win->window, win->param.s_bg_tab, NULL);
    for (int i = 0; i < NB_TAB_PARAM; i++) {
        sfRenderWindow_drawText(win->window, win->param.tab[i].tab, NULL);
    }
    check_back(win, &pos_mouse);
    check_graphic(win, &pos_mouse);
    check_audio(win, &pos_mouse);
    check_controls(win, &pos_mouse);
    sfRenderWindow_drawText(win->window, win->param.settings, NULL);
    manage_tab(win);
    display_cursor(win);
}
