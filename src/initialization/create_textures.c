/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** create_textures
*/

#include <stdlib.h>

#include "textures.h"
#include "wolf.h"

int create_textures(window_t *win)
{
    win->textures = malloc(sizeof(sfTexture *) * (TOTAL_TEXTURES));
    if (!win->textures)
        return EXIT_FAILURE;
    for (int i = 0; i < (TOTAL_TEXTURES); i++) {
        win->textures[i] = FILE_TEXT(textures[i].texture);
    }
    return EXIT_SUCCESS;
}
