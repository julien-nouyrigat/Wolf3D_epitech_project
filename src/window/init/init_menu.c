/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** init_menu
*/

#include "window.h"
#include "wolf.h"

static void set_font_size(window_t *win)
{
    sfFont *teko = sfFont_createFromFile("./assets/fonts/teko.ttf");

    for (int i = 0; i < NB_TAB_MENU; i++) {
        sfText_setFont(win->menu.tab[i].text, teko);
        sfText_setCharacterSize(win->menu.tab[i].text, 100);
    }
}

static void set_color(window_t *win)
{
    for (int i = 0; i < NB_TAB_MENU; i++) {
        sfRectangleShape_setFillColor(win->menu.tab[i].rect, sfTransparent);
        sfRectangleShape_setOutlineColor(win->menu.tab[i].rect, sfTransparent);
        sfRectangleShape_setOutlineThickness(win->menu.tab[i].rect, 1.0);
    }
}

void get_bound_rect(window_t *win)
{
    for (int i = 0; i < NB_TAB_MENU; i++)
        win->menu.tab[i].bound = sfRectangleShape_getGlobalBounds(
            win->menu.tab[i].rect);
}

static void init_rect_menu(window_t *win)
{
    for (int i = 0; i < NB_TAB_MENU; i++) {
        win->menu.tab[i].rect = sfRectangleShape_create();
    }
    sfRectangleShape_setSize(win->menu.tab[0].rect, (sfVector2f){320, 100});
    sfRectangleShape_setSize(win->menu.tab[1].rect, (sfVector2f){310, 100});
    sfRectangleShape_setSize(win->menu.tab[2].rect, (sfVector2f){400, 100});
    sfRectangleShape_setSize(win->menu.tab[3].rect, (sfVector2f){275, 100});
    sfRectangleShape_setSize(win->menu.tab[4].rect, (sfVector2f){310, 100});
    sfRectangleShape_setPosition(win->menu.tab[0].rect, (sfVector2f){110, 415});
    sfRectangleShape_setPosition(win->menu.tab[1].rect, (sfVector2f){110, 535});
    sfRectangleShape_setPosition(win->menu.tab[2].rect, (sfVector2f){110, 655});
    sfRectangleShape_setPosition(win->menu.tab[3].rect,
        (sfVector2f){110, 775});
    sfRectangleShape_setPosition(win->menu.tab[4].rect, (sfVector2f){110, 895});
    get_bound_rect(win);
}

static void init_text_menu(window_t *win, sfColor *grey)
{
    int y_rect = 400;

    for (int i = 0; i < NB_TAB_MENU; i++)
        win->menu.tab[i].text = sfText_create();
    sfText_setString(win->menu.tab[0].text, "HOST GAME");
    sfText_setString(win->menu.tab[1].text, "JOIN GAME");
    sfText_setString(win->menu.tab[2].text, "SINGLEPLAYER");
    sfText_setString(win->menu.tab[3].text, "SETTINGS");
    sfText_setString(win->menu.tab[4].text, "QUIT GAME");
    for (int i = 0; i < NB_TAB_MENU; i++) {
        sfText_setPosition(win->menu.tab[i].text, (sfVector2f){120, y_rect});
        y_rect += 120;
    }
    for (int i = 0; i < NB_TAB_MENU; i++)
        sfText_setColor(win->menu.tab[i].text, *grey);
}

static void init_title(window_t *win)
{
    win->menu.s_title = sfSprite_create();
    win->menu.t_title = sfTexture_createFromFile(
        "./assets/image/depot_title.png", NULL);
    sfSprite_setTexture(win->menu.s_title, win->menu.t_title, sfTrue);
    sfSprite_setScale(win->menu.s_title, (sfVector2f){1, 1.4});
    sfSprite_setPosition(win->menu.s_title, (sfVector2f){70, 50});
    win->menu.s_point = sfSprite_create();
    win->menu.t_point = sfTexture_createFromFile(
        "./assets/image/point.png", NULL);
    sfSprite_setTexture(win->menu.s_point, win->menu.t_point, sfTrue);
    sfSprite_setScale(win->menu.s_point, (sfVector2f){0.21, 0.21});
    sfSprite_setPosition(win->menu.s_point, (sfVector2f){278, 230});
}

void init_rect_back(window_t *win)
{
    win->menu.s_rect_back = sfSprite_create();
    win->menu.t_rect_back = sfTexture_createFromFile(
        "./assets/image/rect_butt.png", NULL);
    sfSprite_setTexture(win->menu.s_rect_back, win->menu.t_rect_back, sfTrue);
}

int init_menu(window_t *win)
{
    sfColor grey = sfColor_fromRGB(143, 143, 143);

    sfRenderWindow_setMouseCursorVisible(win->window, sfFalse);
    win->is_menu = true;
    win->is_lobby = false;
    win->is_game = false;
    win->is_param = false;
    win->is_single = false;
    init_text_menu(win, &grey);
    set_font_size(win);
    init_rect_menu(win);
    init_rect_back(win);
    set_color(win);
    init_title(win);
    init_cursor(win);
    win->menu.music_started = false;
    win->menu.music = sfMusic_createFromFile(
        "./assets/sounds/01_Main_Menu.mp3");
    return EXIT_SUCCESS;
}
