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
    #include "client.h"
    #include "server.h"
    #include "map.h"

    #undef EXIT_SUCCESS
    #undef EXIT_FAILURE
    #undef M_PI

    #define EXIT_SUCCESS 0
    #define EXIT_FAILURE 84
    #define M_PI 3.1415926535

int flag_h(void);
int wolf(client_t *client);
void destroy_assets(window_t *wolf_win, player_t *player);
int init_window(window_t *wolf_win);
int init_player(player_t **player);
bool manage_keyboard(sfEvent *event, input_enum_t *input);
void moove_forward(player_t *player);
void moove_backward(player_t *player);
void rotate_left(player_t *player);
void rotate_right(player_t *player);
int init_map(map_t **map);
void init_ray(ray_t *ray);
void draw_2d_player(window_t *wolf_win, player_t *player);
void draw_2d_map(window_t *wolf_win, map_t *map);
void window_pseudo(window_t *wolf_win);
void window_ip(window_t *wolf_win);
void display_pseudo(window_t *win_wolf);
void display_ip(window_t *win_wolf);

#endif /* WOLF_H_ */
