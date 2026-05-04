/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** draw_floor
*/

#include "textures.h"
#include "wolf.h"

floor_ray_t init_floor_ray(ray_t *ray, window_t *win, player_t *player,
    size_t screen_y)
{
    floor_ray_t f_ray = {0};

    f_ray.x0 = ray->direction.x - player->camera_plane.x;
    f_ray.y0 = ray->direction.y - player->camera_plane.y;
    f_ray.x1 = ray->direction.x + player->camera_plane.x;
    f_ray.y1 = ray->direction.y + player->camera_plane.y;
    f_ray.pos = screen_y - win->size.y / 2;
    f_ray.pos_z = win->size.y / 2;
    f_ray.row_dist = f_ray.pos_z / 2;
    f_ray.step_x = f_ray.row_dist * (f_ray.x1 - f_ray.x0) / win->size.x;
    f_ray.step_y = f_ray.row_dist * (f_ray.y1 - f_ray.y0) / win->size.x;
    f_ray.floor_x = player->pos_f.x + f_ray.row_dist * f_ray.x0;
    f_ray.floor_y = player->pos_f.y + f_ray.row_dist * f_ray.y0;
    return f_ray;
}

void draw_floor(ray_t *ray, window_t *win, map_t *map, player_t *player)
{
    floor_ray_t f_ray = {0};
    sfVector2i cell = {0};
    sfVector2i text = {0};
    sfVector2u t_size = sfTexture_getSize
        (win->textures[(map->type * TEXT_TYPES + FLOOR) - TEXT_TYPES - 1]);

    for (size_t i = 0; i < win->size.y; i++) {
        f_ray = init_floor_ray(ray, win, player, i);
        for (size_t j = 0; j < win->size.x; j++) {
            cell.x = (int)f_ray.floor_x;
            cell.y = (int)f_ray.floor_y;
            text.x =
                (int)(win->size.x * (f_ray.floor_x - cell.x)) & (t_size.x - 1);
            text.y =
                (int)(win->size.y * (f_ray.floor_y - cell.y)) & (t_size.y - 1);
        }
    }
}
