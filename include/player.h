/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** player
*/

#ifndef PLAYER_H_
    #define PLAYER_H_

    #include <stdbool.h>
    #include <math.h>

    #include "window.h"

    #define PLAYER_SIZE 15
    #define BOBING_COEF 0.3f
    #define ZERO_INV 1e30
    #define VERTICAL true
    #define HORIZONTAL false
    #define ROTATION_SPEED (M_PI / 50)
    #define LIFE_START 100
    #define STAM_START 40
    #define SPRINT 5
    #define FOV 0.66
    #define LIFE_LEN 7
    #define STAM_LEN 7
    #define LIGHT 255
    #define SHADOW 160
    #define FOG 0.4
    #define MOVEMENT_SPEED 4

typedef struct {
    float x0;
    float y0;
    float x1;
    float y1;
    int pos;
    float pos_z;
    float row_dist;
    float step_x;
    float step_y;
    float floor_x;
    float floor_y;
} floor_ray_t;

typedef struct {
    sfVertex top_left;
    sfVertex top_right;
    sfVertex bottom_right;
    sfVertex bottom_left;
} quad_vert_t;

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
    size_t life;
    size_t max_life;
    size_t stamina;
    size_t max_stamina;
    bool sprint;
    bool is_moving;
    float y_camera;
    sfClock *p_clock;
    float bobing;
} player_t;

#endif /* PLAYER_H_ */
