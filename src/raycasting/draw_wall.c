/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** draw_wall
*/

#include <math.h>

#include "decors.h"
#include "wolf.h"

// static float find_wall_x(ray_t *ray)
// {
//     float wall_x = ray->orientation == VERTICAL ?
//         ray->screen_x + ray->real_dist * ray->direction.x :
//         ray->screen_x + ray->real_dist * ray->direction.y;

//     wall_x -= floor(wall_x);
//     return wall_x;
// }

// void draw_wall(ray_t *ray, window_t *win, map_t *map, player_t *player)
// {
//     int wall_height = (int)(win->size.y / ray->real_dist);
//     int draw_start = (win->size.y / 2) - (wall_height / 2);
//     int draw_end = (win->size.y / 2) + (wall_height / 2);
//     float wall_x = find_wall_x(ray);
//     sfVector2u text_size = sfTexture_getSize
//         (win->decors[(map->type * TEXT_TYPES + WALL) - TEXT_TYPES]);
//     float text_x = wall_x * text_size.x;
//     sfVertexArray *wall_line = sfVertexArray_create();
//     sfVertex bottom = {.position = {ray->screen_x, draw_start},
//         .texCoords = {text_x, 0.0}};
//     sfVertex top = {.position = {ray->screen_x, draw_end},
//         .texCoords = (sfVector2f){text_size.x, text_size.y}};

//     sfVertexArray_append(wall_line, bottom);
//     sfVertexArray_append(wall_line, top);
//     sfVertexArray_setPrimitiveType(wall_line, sfLines);
//     sfRenderWindow_drawVertexArray(win->window, wall_line, &wall);
//     sfVertexArray_destroy(wall_line);
// }



static float find_wall_x(ray_t *ray, player_t *player)
{
    float wall_x = ray->orientation == VERTICAL ?
        player->pos_f.y + ray->real_dist * ray->direction.y :
        player->pos_f.x + ray->real_dist * ray->direction.x;

    wall_x -= floor(wall_x);
    return wall_x;
}

void draw_wall(ray_t *ray, window_t *win, map_t *map, player_t *player)
{
    int wall_height = (int)(win->size.y / ray->real_dist);
    float wall_x = find_wall_x(ray, player);
    int draw_start = (win->size.y / 2) - (wall_height / 2);
    int draw_end = (win->size.y / 2) + (wall_height / 2);
    sfVector2u decor_size = sfImage_getSize
        (win->decors[(map->type * DECOR_TYPES + WALL) - DECOR_TYPES]);
    sfVector2i text_coord = (sfVector2i){0, 0};
    float step = 1.0 * decor_size.y / wall_height;
    float text_pos = (draw_start - win->size.y / 2 + wall_height / 2) * step;

    text_coord.x = (int)(wall_x * decor_size.x);
    if ((ray->orientation == VERTICAL && ray->direction.x > 0) ||
        (ray->orientation == HORIZONTAL && ray->direction.y < 0))
        text_coord.x = decor_size.x - text_coord.x - 1;
    for (int i = draw_start; i < draw_end; i++) {
        text_coord.y = (int)text_pos & (decor_size.y - 1);
        text_pos += step;
        ray->color = sfRed;
    }
}
