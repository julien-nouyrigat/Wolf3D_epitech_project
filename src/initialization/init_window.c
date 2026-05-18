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
    wolf_win->size = sfRenderWindow_getSize(wolf_win->window);
    wolf_win->bg_color = sfBlack;
    wolf_win->clock.clock = sfClock_create();
    wolf_win->clock.elapsed_time_bg = 0.0f;
    wolf_win->font = sfFont_createFromFile("./assets/fonts/teko.ttf");
    init_brackground_menu(wolf_win);
    init_menu(wolf_win);
    init_lamp(wolf_win);
    if (create_textures(wolf_win) == EXIT_FAILURE)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}
