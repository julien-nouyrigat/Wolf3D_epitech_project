/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** window
*/

#ifndef WINDOW_H_
    #define WINDOW_H_

    #include <stdio.h>
    #include <SFML/Graphics.h>
    #include <SFML/Graphics/Export.h>
    #include <SFML/Graphics/BlendMode.h>
    #include <SFML/Graphics/Color.h>
    #include <SFML/Graphics/Rect.h>
    #include <SFML/Graphics/Transform.h>
    #include <SFML/Graphics/Types.h>
    #include <SFML/System/Vector2.h>
    #include <SFML/Audio.h>
    #include <stdbool.h>

    #define FRAMES_LIMIT 60
    #define WIN_WIDTH 1980
    #define WIN_HEIGHT 1080
    #define WIN_BPP 32
    #define LINE_SIZE 3
    #define COL_BG 29
    #define LINE_BG 28
    #define LAST_LINE_BG 6
    #define SIZE_X_BG (9280 / COL_BG)
    #define SIZE_Y_BG (5040 / LINE_BG)
    #define IPS_BG (1.0 / 24)

typedef struct {
    sfTexture *t_bg;
    sfSprite *s_bg;
    sfIntRect rect_bg;
    int line_ss_bg;
    int col_ss_bg;
    sfTexture *t_title;
    sfSprite *s_title;
    sfTexture *t_point;
    sfSprite *s_point;
    sfText *host;
    sfRectangleShape *host_rect;
    sfFloatRect host_bound;
    sfText *join;
    sfRectangleShape *join_rect;
    sfFloatRect join_bound;
    sfText *single;
    sfRectangleShape *single_rect;
    sfFloatRect single_bound;
    sfText *settings;
    sfRectangleShape *settings_rect;
    sfFloatRect settings_bound;
    sfText *quit;
    sfRectangleShape *quit_rect;
    sfFloatRect quit_bound;
    sfSprite *s_mouse;
    sfTexture *t_mouse;
    sfSprite *s_rect_back;
    sfTexture *t_rect_back;
    sfMusic *music;
} menu_t;

typedef struct player_lst_s {
    char pseudo[BUFSIZ];
    sfText *text_pseudo;
    sfTexture *t_profil;
    sfSprite *s_profil;
    struct player_lst_s *next;
} player_lst_t;

typedef struct {
    sfText *lobby;
    player_lst_t p_lst;
    sfRectangleShape *rect;
    sfText *leave;
    sfRectangleShape *leave_rect;
    sfFloatRect leave_bound;
    sfText *settings;
    sfRectangleShape *settings_rect;
    sfFloatRect settings_bound;
} lobby_t;

typedef struct {
    sfClock *clock;
    sfTime time;
    float elapsed_time_bg;
} win_clock_t;

typedef struct {
    sfRenderWindow *window;
    menu_t menu;
    lobby_t lobby;
    sfEvent event;
    sfVector2u size;
    sfColor bg_color;
    win_clock_t clock;
    bool is_menu;
    bool is_lobby;
    bool is_game;
    bool is_single;
    bool is_param;
} window_t;

#endif /* WINDOW_H_ */
