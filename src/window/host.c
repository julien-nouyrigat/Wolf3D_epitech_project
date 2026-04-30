/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** host
*/

#include "server.h"
#include "wolf.h"

static void draw_text(window_t *win)
{
    sfRenderWindow_drawText(win->window, win->host.title, NULL);
    sfRenderWindow_drawText(win->window, win->host.back, NULL);
    sfRenderWindow_drawText(win->window, win->host.new, NULL);
}

static void new_but(window_t *win)
{
    sfVector2i mp = sfMouse_getPositionRenderWindow(win->window);
    sfColor grey = sfColor_fromRGB(143, 143, 143);
    char buff[1];

    if (sfFloatRect_contains(&win->host.new_bound, mp.x, mp.y)) {
        sfSprite_setScale(win->menu.s_rect_back, (sfVector2f){0.9, 1});
        sfSprite_setPosition(win->menu.s_rect_back, (sfVector2f){180, 315});
        sfRenderWindow_drawSprite(win->window, win->menu.s_rect_back, NULL);
        sfText_setColor(win->host.new, sfWhite);
        if (win->event.type == sfEvtMouseButtonPressed) {
            win->is_lobby = true;
            buff[0] = CREATE_ROOM;
            send(win->client->sock_tcp, buff, 1, 0);
            win->is_host_game = false;
        }
    } else
        sfText_setColor(win->host.new, grey);
}

static void back_butt(window_t *win)
{
    sfVector2i mp = sfMouse_getPositionRenderWindow(win->window);

    if (sfFloatRect_contains(&win->host.back_bound, mp.x, mp.y)) {
        sfSprite_setScale(win->menu.s_rect_back, (sfVector2f){0.9, 1});
        sfSprite_setPosition(win->menu.s_rect_back, (sfVector2f){180, 145});
        sfRenderWindow_drawSprite(win->window, win->menu.s_rect_back, NULL);
        if (win->event.type == sfEvtMouseButtonPressed) {
            win->is_menu = true;
            win->is_host_game = false;
        }
    }
    new_but(win);
}

void display_host(window_t *win)
{
    display_background_menu(win);
    sfRenderWindow_drawSprite(win->window, win->host.s_back, NULL);
    back_butt(win);
    draw_text(win);
    display_cursor(win);
}
