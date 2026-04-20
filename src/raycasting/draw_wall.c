/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** draw_wall
*/

#include "wolf.h"

void draw_wall(ray_t *ray, window_t *win)
{
    int wall_height = (int)(WIN_HEIGHT / ray->real_dist);
    int draw_start = (WIN_HEIGHT / 2) - (wall_height / 2);
    int draw_end = (WIN_HEIGHT / 2) + (wall_height / 2);
    sfRectangleShape *pixel = sfRectangleShape_create();

    sfRectangleShape_setSize(pixel, (sfVector2f){1, 1});
    if (draw_start < 0)
        draw_start = 0;
    if (draw_end >= WIN_HEIGHT)
        draw_end = WIN_HEIGHT - 1;
    for (int y = draw_start; y <= draw_end; y++) {
        sfRectangleShape_setPosition(pixel, (sfVector2f){ray->screen_x, y});
        if (ray->orientation == VERTICAL)
            sfRectangleShape_setFillColor(pixel, sfColor_fromRGB(0, 128, 255));
        else
            sfRectangleShape_setFillColor(pixel, sfColor_fromRGB(0, 102, 204));
        sfRenderWindow_drawRectangleShape(win->window, pixel, NULL);
    }
}
