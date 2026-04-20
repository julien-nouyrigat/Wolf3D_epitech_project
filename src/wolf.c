/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** wolf
*/

#include <stdlib.h>
#include "client.h"
#include "server.h"
#include "wolf.h"

static void manage_events(window_t *wolf_win, client_t *client)
{
    input_enum_t input_enum;

    if (wolf_win->event.type == sfEvtClosed)
        sfRenderWindow_close(wolf_win->window);
    if (wolf_win->event.type == sfEvtKeyPressed) {
        if (manage_keyboard(&(wolf_win->event), &input_enum) == true)
            send_input(client, &input_enum);
    }
}

static int render_window(window_t *wolf_win, player_t *player, map_t *map)
{
    sfRenderWindow_clear(wolf_win->window, wolf_win->bg_color);
    // if (wolf_win->is_pseudo) {
    //     display_pseudo(wolf_win);
    //     sfRenderWindow_display(wolf_win->window);
    //     return EXIT_SUCCESS;
    // }
    // if (wolf_win->is_connect) {
    //     display_ip(wolf_win);
    //     sfRenderWindow_display(wolf_win->window);
    //     return EXIT_SUCCESS;
    // }
    draw_2d_map(wolf_win, map);
    for (int i = 0; i < MAXLOG; i++) {
        draw_2d_player(wolf_win, &player[i]);
    }
    sfRenderWindow_display(wolf_win->window);
    return EXIT_SUCCESS;
}

static int manage_windows(window_t *wolf_win)
{
    if (wolf_win->is_pseudo) {
        window_pseudo(wolf_win);
        return EXIT_SUCCESS;
    }
    if (wolf_win->is_connect) {
        window_ip(wolf_win);
        return EXIT_SUCCESS;
    }
    return EXIT_SUCCESS;
}

static int game_loop(window_t *wolf_win, player_t player[], map_t *map,
    client_t *client)
{
    while (sfRenderWindow_isOpen(wolf_win->window)) {
        while (sfRenderWindow_pollEvent(wolf_win->window, &(wolf_win->event))) {
            manage_events(wolf_win, client);
            ///manage_windows(wolf_win);
        }
        recv_states(client, player);
        if (render_window(wolf_win, player, map) == EXIT_FAILURE){
            destroy_assets(wolf_win, player);
            return EXIT_FAILURE;
        }
    }
    return EXIT_SUCCESS;
}

int wolf(client_t *client)
{
    window_t wolf_win = {0};
    player_t *player = NULL;
    map_t *m = NULL;

    wolf_win.is_pseudo = true;
    wolf_win.is_connect = false;
    wolf_win.launch_game = false;
    if (init_player(&player) == EXIT_FAILURE || init_map(&m) == EXIT_FAILURE) {
        destroy_assets(&wolf_win, player);
        return EXIT_FAILURE;
    }
    if (init_window(&wolf_win) == EXIT_FAILURE)
        return EXIT_FAILURE;
    init_udp(client);
    if (game_loop(&wolf_win, player, m, client) == EXIT_FAILURE)
        return EXIT_FAILURE;
    destroy_assets(&wolf_win, player);
    return EXIT_SUCCESS;
}
