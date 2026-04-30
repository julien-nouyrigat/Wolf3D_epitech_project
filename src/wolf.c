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

static void manage_events(window_t *win, player_t *player, map_t *map,
    sfVector2i *mp)
{
    for (size_t i = 0; events[i].type != END; i++) {
        if (win->event.type == events[i].type)
            events[i].function(win, player, map);
    }
    if (win->event.type == sfEvtMouseButtonPressed) {
        if (sfFloatRect_contains(&win->menu.tab[4].bound, mp->x, mp->y))
            close_window(win, player, map);
        if (sfFloatRect_contains(&win->menu.tab[2].bound, mp->x, mp->y)) {
            win->is_menu = false;
            win->is_single = true;
        }
        if (sfFloatRect_contains(&win->menu.tab[0].bound, mp->x, mp->y)) {
            win->is_menu = false;
            win->is_host_game = true;
        }
    }
}

static void manage_window(window_t *win, player_t *player, map_t *map)
{
    if (win->is_menu == true)
        display_menu(win);
    if (win->is_single == true) {
        dda_algorithm(player, map, win);
    }
    if (win->is_host_game == true) {
        display_host(win);
    }
    if (win->is_lobby == true) {
        display_lobby(win);
    }
}

static int render_window(window_t *win, player_t *player, map_t *map)
{
    manage_keyboard(player, map);
    sfRenderWindow_clear(win->window, win->bg_color);
    win->clock.time = sfClock_restart(win->clock.clock);
    win->clock.elapsed_time_bg += win->clock.time.microseconds /
        1000000.0;
    manage_window(win, player, map);
    sfRenderWindow_display(win->window);
    return EXIT_SUCCESS;
}

static int game_loop(window_t *wolf_win, player_t *player, map_t *map)
{
    sfVector2i mouse_pos;

    while (sfRenderWindow_isOpen(wolf_win->window)) {
        recv_rooms(wolf_win->client);
        mouse_pos = sfMouse_getPositionRenderWindow(wolf_win->window);
        while (sfRenderWindow_pollEvent(wolf_win->window, &(wolf_win->event)))
            manage_events(wolf_win, player, map, &mouse_pos);
        if (render_window(wolf_win, player, map) == EXIT_FAILURE){
            destroy_assets(wolf_win, player);
            return EXIT_FAILURE;
        }
    }
    return EXIT_SUCCESS;
}

static int check_init(window_t *wolf_win, player_t **player, map_t **map)
{
    if (init_player(player) == EXIT_FAILURE) {
        destroy_assets(wolf_win, *player);
        return EXIT_FAILURE;
    }
    if (init_map(map) == EXIT_FAILURE) {
        destroy_assets(wolf_win, *player);
        return EXIT_FAILURE;
    }
    if (init_window(wolf_win) == EXIT_FAILURE)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

int wolf(char *ip)
{
    window_t *wolf_win = malloc(sizeof(window_t));
    player_t *player = NULL;
    map_t *map = NULL;

    if (!wolf_win)
        return EXIT_FAILURE;
    wolf_win->client = malloc(sizeof(client_info_t));
    wolf_win->client->sock_tcp = -1;
    wolf_win->client->rooms = NULL;
    if (connect_to_server(wolf_win->client, ip) == EXIT_FAILURE)
        return EXIT_FAILURE;
    if (check_init(wolf_win, &player, &map) == EXIT_FAILURE)
        return EXIT_FAILURE;
    if (game_loop(wolf_win, player, map) == EXIT_FAILURE)
        return EXIT_FAILURE;
    destroy_assets(wolf_win, player);
    return EXIT_SUCCESS;
}
