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

    sfText_setFont(win->menu.host, teko);
    sfText_setFont(win->menu.join, teko);
    sfText_setFont(win->menu.single, teko);
    sfText_setFont(win->menu.settings, teko);
    sfText_setFont(win->menu.quit, teko);
    sfText_setCharacterSize(win->menu.host, 100);
    sfText_setCharacterSize(win->menu.join, 100);
    sfText_setCharacterSize(win->menu.single, 100);
    sfText_setCharacterSize(win->menu.settings, 100);
    sfText_setCharacterSize(win->menu.quit, 100);
}

static void set_color(window_t *win)
{
    sfRectangleShape_setFillColor(win->menu.host_rect, sfTransparent);
    sfRectangleShape_setFillColor(win->menu.join_rect, sfTransparent);
    sfRectangleShape_setFillColor(win->menu.single_rect, sfTransparent);
    sfRectangleShape_setFillColor(win->menu.settings_rect, sfTransparent);
    sfRectangleShape_setFillColor(win->menu.quit_rect, sfTransparent);
    sfRectangleShape_setOutlineColor(win->menu.host_rect, sfTransparent);
    sfRectangleShape_setOutlineColor(win->menu.join_rect, sfTransparent);
    sfRectangleShape_setOutlineColor(win->menu.single_rect, sfTransparent);
    sfRectangleShape_setOutlineColor(win->menu.settings_rect, sfTransparent);
    sfRectangleShape_setOutlineColor(win->menu.quit_rect, sfTransparent);
    sfRectangleShape_setOutlineThickness(win->menu.host_rect, 1.0);
    sfRectangleShape_setOutlineThickness(win->menu.join_rect, 1.0);
    sfRectangleShape_setOutlineThickness(win->menu.single_rect, 1.0);
    sfRectangleShape_setOutlineThickness(win->menu.settings_rect, 1.0);
    sfRectangleShape_setOutlineThickness(win->menu.quit_rect, 1.0);
}

void get_bound_rect(window_t *win)
{
    win->menu.host_bound = sfRectangleShape_getGlobalBounds(
        win->menu.host_rect);
    win->menu.join_bound = sfRectangleShape_getGlobalBounds(
        win->menu.join_rect);
    win->menu.single_bound = sfRectangleShape_getGlobalBounds(
        win->menu.single_rect);
    win->menu.settings_bound = sfRectangleShape_getGlobalBounds(
        win->menu.settings_rect);
    win->menu.quit_bound = sfRectangleShape_getGlobalBounds(
        win->menu.quit_rect);
}

static void init_rect_menu(window_t *win)
{
    win->menu.host_rect = sfRectangleShape_create();
    win->menu.join_rect = sfRectangleShape_create();
    win->menu.single_rect = sfRectangleShape_create();
    win->menu.settings_rect = sfRectangleShape_create();
    win->menu.quit_rect = sfRectangleShape_create();
    sfRectangleShape_setSize(win->menu.host_rect, (sfVector2f){320, 100});
    sfRectangleShape_setSize(win->menu.join_rect, (sfVector2f){310, 100});
    sfRectangleShape_setSize(win->menu.single_rect, (sfVector2f){400, 100});
    sfRectangleShape_setSize(win->menu.settings_rect, (sfVector2f){275, 100});
    sfRectangleShape_setSize(win->menu.quit_rect, (sfVector2f){310, 100});
    sfRectangleShape_setPosition(win->menu.host_rect, (sfVector2f){110, 415});
    sfRectangleShape_setPosition(win->menu.join_rect, (sfVector2f){110, 535});
    sfRectangleShape_setPosition(win->menu.single_rect, (sfVector2f){110, 655});
    sfRectangleShape_setPosition(win->menu.settings_rect,
        (sfVector2f){110, 775});
    sfRectangleShape_setPosition(win->menu.quit_rect, (sfVector2f){110, 895});
    get_bound_rect(win);
}

static void init_text_menu(window_t *win, sfColor *grey)
{
    win->menu.host = sfText_create();
    win->menu.join = sfText_create();
    win->menu.single = sfText_create();
    win->menu.settings = sfText_create();
    win->menu.quit = sfText_create();
    sfText_setString(win->menu.host, "HOST GAME");
    sfText_setString(win->menu.join, "JOIN GAME");
    sfText_setString(win->menu.single, "SINGLEPLAYER");
    sfText_setString(win->menu.settings, "SETTINGS");
    sfText_setString(win->menu.quit, "QUIT GAME");
    sfText_setPosition(win->menu.host, (sfVector2f){120, 400});
    sfText_setPosition(win->menu.join, (sfVector2f){120, 520});
    sfText_setPosition(win->menu.single, (sfVector2f){120, 640});
    sfText_setPosition(win->menu.settings, (sfVector2f){120, 760});
    sfText_setPosition(win->menu.quit, (sfVector2f){120, 880});
    sfText_setColor(win->menu.host, *grey);
    sfText_setColor(win->menu.join, *grey);
    sfText_setColor(win->menu.single, *grey);
    sfText_setColor(win->menu.settings, *grey);
    sfText_setColor(win->menu.quit, *grey);
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
    sfSprite_setPosition(win->menu.s_rect_back, (sfVector2f){-1000, -1000});
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
    win->menu.music = sfMusic_createFromFile(
        "./assets/sounds/01_Main_Menu.mp3");
    return EXIT_SUCCESS;
}
