/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** graphics
*/

#include "wolf.h"

static void resize_view(window_t *win)
{
    float window_ratio = (float)win->width / win->height;
    float view_ratio = (float)WIN_WIDTH / WIN_HEIGHT;
    sfVector2f size = {1, 1};
    sfVector2f pos = {0, 0};

    if (window_ratio > view_ratio) {
        size.x = view_ratio / window_ratio;
        pos.x = (1 - size.x) / 2;
    } else {
        size.y = window_ratio / view_ratio;
        pos.y = (1 - size.y) / 2;
    }
    sfView_setViewport(win->view,
        (sfFloatRect){pos.x, pos.y, size.x, size.y});
    sfRenderWindow_setView(win->window, win->view);
}

static void change_resolution(window_t *win, int width, int height,
    bool fullscreen)
{
    sfVideoMode mode = {width, height, WIN_BPP};
    sfUint32 style = {sfClose};

    if (win->width == width && win->height == height &&
        win->is_fullscreen == fullscreen)
        return;
    if (fullscreen)
        style |= sfFullscreen;
    else
        style |= sfResize;
    sfRenderWindow_destroy(win->window);
    win->window = sfRenderWindow_create(mode, "Wolf3D", style, NULL);
    win->width = width;
    win->height = height;
    win->is_fullscreen = fullscreen;
    sfRenderWindow_setMouseCursorVisible(win->window, sfFalse);
    resize_view(win);
}

static void check_size_screen(window_t *win)
{
    sfVector2i pos_mouse = sfMouse_getPositionRenderWindow(win->window);
    sfVideoMode desktop = sfVideoMode_getDesktopMode();

    if (sfFloatRect_contains(&win->graphics.tab[0].bound, pos_mouse.x,
            pos_mouse.y)) {
        if (win->event.type == sfEvtMouseButtonPressed)
            change_resolution(win, WIN_WIDTH, WIN_HEIGHT, false);
    }
    if (sfFloatRect_contains(&win->graphics.tab[1].bound, pos_mouse.x,
            pos_mouse.y)) {
        if (win->event.type == sfEvtMouseButtonPressed)
            change_resolution(win, desktop.width, desktop.height, true);
    }
}

void display_graphics(window_t *win)
{
    sfRenderWindow_drawText(win->window, win->graphics.title, NULL);
    for (size_t i = 0; i < NB_RESOLUTION; i++) {
        sfRenderWindow_drawText(win->window, win->graphics.tab[i].text, NULL);
    }
    check_size_screen(win);
}
