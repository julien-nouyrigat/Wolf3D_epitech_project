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
    win->weapons_texts = malloc(sizeof(sfTexture *) * (NB_WEAPONS));
    if (!win->weapons_texts)
        return EXIT_FAILURE;
    win->icons_texts = malloc(sizeof(sfTexture *) * (NB_WEAPONS));
    if (!win->icons_texts)
        return EXIT_FAILURE;
    for (int i = 0; i < (TOTAL_TEXTURES); i++) {
        win->textures[i] = FILE_TEXT(textures[i].texture);
    }
    for (int i = 0; i < (NB_WEAPONS); i++) {
        win->weapons_texts[i] = FILE_TEXT(weapons_textures[i].texture);
    }
    for (int i = 0; i < (NB_WEAPONS); i++) {
        win->icons_texts[i] = FILE_TEXT(weapons_icons[i].texture);
    }
    return EXIT_SUCCESS;
}
