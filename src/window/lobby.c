/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** lobby
*/

#include "window.h"
#include "wolf.h"

static void manage_leave(window_t *win)
{
    sfVector2i mp = sfMouse_getPositionRenderWindow(win->window);

    if (sfFloatRect_contains(&win->lobby.leave_bound, mp.x, mp.y)) {
        sfRenderWindow_drawSprite(win->window, win->menu.s_rect_back, NULL);
        sfSprite_setPosition(win->menu.s_rect_back, (sfVector2f){70, 814});
        sfSprite_setScale(win->menu.s_rect_back, (sfVector2f){0.6, 0.9});
        if (win->event.type == sfEvtMouseButtonPressed) {
            win->is_menu = true;
            win->is_single = false;
            win->is_lobby = false;
        }
    }
    if (sfFloatRect_contains(&win->lobby.settings_bound, mp.x, mp.y)) {
        sfRenderWindow_drawSprite(win->window, win->menu.s_rect_back, NULL);
        sfSprite_setPosition(win->menu.s_rect_back, (sfVector2f){288, 814});
        sfSprite_setScale(win->menu.s_rect_back, (sfVector2f){0.85, 0.9});
        if (win->event.type == sfEvtMouseButtonPressed) {
            win->is_menu = true;
            win->is_single = false;
            win->is_lobby = false;
        }
    }
}

void display_lobby(window_t *win)
{
    display_background_menu(win);
    sfRenderWindow_drawSprite(win->window, win->lobby.s_back, NULL);
    manage_leave(win);
    sfRenderWindow_drawText(win->window, win->lobby.lobby, NULL);
    sfRenderWindow_drawText(win->window, win->lobby.settings, NULL);
    sfRenderWindow_drawText(win->window, win->lobby.leave, NULL);
    display_cursor(win);
}
