/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** wolf
*/

#include <stdlib.h>

#include "wolf.h"

const struct evt_pfs_s events[] = {
    {sfEvtClosed, &close_window},
    {sfEvtResized, &resize_window},
    {END, NULL}
};

static void manage_events(window_t *win, player_t *player, map_t *map)
{
    for (size_t i = 0; events[i].type != END; i++) {
        if (win->event.type == events[i].type)
            events[i].function(win, player, map);
    }
}

static int render_window(window_t *win, player_t *player, map_t *map)
{
    sfRenderWindow_clear(win->window, win->bg_color);
    manage_keyboard(player, map);
    dda_algorithm(player, map, win);
    draw_2d_map(win, map);
    draw_2d_player(win, player);
    sfRenderWindow_display(win->window);
    return EXIT_SUCCESS;
}

static int game_loop(window_t *wolf_win, player_t *player, map_t *map)
{
    while (sfRenderWindow_isOpen(wolf_win->window)) {
        while (sfRenderWindow_pollEvent(wolf_win->window, &(wolf_win->event)))
            manage_events(wolf_win, player, map);
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
