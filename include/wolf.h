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

    #undef EXIT_SUCCESS
    #undef EXIT_FAILURE

    #define EXIT_SUCCESS 0
    #define EXIT_FAILURE 84

int flag_h(void);
int wolf(void);
void destroy_assets(window_t *wolf_win, player_t *player);
int init_window(window_t *wolf_win);
int init_player(player_t **player);
void manage_keyboard(sfEvent *event, player_t *player, map_t *map);
void move_forward(player_t *player, map_t *map);
void move_backward(player_t *player, map_t *map);
void rotate_left(player_t *player, map_t *map);
void rotate_right(player_t *player, map_t *map);
int init_map(map_t **map);
void init_ray(ray_t *ray);
void draw_2d_player(window_t *wolf_win, player_t *player);
void draw_2d_map(window_t *wolf_win, map_t *map);
void dda_algorithm(player_t *player, map_t *map, window_t *win);
void draw_wall(ray_t *ray, window_t *win);

#endif /* WOLF_H_ */
