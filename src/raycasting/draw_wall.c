/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** draw_wall
*/

#include <math.h>

#include "textures.h"
#include "wolf.h"

static float find_wall_x(ray_t *ray, player_t *player)
{
    float wall_x = ray->orientation == VERTICAL ?
        player->pos_f.y + ray->real_dist * ray->direction.y :
        player->pos_f.x + ray->real_dist * ray->direction.x;

    wall_x -= floor(wall_x);
    return wall_x;
}

static sfVertex create_vertex(float pos_x, float pos_y, float text_x,
    float text_y)
{
    sfVertex vertex = {.position = (sfVector2f){pos_x, pos_y},
        .color = sfWhite, .texCoords = (sfVector2f){text_x, text_y}};

    return vertex;
}

static sfRenderStates get_wall_state(window_t *win, map_t *map)
{
    sfRenderStates wall_state = {.texture =
            win->textures[(map->type * TEXT_TYPES + WALL) - TEXT_TYPES - 1],
        .blendMode = sfBlendAlpha, .transform = sfTransform_Identity,
        .shader = NULL};

    return wall_state;
}

static sfVertexArray *create_wall_array(sfVertex *top_left,
    sfVertex *top_right, sfVertex *bottom_right,
    sfVertex *bottom_left)
{
    sfVertexArray *wall_line = sfVertexArray_create();

    sfVertexArray_setPrimitiveType(wall_line, sfQuads);
    sfVertexArray_append(wall_line, *top_left);
    sfVertexArray_append(wall_line, *top_right);
    sfVertexArray_append(wall_line, *bottom_right);
    sfVertexArray_append(wall_line, *bottom_left);
    return wall_line;
}

void draw_wall(ray_t *ray, window_t *win, map_t *map, player_t *player)
{
    int wall_height = (int)(win->size.y / ray->real_dist);
    int wall_bottom = (win->size.y / 2) - (wall_height / 2);
    int wall_top = (win->size.y / 2) + (wall_height / 2);
    float wall_x = find_wall_x(ray, player);
    sfVector2u size = sfTexture_getSize
        (win->textures[(map->type * TEXT_TYPES + WALL) - TEXT_TYPES - 1]);
    float text_x = wall_x * size.x;
    sfVertex top_left = create_vertex(ray->screen_x, wall_top, text_x, size.y);
    sfVertex top_right =
        create_vertex(ray->screen_x + 1.0, wall_top, text_x + 1.0, size.y);
    sfVertex bottom_right = create_vertex(ray->screen_x + 1.0, wall_bottom,
        text_x + 1.0, 0.f);
    sfVertex bottom_left =
        create_vertex(ray->screen_x, wall_bottom, text_x, 0.f);
    sfRenderStates wall_state = get_wall_state(win, map);
    sfVertexArray *wall_line = create_wall_array(&top_left, &top_right,
        &bottom_left, &bottom_right);

    sfRenderWindow_drawVertexArray(win->window, wall_line, &wall_state);
    sfVertexArray_destroy(wall_line);
}
