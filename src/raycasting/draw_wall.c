/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** draw_wall
*/

#include "wolf.h"

void draw_wall(ray_t *ray, window_t *win)
{
    int wall_height = (int)(win->size.y / ray->real_dist);
    int draw_start = (win->size.y / 2) - (wall_height / 2);
    int draw_end = (win->size.y / 2) + (wall_height / 2);
    sfVertexArray *wall_line = sfVertexArray_create();
    sfVertex bottom = {.position = {ray->screen_x, draw_start},
        .color = ray->color};
    sfVertex top = {.position = {ray->screen_x, draw_end}, .color = ray->color};

    sfVertexArray_append(wall_line, bottom);
    sfVertexArray_append(wall_line, top);
    sfVertexArray_setPrimitiveType(wall_line, sfLines);
    sfRenderWindow_drawVertexArray(win->window, wall_line, NULL);
    sfVertexArray_destroy(wall_line);
}
