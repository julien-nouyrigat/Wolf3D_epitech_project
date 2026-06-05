/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** rotate_right
*/

#include <math.h>

#include "wolf.h"

void rotate(player_t *player, float rot_speed)
{
    float old_dir_x = player->direction.x;
    float old_plane_x = player->camera_plane.x;

    player->direction.x =
        player->direction.x * cos(rot_speed) -
        player->direction.y * sin(rot_speed);
    player->direction.y =
        old_dir_x * sin(rot_speed) +
        player->direction.y * cos(rot_speed);
    player->camera_plane.x =
        player->camera_plane.x * cos(rot_speed) -
        player->camera_plane.y * sin(rot_speed);
    player->camera_plane.y =
        old_plane_x * sin(rot_speed) +
        player->camera_plane.y * cos(rot_speed);
}

void manage_mouse_look(window_t *win, player_t *player)
{
    sfVector2i center = {win->size.x / 2, win->size.y / 2};
    sfVector2i mouse = sfMouse_getPositionRenderWindow(win->window);
    float mov_x = mouse.x - center.x;
    float mov_y = mouse.y - center.y;

    if (player->life <= 0)
        return;
    rotate(player, -mov_x * 0.002f);
    player->y_camera -= mov_y * 6.5f;
    if (player->y_camera > UP_MAX)
        player->y_camera = UP_MAX;
    if (player->y_camera < DOWN_MAX)
        player->y_camera = DOWN_MAX;
    sfMouse_setPositionRenderWindow(center, win->window);
}

void rotate_left(player_t *player, map_t *map,
    __attribute_maybe_unused__ window_t *win)
{
    float old_dir_x = player->direction.x;
    float old_plane_x = player->camera_plane.x;

    if (player->life == 0)
        return;
    (void)map;
    player->direction.x = player->direction.x * cos(ROTATION_SPEED) -
        player->direction.y * sin(ROTATION_SPEED);
    player->direction.y = old_dir_x * sin(ROTATION_SPEED) +
        player->direction.y * cos(ROTATION_SPEED);
    player->camera_plane.x = player->camera_plane.x * cos(ROTATION_SPEED) -
        player->camera_plane.y * sin(ROTATION_SPEED);
    player->camera_plane.y = old_plane_x * sin(ROTATION_SPEED) +
        player->camera_plane.y * cos(ROTATION_SPEED);
}

void rotate_right(player_t *player, map_t *map,
    __attribute_maybe_unused__ window_t *win)
{
    float old_dir_x = player->direction.x;
    float old_plane_x = player->camera_plane.x;

    if (player->life == 0)
        return;
    (void)map;
    player->direction.x = player->direction.x * cos(- ROTATION_SPEED) -
        player->direction.y * sin(- ROTATION_SPEED);
    player->direction.y = old_dir_x * sin(- ROTATION_SPEED) +
        player->direction.y * cos(- ROTATION_SPEED);
    player->camera_plane.x = player->camera_plane.x * cos(- ROTATION_SPEED) -
        player->camera_plane.y * sin(- ROTATION_SPEED);
    player->camera_plane.y = old_plane_x * sin(- ROTATION_SPEED) +
        player->camera_plane.y * cos(- ROTATION_SPEED);
}

void up_cam(player_t *player, map_t *map,
    __attribute_maybe_unused__ window_t *win)
{
    if (player->life == 0)
        return;
    (void)map;
    player->y_camera += UP_DOWN_MVT;
    if (player->y_camera > UP_MAX)
        player->y_camera = UP_MAX;
}

void down_cam(player_t *player, map_t *map,
    __attribute_maybe_unused__ window_t *win)
{
    if (player->life == 0)
        return;
    (void)map;
    player->y_camera -= UP_DOWN_MVT;
    if (player->y_camera < DOWN_MAX)
        player->y_camera = DOWN_MAX;
}
