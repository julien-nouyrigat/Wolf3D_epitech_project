/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** display_enemies
*/

#include <stdlib.h>
#include <sys/param.h>

#include "wolf.h"

static sfVector2f transform_sprite(monster_t *mob, player_t *player)
{
    sfVector2f relative = (sfVector2f){mob->position.x / TILE_SIZE -
        player->pos_f.x, mob->position.y / TILE_SIZE - player->pos_f.y};
    float inv_det = 1.0f / (player->direction.x * player->camera_plane.y -
        player->camera_plane.x * player->direction.y);
    sfVector2f transformed = {0};

    transformed.x = inv_det * (player->camera_plane.y * relative.x -
        player->camera_plane.x * relative.y);
    transformed.y = inv_det * (- player->direction.y * relative.x +
        player->direction.x * relative.y);
    return transformed;
}

static sprite_proj_t compute_projection(sfVector2f *transform, window_t *win)
{
    sprite_proj_t projection = {0};

    projection.depth = transform->y;
    projection.screen_x = (int)((win->size.x / 2.f) *
        (1.f + transform->x / transform->y));
    projection.height = abs((int)(win->size.y / transform->y));
    projection.width = projection.height;
    projection.start_y = -projection.height / 2 + win->size.y / 2;
    if (projection.start_y < 0)
        projection.start_y = 0;
    projection.end_y = projection.height / 2 + win->size.y / 2;
    if (projection.end_y >= (int)win->size.y)
        projection.end_y = win->size.y - 1;
    projection.start_x = -projection.width / 2 + projection.screen_x;
    if (projection.start_x < 0)
        projection.start_x = 0;
    projection.end_x = projection.width / 2 + projection.screen_x;
    if (projection.end_x >= (int)win->size.x)
        projection.end_x = win->size.x - 1;
    return projection;
}

static sfRenderStates get_mob_state(sfTexture *texture)
{
    sfRenderStates mob_state = {.texture = texture,
        .blendMode = sfBlendAlpha, .transform = sfTransform_Identity,
        .shader = NULL};

    return mob_state;
}

static void draw_sprite_stripe(texture_drawing_t *text_draw,
    sprite_proj_t *proj, sfTexture *texture, window_t *win)
{
    quad_vert_t quad = {0};
    sfVertexArray *array;
    sfRenderStates state = get_mob_state(texture);
    sfVector2u size = sfTexture_getSize(texture);

    quad.top_left = create_vertex(text_draw->stripe, proj->start_y,
        text_draw->text_x, 0);
    quad.top_right = create_vertex(text_draw->stripe + 1, proj->start_y,
        text_draw->text_x + 1, 0);
    quad.bottom_right = create_vertex(text_draw->stripe + 1, proj->end_y,
        text_draw->text_x + 1, size.y);
    quad.bottom_left = create_vertex(text_draw->stripe, proj->end_y,
        text_draw->text_x, size.y);
    array = create_vertex_array(&quad);
    sfRenderWindow_drawVertexArray(win->window, array, &state);
    sfVertexArray_destroy(array);
}

static void draw_sprite(monster_t *mob, player_t *player, window_t *win,
    sfTexture *texture)
{
    sfVector2f transform = transform_sprite(mob, player);
    sprite_proj_t proj = {0};
    sfVector2u tex_size = sfTexture_getSize(texture);
    texture_drawing_t text_draw = {0};

    printf("monsters list ok\n");
    printf("transform x = %f, y = %f\n", transform.x, transform.y);
    if (transform.y <= 0)
        return;
    proj = compute_projection(&transform, win);
    for (int stripe = proj.start_x; stripe < proj.end_x; stripe++) {
        if (transform.y < player->z_buffer[stripe]) {
            text_draw.stripe = stripe;
            text_draw.text_x = (float)(stripe - proj.start_x) * tex_size.x
                / proj.width;
            draw_sprite_stripe(&text_draw, &proj, texture, win);
        }
    }
}

void display_enemies(player_t *player, map_t *map, window_t *win)
{
    enemy_t *tmp = map->level->enemies;

    for (; tmp != NULL; tmp = tmp->next)
        draw_sprite(tmp->monster, player, win,
            map->level->mob_texts[tmp->type]);
}
