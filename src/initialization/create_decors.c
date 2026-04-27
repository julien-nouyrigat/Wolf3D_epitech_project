/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** create_decors
*/

#include <stdlib.h>

#include "decors.h"
#include "wolf.h"

int create_decors(window_t *win)
{
    win->decors = malloc(sizeof(sfImage *) * (END_DECORS - DECOR_TYPES));
    if (!win->decors)
        return EXIT_FAILURE;
    for (int i = 0; i < (END_DECORS - DECOR_TYPES); i++) {
        win->decors[i] = FILE_IMG(decors[i].decor);
    }
    return EXIT_SUCCESS;
}
