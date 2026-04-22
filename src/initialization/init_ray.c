/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** init_ray
*/

#include "wolf.h"

void init_ray(ray_t *ray)
{
    ray->angle = 0;
    ray->x_len = 0;
    ray->y_len = 0;
    ray->x_step = 0;
    ray->y_step = 0;
    ray->x_dist = 0;
    ray->y_dist = 0;
    ray->wall_face = VERTICAL;
    ray->dist = 0;
}
