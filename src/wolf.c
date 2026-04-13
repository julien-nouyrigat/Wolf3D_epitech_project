/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** wolf
*/

#include <stdlib.h>

#include "wolf.h"


static void manage_events(window_t *wolf_win)
{
    if (wolf_win->event.type == sfEvtClosed)
        sfRenderWindow_close(wolf_win->window);
}

static int render_window(window_t *wolf_win)
{
    sfRenderWindow_clear(wolf_win->window, sfBlack);
    sfRenderWindow_display(wolf_win->window);
    return EXIT_SUCCESS;
}

int wolf(void)
{
    window_t *wolf_win = malloc(sizeof(window_t));
    sfVideoMode mode = {1920, 1080, 32};

    if (!wolf_win)
        return EXIT_FAILURE;
    wolf_win->window = sfRenderWindow_create(mode, "Wolf3D",
        sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(wolf_win->window, FRAMES_LIMIT);
    if (!wolf_win->window)
        return EXIT_FAILURE;
    while (sfRenderWindow_isOpen(wolf_win->window)){
        while (sfRenderWindow_pollEvent(wolf_win->window, &(wolf_win->event)))
            manage_events(wolf_win);
        if (render_window(wolf_win) == EXIT_FAILURE){
            destroy_assets(wolf_win);
            return EXIT_FAILURE;
        }
    }
    destroy_assets(wolf_win);
    return EXIT_SUCCESS;
}
