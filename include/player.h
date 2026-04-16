/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** player
*/

#ifndef PLAYER_H_
    #define PLAYER_H_

    #include "window.h"

    #define OFFSET 0.0001
    #define PLAYER_SIZE 15

typedef struct {
    float angle;
    float x_len;
    float y_len;
    int x_step;
    int y_step;
    float x_dist;
    float y_dist;
} ray_t;

typedef struct {
    int pos_x;
    int pos_y;
    float angle;
    sfRectangleShape *hitbox;
    float delta_x;
    float delta_y;
} player_t;

#endif /* PLAYER_H_ */
