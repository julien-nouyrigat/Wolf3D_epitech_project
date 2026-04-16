/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** wolf
*/

#include <stdlib.h>

#include "wolf.h"

static void manage_events(window_t *wolf_win, player_t *player)
{
    if (wolf_win->event.type == sfEvtClosed)
        sfRenderWindow_close(wolf_win->window);
    if (wolf_win->event.type == sfEvtKeyPressed) {
        manage_keyboard(&(wolf_win->event), player);
    }
}

static int render_window(window_t *wolf_win, player_t *player, map_t *map)
{
    sfRenderWindow_clear(wolf_win->window, wolf_win->bg_color);
    draw_2d_map(wolf_win, map);
    draw_2d_player(wolf_win, player);
    sfRenderWindow_display(wolf_win->window);
    return EXIT_SUCCESS;
}

static int game_loop(window_t *wolf_win, player_t *player, map_t *map)
{
    while (sfRenderWindow_isOpen(wolf_win->window)) {
        while (sfRenderWindow_pollEvent(wolf_win->window, &(wolf_win->event)))
            manage_events(wolf_win, player);
        if (render_window(wolf_win, player, map) == EXIT_FAILURE){
            destroy_assets(wolf_win, player);
            return EXIT_FAILURE;
        }
    }
    return EXIT_SUCCESS;
}

int wolf(void)
{
    window_t *wolf_win = malloc(sizeof(window_t));
    player_t *player = NULL;
    map_t *map = NULL;

    if (!wolf_win)
        return EXIT_FAILURE;
    if (init_player(&player) == EXIT_FAILURE) {
        destroy_assets(wolf_win, player);
        return EXIT_FAILURE;
    }
    if (init_map(&map) == EXIT_FAILURE) {
        destroy_assets(wolf_win, player);
        return EXIT_FAILURE;
    }
    if (init_window(wolf_win) == EXIT_FAILURE)
        return EXIT_FAILURE;
    if (game_loop(wolf_win, player, map) == EXIT_FAILURE)
        return EXIT_FAILURE;
    destroy_assets(wolf_win, player);
    return EXIT_SUCCESS;
}
