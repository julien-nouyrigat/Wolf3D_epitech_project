/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** player
*/

#ifndef PLAYER_H_
    #define PLAYER_H_

    #include <stdbool.h>

    #include "window.h"

    #define PLAYER_SIZE 15
    #define ZERO_INV 1e30
    #define VERTICAL true
    #define HORIZONTAL false
    #define ROTATION_SPEED (M_PI / 50)

typedef struct {
    size_t screen_x;
    sfVector2f direction;
    sfVector2f side_dist;
    sfVector2f delta_dist;
    sfVector2i step;
    float real_dist;
    bool orientation;
    sfColor color;
} ray_t;

typedef struct {
    sfVector2f position;
    sfVector2f pos_f;
    sfVector2f direction;
    sfVector2f camera_plane;
    sfVector2f camera;
    sfRectangleShape *hitbox;
    float delta_x;
    float delta_y;
    int mvt_speed;
} player_t;

#endif /* PLAYER_H_ */
