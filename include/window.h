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
    #include <arpa/inet.h>
    #include <SFML/Audio.h>
    #include <stdbool.h>

    #include "music.h"
    #include "weapons.h"
    #include "boutique.h"

    #define FRAMES_LIMIT 60
    #define WIN_WIDTH 1920
    #define WIN_HEIGHT 1080
    #define WIN_BPP 32
    #define LINE_SIZE 3
    #define COL_BG 29
    #define LINE_BG 28
    #define COL_GUN 3
    #define LINE_GUN 3
    #define LAST_LINE_BG 6
    #define SIZE_X_BG (9280 / COL_BG)
    #define SIZE_Y_BG (5040 / LINE_BG)
    #define SIZE_X_GUN (539 / COL_GUN)
    #define SIZE_Y_GUN (463 / LINE_GUN)
    #define IPS_BG (1.0 / 24)
    #define COL_TRANS 8
    #define LINE_TRANS 18
    #define LAST_LINE_TRANS 5
    #define SIZE_X_TRANS (2048 / COL_TRANS)
    #define SIZE_Y_TRANS (2394 / LINE_TRANS)
    #define IPS_TRANS (1.0 / 24)
    #define NB_TAB_MENU 5
    #define NB_TAB_PARAM 4
    #define HEALTH_COLOR sfColor_fromRGB(82, 252, 123)
    #define STAMINA_COLOR sfColor_fromRGB(234, 255, 33)
    #define MONEY_COLOR sfColor_fromRGB(142, 142, 142)
    #define HUD_TEXT_SIZE 55
    #define NB_RECT_AUDIO 4
    #define NB_TEXT_AUDIO 5
    #define AMBIANCE 50
    #define RENDER_DISTANCE 20
    #define NB_RESOLUTION 6
    #define GRAY sfColor_fromRGB(143, 143, 143)

    #define GUN_DAMAGE 15
    #define GUN_COOLDOWN 1

    #define MAX_CLIENTS 6

typedef struct {
    float pos_x;
    float pos_y;
    float pos_tile_x;
    float pos_tile_y;
    float direction_x;
    float direction_y;
    int mvt_speed;
} player_state_t;

typedef struct {
    sfText *text;
    sfRectangleShape *rect;
    sfFloatRect bound;
} tab_t;

typedef struct {
    uint8_t id;
    int sock_tcp;
    int sock_udp;
    struct sockaddr_in sa_in_tcp;
    struct sockaddr_in sa_in_udp;
    player_state_t other[MAX_CLIENTS];
    sfTexture *t_player;
} client_t;

typedef struct {
    sfText *tab;
    sfFloatRect boud;
} tab_param_t;

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
    tab_t tab[NB_TAB_MENU];
    sfSprite *s_mouse;
    sfTexture *t_mouse;
    sfSprite *s_rect_back;
    sfTexture *t_rect_back;
    sfMusic *music;
    bool music_started;
} menu_t;

typedef struct {
    sfText *text;
    sfFloatRect bound;
} audio_text_t;

typedef struct {
    sfRectangleShape *rect;
} audio_rect_t;

typedef struct {
    uint8_t volume;
    char string_pourcent[BUFSIZ];
    audio_text_t audio_txt[NB_TEXT_AUDIO];
    audio_rect_t audio_rect[NB_RECT_AUDIO];
} audio_t;

typedef struct {
    sfText *text;
    sfRectangleShape *rect;
    sfFloatRect bound;
} resolutions_t;

typedef struct {
    sfText *title;
    resolutions_t tab[NB_RESOLUTION];
} graphics_t;

typedef struct {
    sfSprite *s_bg;
    sfTexture *t_bg;
    sfSprite *s_bg_tab;
    sfText *settings;
    tab_param_t tab[NB_TAB_PARAM];
    audio_t audio;
    sfTexture *t_filter;
    sfSprite *s_filter;
    bool is_graphics;
    bool is_audio;
    bool is_controls;
} param_t;

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
    sfClock *broad_clock;
    sfClock *gun_clock;
    sfClock *trans_clock;
    sfTime time;
    float elapsed_time_bg;
    float elapsed_time_gun;
    float elapsed_time_trans;
} win_clock_t;

typedef struct {
    sfTexture *t_lamp;
    sfTexture *t_dark;
    sfTexture *t_light_of;
    sfTexture *t_gun;
    sfSprite *lamp;
    sfSprite *dark;
    sfSprite *light_of;
    sfSprite *gun;
    sfIntRect rect_gun;
    int line_ss_gun;
    int col_ss_gun;
    bool shoot;
    int current_frame;
    float anim_time;
} game_t;

typedef struct {
    sfText *life;
    sfText *stamina;
    sfText *lvl_money;
    sfText *player_money;
    sfText *dead_text;
    sfText *go_back;
    sfSprite *cross;
    sfSprite *lightning;
} hud_t;

typedef struct {
    sfRectangleShape *wall;
    sfCircleShape *player;
    sfTexture *t_player;
    sfSprite *s_player;
    sfRectangleShape *bg;
    bool is_minimap;
    sfSprite *s_tv;
    sfTexture *t_tv;
} minimap_t;

typedef enum {
    NONE,
    TRANSITION_TO_SHOP,
    TRANSITION_TO_GAME
} transition_state_t;

typedef struct {
    sfTexture *t_bg;
    sfSprite *s_bg;
    sfIntRect rect_bg;
    int line;
    int col;
    bool is_play;
    transition_state_t next_state;
} transition_t;

typedef struct {
    sfRenderWindow *window;
    menu_t menu;
    game_t game;
    lobby_t lobby;
    param_t param;
    sfEvent event;
    sfVector2u size;
    sfColor bg_color;
    win_clock_t clock;
    bool is_menu;
    bool is_lobby;
    bool is_game;
    bool is_single;
    bool is_param;
    sfTexture **textures;
    sfFont *font;
    hud_t hud;
    client_t *client;
    bool is_clickable;
    sfMusic *footsteps;
    music_t tab_music[NB_MUSIC];
    sfMusic *ambiance;
    bool ambiance_started;
    graphics_t graphics;
    sfView *view;
    bool is_fullscreen;
    int width;
    int height;
    sfMusic *gun_sound;
    sfMusic *hurt_sound;
    sfView *view_minimap;
    minimap_t minimap;
    weapon_t **weapons_tab;
    sfTexture **weapons_texts;
    sfTexture **icons_texts;
    transition_t transition;
    bool is_lamp;
    bool is_gun;
    shop_t *shop;
    bool is_shop;
} window_t;

#endif /* WINDOW_H_ */
