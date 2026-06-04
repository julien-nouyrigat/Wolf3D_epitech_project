/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** entity_display
*/

#ifndef ENTITY_DISPLAY_H_
    #define ENTITY_DISPLAY_H_

    #include "wolf.h"

typedef struct entities_s {
    sfVector2f position;
    sfVector2f direction;
    sfTexture *text;
    float p_dist;
    sfFloatRect *hitbox;
    struct entities_s *next;
} entities_t;

#endif /* ENTITY_DISPLAY_H_ */
