/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** init_graphics
*/

#include "wolf.h"

static void init_size_screen(window_t *win)
{
    sfText_setString(win->graphics.tab[0].text, "Windowed");
    sfText_setColor(win->graphics.tab[0].text, sfWhite);
    sfText_setCharacterSize(win->graphics.tab[0].text, 100);
    sfText_setPosition(win->graphics.tab[0].text, (sfVector2f){900, 400});
    sfText_setString(win->graphics.tab[1].text, "Fullscreen");
    sfText_setColor(win->graphics.tab[1].text, sfWhite);
    sfText_setCharacterSize(win->graphics.tab[1].text, 100);
    sfText_setPosition(win->graphics.tab[1].text, (sfVector2f){1300, 400});
}

static void init_resolution_mid(window_t *win)
{
    sfText_setString(win->graphics.tab[2].text, "1280 x 720");
    sfText_setColor(win->graphics.tab[2].text, sfWhite);
    sfText_setCharacterSize(win->graphics.tab[2].text, 100);
    sfText_setPosition(win->graphics.tab[2].text, (sfVector2f){900, 600});
    sfText_setString(win->graphics.tab[3].text, "1980 x 1080");
    sfText_setColor(win->graphics.tab[3].text, sfWhite);
    sfText_setCharacterSize(win->graphics.tab[3].text, 100);
    sfText_setPosition(win->graphics.tab[3].text, (sfVector2f){1300, 600});
}

static void init_resolution_high(window_t *win)
{
    sfText_setString(win->graphics.tab[4].text, "2560 x 1440");
    sfText_setColor(win->graphics.tab[4].text, sfWhite);
    sfText_setCharacterSize(win->graphics.tab[4].text, 100);
    sfText_setPosition(win->graphics.tab[4].text, (sfVector2f){900, 800});
    sfText_setString(win->graphics.tab[5].text, "3840 x 2160");
    sfText_setColor(win->graphics.tab[5].text, sfWhite);
    sfText_setCharacterSize(win->graphics.tab[5].text, 100);
    sfText_setPosition(win->graphics.tab[5].text, (sfVector2f){1300, 800});
}

static void init_title(window_t *win)
{
    sfColor orange = sfColor_fromRGB(255, 165, 0);

    sfText_setString(win->graphics.title, "GRAPHICS");
    sfText_setColor(win->graphics.title, orange);
    sfText_setCharacterSize(win->graphics.title, 180);
    sfText_setPosition(win->graphics.title, (sfVector2f){1030, 95});
}

void init_graphics(window_t *win)
{
    win->graphics.title = sfText_create();
    sfText_setFont(win->graphics.title, win->font);
    for (size_t i = 0; i < NB_RESOLUTION; i++) {
        win->graphics.tab[i].text = sfText_create();
        sfText_setFont(win->graphics.tab[i].text, win->font);
        win->graphics.tab[i].rect = sfRectangleShape_create();
    }
    init_title(win);
    init_size_screen(win);
    init_resolution_mid(win);
    init_resolution_high(win);
    for (size_t i = 0; i < NB_RESOLUTION; i++)
        win->graphics.tab[i].bound = sfText_getGlobalBounds(
            win->graphics.tab[i].text);
}
