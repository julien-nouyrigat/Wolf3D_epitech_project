/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** display_enemies
*/

#include <stdlib.h>
#include <sys/param.h>
#include <math.h>

#include "entity_display.h"
#include "wolf.h"

static sfVector2f transform_position(player_t *player, sfVector2f *sprite_pos)
{
    float inv_det = 1.0f / (player->camera_plane.x * player->direction.y -
        player->direction.x * player->camera_plane.y);
    float x = inv_det * (player->direction.y * sprite_pos->x -
        player->direction.x * sprite_pos->y);
    float y = inv_det * (-player->camera_plane.y * sprite_pos->x +
        player->camera_plane.x * sprite_pos->y);
    sfVector2f transform = (sfVector2f){x, y};

    return transform;
}

static sprite_proj_t compute_projection(sfVector2f *transform, window_t *win,
    player_t *player)
{
    sprite_proj_t proj = {0};
    int center = win->size.y / 2 + (int)player->y_camera / 2 +
        (int)(sin(player->bobing) * 10) / 2;

    proj.screen_x = (int)((win->size.x / 2) *
        (1 + transform->x / transform->y));
    proj.height = abs((int)(win->size.y / (transform->y / TILE_SIZE)));
    proj.end_y = center + proj.height / 2;
    proj.start_y = proj.end_y - proj.height;
    proj.width = abs((int)(win->size.y / (transform->y / TILE_SIZE)));
    proj.start_x = proj.screen_x - proj.width / 2;
    proj.end_x = proj.screen_x + proj.width / 2;
    return proj;
}

static sfRenderStates get_mob_state(sfTexture *texture)
{
    sfRenderStates mob_state = {.texture = texture,
        .blendMode = sfBlendAlpha, .transform = sfTransform_Identity,
        .shader = NULL};

    return mob_state;
}

static void apply_shadows(quad_vert_t *quad_vert, sprite_proj_t *proj)
{
    float fog = LIGHT / (1 + (proj->dist / FOG_COEF) * FOG);

    quad_vert->top_left.color = sfColor_fromRGB(fog, fog, fog);
    quad_vert->top_right.color = sfColor_fromRGB(fog, fog, fog);
    quad_vert->bottom_right.color = sfColor_fromRGB(fog, fog, fog);
    quad_vert->bottom_left.color = sfColor_fromRGB(fog, fog, fog);
}

static void draw_vertex_array(sprite_proj_t *proj, int stripe,
    window_t *win)
{
    quad_vert_t quad = {0};
    sfVertexArray *array;
    sfRenderStates state = get_mob_state(proj->entity_text);
    sfVector2u size = sfTexture_getSize(proj->entity_text);
    int tex_x = (int)((float)(stripe - proj->start_x) /
        (float)(proj->width) * size.x);

    quad.top_left = create_vertex(stripe, proj->start_y, tex_x, 0);
    quad.top_right = create_vertex(stripe + 1, proj->start_y, tex_x + 1, 0);
    quad.bottom_right = create_vertex(stripe + 1, proj->end_y, tex_x + 1,
        size.y);
    quad.bottom_left = create_vertex(stripe, proj->end_y, tex_x, size.y);
    apply_shadows(&quad, proj);
    array = create_vertex_array(&quad);
    sfRenderWindow_drawVertexArray(win->window, array, &state);
    sfVertexArray_destroy(array);
}

static void select_sprite_stripe(sprite_proj_t *proj, sfVector2f *transform,
    window_t *win, player_t *player)
{
    for (int stripe = proj->start_x; stripe < proj->end_x; stripe++) {
        if (transform->y > 0 && stripe > 0 && stripe < (int)win->size.x &&
            transform->y / TILE_SIZE < player->z_buffer[stripe])
            draw_vertex_array(proj, stripe, win);
    }
}

static void get_sprite_3d_proj(entities_t *entity, player_t *player,
    window_t *win)
{
    sfVector2f sprite_pos = (sfVector2f){entity->position.x -
        player->position.x, entity->position.y - player->position.y};
    sfVector2f transform = transform_position(player, &sprite_pos);
    sprite_proj_t proj = compute_projection(&transform, win, player);

    if (transform.y / TILE_SIZE < 0.1f)
        return;
    proj.entity_text = entity->text;
    proj.dist = entity->p_dist;
    select_sprite_stripe(&proj, &transform, win, player);
}

static void display_entities(player_t *player, window_t *win, entities_t *head)
{
    entities_t *tmp = head;

    for (; tmp != NULL; tmp = tmp->next) {
        get_sprite_3d_proj(tmp, player, win);
    }
}

static int add_monster_entity(enemy_t *mob, entities_t **head,
    player_t *player, map_t *map)
{
    entities_t *new = NULL;

    if (mob->monster->health <= 0)
        return EXIT_SUCCESS;
    new = calloc(sizeof(entities_t), 1);
    if (new == NULL)
        return EXIT_FAILURE;
    new->position = mob->monster->position;
    new->direction = mob->monster->direction;
    new->text = map->level->mob_texts[mob->type];
    new->p_dist = sqrt(
        pow(player->pos_f.x - mob->monster->position.x / TILE_SIZE, 2) +
        pow(player->pos_f.y - mob->monster->position.y / TILE_SIZE, 2));
    new->next = *head;
    *head = new;
    return EXIT_SUCCESS;
}

int create_entity_list(player_t *player, map_t *map, window_t *win)
{
    entities_t *head = NULL;
    enemy_t *mob_tmp = map->level->enemies;

    for (size_t i = 0; i < MAX_CLIENTS; i++) {
        if (!win->client)
            continue;
        add_player_entity(&head, player, win, i);
    }
    for (; mob_tmp != NULL; mob_tmp = mob_tmp->next) {
        if (add_monster_entity(mob_tmp, &head, player, map) == EXIT_FAILURE)
            return EXIT_FAILURE;
    }
    head = sort_entities(head);
    display_entities(player, win, head);
    free_entities(head);
    return EXIT_SUCCESS;
}
