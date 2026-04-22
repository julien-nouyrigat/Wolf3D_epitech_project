/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** menu
*/

#include "wolf.h"

static void display_tab(window_t *win)
{
    sfRenderWindow_drawText(win->window, win->menu.host, NULL);
    sfRenderWindow_drawText(win->window, win->menu.join, NULL);
    sfRenderWindow_drawText(win->window, win->menu.single, NULL);
    sfRenderWindow_drawText(win->window, win->menu.settings, NULL);
    sfRenderWindow_drawText(win->window, win->menu.quit, NULL);
}

static void display_title(window_t *win)
{
    sfRenderWindow_drawSprite(win->window, win->menu.s_title, NULL);
    sfSprite_setPosition(win->menu.s_point, (sfVector2f){278, 230});
    sfRenderWindow_drawSprite(win->window, win->menu.s_point, NULL);
    sfSprite_setPosition(win->menu.s_point, (sfVector2f){465, 230});
    sfRenderWindow_drawSprite(win->window, win->menu.s_point, NULL);
    sfSprite_setPosition(win->menu.s_point, (sfVector2f){650, 230});
    sfRenderWindow_drawSprite(win->window, win->menu.s_point, NULL);
    sfSprite_setPosition(win->menu.s_point, (sfVector2f){870, 230});
    sfRenderWindow_drawSprite(win->window, win->menu.s_point, NULL);
    sfSprite_setPosition(win->menu.s_point, (sfVector2f){1050, 230});
    sfRenderWindow_drawSprite(win->window, win->menu.s_point, NULL);
}

static void change_color_action(window_t *win, sfVector2i *mp, sfColor *grey)
{
    if (sfFloatRect_contains(&(win->menu.settings_bound), mp->x, mp->y)) {
        sfSprite_setPosition(win->menu.s_rect_back, (sfVector2f){100, 775});
        sfSprite_setScale(win->menu.s_rect_back, (sfVector2f){1.12, 1.2});
        sfText_setColor(win->menu.settings, sfWhite);
    } else {
        sfText_setColor(win->menu.settings, *grey);
    }
    if (sfFloatRect_contains(&(win->menu.quit_bound), mp->x, mp->y)) {
        sfSprite_setPosition(win->menu.s_rect_back, (sfVector2f){100, 895});
        sfSprite_setScale(win->menu.s_rect_back, (sfVector2f){1.24, 1.2});
        sfText_setColor(win->menu.quit, sfWhite);
    } else {
        sfText_setColor(win->menu.quit, *grey);
    }
}

static void change_color_solo(window_t *win, sfVector2i *mp, sfColor *grey)
{
    if (sfFloatRect_contains(&(win->menu.single_bound), mp->x, mp->y)) {
        sfSprite_setPosition(win->menu.s_rect_back, (sfVector2f){100, 655});
        sfSprite_setScale(win->menu.s_rect_back, (sfVector2f){1.62, 1.2});
        sfText_setColor(win->menu.single, sfWhite);
    } else {
        sfText_setColor(win->menu.single, *grey);
    }
    if (!sfFloatRect_contains(&(win->menu.host_bound), mp->x, mp->y) &&
        !sfFloatRect_contains(&(win->menu.join_bound), mp->x, mp->y) &&
        !sfFloatRect_contains(&(win->menu.single_bound), mp->x, mp->y) &&
        !sfFloatRect_contains(&(win->menu.settings_bound), mp->x, mp->y) &&
        !sfFloatRect_contains(&(win->menu.quit_bound), mp->x, mp->y))
        sfSprite_setPosition(win->menu.s_rect_back, (sfVector2f){-1000, -1000});
}

static void change_color_multi(window_t *win, sfVector2i *mp)
{
    sfColor grey = sfColor_fromRGB(143, 143, 143);

    if (sfFloatRect_contains(&(win->menu.host_bound), mp->x, mp->y)) {
        sfSprite_setPosition(win->menu.s_rect_back, (sfVector2f){100, 415});
        sfSprite_setScale(win->menu.s_rect_back, (sfVector2f){1.32, 1.2});
        sfText_setColor(win->menu.host, sfWhite);
    } else
        sfText_setColor(win->menu.host, grey);
    if (sfFloatRect_contains(&(win->menu.join_bound), mp->x, mp->y)) {
        sfSprite_setPosition(win->menu.s_rect_back, (sfVector2f){100, 535});
        sfSprite_setScale(win->menu.s_rect_back, (sfVector2f){1.27, 1.2});
        sfText_setColor(win->menu.join, sfWhite);
    } else
        sfText_setColor(win->menu.join, grey);
    change_color_solo(win, mp, &grey);
    change_color_action(win, mp, &grey);
}

static void display_rect(window_t *win)
{
    sfVector2i mp = sfMouse_getPositionRenderWindow(win->window);

    change_color_multi(win, &mp);
    sfRenderWindow_drawRectangleShape(win->window, win->menu.host_rect, NULL);
    sfRenderWindow_drawRectangleShape(win->window, win->menu.join_rect, NULL);
    sfRenderWindow_drawRectangleShape(win->window, win->menu.single_rect, NULL);
    sfRenderWindow_drawRectangleShape(win->window, win->menu.settings_rect,
        NULL);
    sfRenderWindow_drawRectangleShape(win->window, win->menu.quit_rect, NULL);
    sfRenderWindow_drawSprite(win->window, win->menu.s_rect_back, NULL);
}

void display_menu(window_t *win)
{
    display_background_menu(win);
    display_title(win);
    display_rect(win);
    display_tab(win);
    display_cursor(win);
}
