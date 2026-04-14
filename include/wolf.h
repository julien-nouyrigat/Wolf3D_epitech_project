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

    #undef EXIT_SUCCESS
    #undef EXIT_FAILURE

    #define EXIT_SUCCESS 0
    #define EXIT_FAILURE 84

int flag_h(void);
int wolf(void);
void destroy_assets(window_t *wolf_win, player_t *player);
int init_window(window_t *wolf_win);
int init_player(player_t *player);
void manage_keyboard(sfEvent *event, player_t *player);

// player movements
void moove_forward(player_t *player);
void moove_backward(player_t *player);
void moove_left(player_t *player);
void moove_right(player_t *player);

#endif /* WOLF_H_ */
