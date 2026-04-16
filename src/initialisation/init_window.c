/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** init_window
*/

#include "wolf.h"

int init_window(window_t *wolf_win)
{
    sfVideoMode mode = {WIN_WIDTH, WIN_HEIGHT, WIN_BPP};

    wolf_win->window = sfRenderWindow_create(mode, "Wolf3D",
        sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(wolf_win->window, FRAMES_LIMIT);
    if (!wolf_win->window)
        return EXIT_FAILURE;
    wolf_win->bg_color = sfColor_fromRGB(96, 96, 96);
    return EXIT_SUCCESS;
}
