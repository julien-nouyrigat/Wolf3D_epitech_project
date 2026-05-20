/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** wolf
*/

#ifndef WOLF_H_
    #define WOLF_H_

    #include "window.h"
    #include "player.h"
    #include "map.h"
    #include "events.h"

    #undef EXIT_SUCCESS
    #undef EXIT_FAILURE

    #define EXIT_SUCCESS 0
    #define EXIT_FAILURE 84

    #define WALL 1
    #define SECOND 1000000.0
    #define HALF_SEC 0.5
    #define FULL_SEC 0.0

typedef enum {
    KEY_Z,
    KEY_S,
    KEY_Q,
    KEY_D,
    KEY_LEFT,
    KEY_RIGHT
} key_enum_t;

int flag_h(void);
int wolf(void);
void down_cam(player_t *player, map_t *map);
void up_cam(player_t *player, map_t *map);
void init_lamp(window_t *wolf_win);
void display_lamp(window_t *win);
void destroy_assets(window_t *wolf_win, player_t *player);
int init_window(window_t *wolf_win);
int init_player(player_t **player);
void manage_keyboard(player_t *player, map_t *map);
void close_window(window_t *win, player_t *player, map_t *map);
void resize_window(window_t *win, player_t *player, map_t *map);
void move_forward(player_t *player, map_t *map);
void move_backward(player_t *player, map_t *map);
void move_left(player_t *player, map_t *map);
void move_right(player_t *player, map_t *map);
void rotate_left(player_t *player, map_t *map);
void rotate_right(player_t *player, map_t *map);
int init_map(map_t **map);
void init_ray(ray_t *ray);
void draw_2d_player(window_t *wolf_win, player_t *player);
void draw_2d_map(window_t *wolf_win, map_t *map);
void dda_algorithm(player_t *player, map_t *map, window_t *win);
void draw_wall(ray_t *ray, window_t *win, map_t *map, player_t *player);
int init_brackground_menu(window_t *win);
void display_background_menu(window_t *win);
int init_menu(window_t *win);
void display_menu(window_t *win);
void display_lobby(window_t *win);
void display_cursor(window_t *win);
void init_cursor(window_t *win);
int create_textures(window_t *win);
void draw_floor(ray_t *ray, window_t *win, map_t *map, player_t *player);
char *my_itoa(int nb);
void create_hud(window_t *win);
int display_hud(window_t *win, player_t *player);
void sprint(player_t *player, map_t *map);
void stop_sprint(window_t *win, player_t *player, map_t *map);
void stamina_regen(player_t *player);
void manage_client_network(window_t *win, player_t *player, map_t *map);
void send_key_move(key_enum_t key, window_t *win);
int init_lobby(window_t *win);

#endif /* WOLF_H_ */
