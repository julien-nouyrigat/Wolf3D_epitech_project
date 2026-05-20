/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** display_enemies
*/

#include <stdlib.h>
#include <sys/param.h>

#include "wolf.h"

static sfVector2f transform_position(monster_t *mob, player_t *player)
{
    sfVector2f sprite_pos = (sfVector2f){mob->position.x - player->position.x,
        mob->position.y - player->position.y};
    float inv_det = 1.f / (player->camera_plane.x * player->direction.y -
        player->camera_plane.y * player->direction.x);
    float x = inv_det * (player->direction.y *
        sprite_pos.x - player->direction.x * sprite_pos.y);
    float y = inv_det * (-player->camera_plane.y *
        sprite_pos.x + player->camera_plane.x * sprite_pos.y);
    sfVector2f transformed = (sfVector2f){x, y};

    return transformed;
}

static quad_vert_t find_quad_vertex(monster_t *mob, window_t *win,
    player_t *player, sfTexture *text)
{
    quad_vert_t quad_vert = {0};
    sfVector2f transformed = transform_position(mob, player);
    int screen_x = win->size.x / 2 * (1 + transformed.x / transformed.y);
    int sprite_size = fabs(win->size.x / transformed.y);
    int draw_start = MAX(screen_x - sprite_size / 2, 0);
    int draw_end = MIN(screen_x + sprite_size / 2, (int)win->size.y - 1);
    sfVector2u size = sfTexture_getSize(text);
    float text_x = screen_x * size.x;

    for (int i = draw_start; i < draw_end; i++) {
        if (transformed.y > 0) {
            quad_vert.top_left = create_vertex((float)i, draw_start, text_x, size.y);
            quad_vert.top_right =
                create_vertex((float)i + 1.0, draw_start, text_x + 1.0, size.y);
            quad_vert.bottom_right = create_vertex((float)i + 1.0, draw_end,
                text_x + 1.0, 0.f);
            quad_vert.bottom_left =
                create_vertex((float)i, draw_end, text_x, 0.f);
            // apply_shadows(&quad_vert, ray);
        }
    }
    return quad_vert;
}

static void draw_enemy(monster_t *mob, player_t *player, window_t *win)
{
    sfVertexArray *mob_line = sfVertexArray_create();
    sfVector2f transformed = transform_position(mob, player);
    int screen_x = win->size.x / 2 * (1 + transformed.x / transformed.y);
    int sprite_size = fabs(win->size.x / transformed.y);
    int draw_start = MAX(screen_x - sprite_size / 2, 0);
    int draw_end = MIN(screen_x + sprite_size / 2, (int)win->size.y - 1);

    sfVertexArray_setPrimitiveType(mob_line, sfLines);
    for (int i = draw_start; i < draw_end; i++) {
        if (transformed.y > 0) {
            sfVertexArray_append(mob_line, (sfVertex)
                {.position = {(float)i, win->size.y / 2.f -
                        sprite_size / 2.f}, sfWhite});
            sfVertexArray_append(mob_line, (sfVertex)
                {.position = {(float)i, win->size.y / 2.f +
                        sprite_size / 2.f}, sfWhite});
        }
    }
    sfRenderWindow_drawVertexArray(win->window, mob_line, NULL);
    sfVertexArray_destroy(mob_line);
}

static sfRenderStates get_mob_state(sfTexture *texture)
{
    sfRenderStates mob_state = {.texture = texture,
        .blendMode = sfBlendAlpha, .transform = sfTransform_Identity,
        .shader = NULL};

    return mob_state;
}

static void draw_mob(monster_t *mob, player_t *player, window_t *win,
    sfTexture *text)
{
    quad_vert_t quad_vert = find_quad_vertex(mob, win, player, text);
    sfRenderStates mob_state = get_mob_state(text);
    sfVertexArray *mob_line = create_vertex_array(&quad_vert);

    sfRenderWindow_drawVertexArray(win->window, mob_line, &mob_state);
    sfVertexArray_destroy(mob_line);
}

void display_enemies(player_t *player, map_t *map, window_t *win)
{
    enemy_t *tmp = map->level->enemies;

    for (; tmp != NULL; tmp = tmp->next)
        draw_mob(tmp->monster, player, win, map->level->mob_texts[tmp->type]);
}
