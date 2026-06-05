/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** wolf
*/

#include <stdlib.h>
#include "network.h"
#include "wolf.h"

const struct evt_pfs_s events[] = {
    {sfEvtClosed, &close_window},
    {sfEvtResized, &resize_window},
    {sfEvtKeyReleased, &stop_sprint},
    {END, NULL}
};

void check_other_events(window_t *win, sfVector2i *mp, player_t *player)
{
    if (win->event.type == sfEvtMouseButtonPressed && win->is_clickable) {
        if (sfFloatRect_contains(&win->menu.tab[2].bound, mp->x, mp->y)) {
            win->is_menu = false;
            win->is_single = true;
        }
        if (sfFloatRect_contains(&win->menu.tab[1].bound, mp->x, mp->y)) {
            connect_client(win, player);
            win->is_menu = false;
            win->is_lobby = true;
        }
    }
    if (win->event.type == sfEvtMouseButtonPressed && win->is_clickable) {
        if (sfFloatRect_contains(&win->menu.tab[3].bound, mp->x, mp->y)) {
            win->is_clickable = false;
            win->is_param = true;
        }
    }
}

static void manage_events(window_t *win, player_t *player, map_t *map,
    sfVector2i *mp)
{
    for (size_t i = 0; events[i].type != END; i++) {
        if (win->event.type == events[i].type)
            events[i].function(win, player, map);
    }
    if (win->is_game || win->is_single)
        manage_game_mouse(win, player, map);
    if (win->event.type == sfEvtMouseButtonPressed && win->is_clickable)
        if (sfFloatRect_contains(&win->menu.tab[4].bound, mp->x, mp->y))
            close_window(win, player, map);
    check_other_events(win, mp, player);
}

static void display_other_elements(window_t *win, player_t *player,
    map_t __attribute_maybe_unused__ *map)
{
    if (win->is_lamp)
        display_lamp(win, player);
    if (player->life != 0){
        display_hand_inv(win, player);
        draw_hand(win, player);
    }
}

static int display_game_elements(window_t *win, player_t *player, map_t *map)
{
    manage_mouse_look(win, player);
    manage_enemies(win, player, map);
    enemy_attack(player, map, win);
    if (!win->ambiance_started) {
        sfMusic_play(win->ambiance);
        sfMusic_setLoop(win->ambiance, sfTrue);
        win->ambiance_started = true;
    }
    if (dda_algorithm(player, map, win) == EXIT_FAILURE)
        return EXIT_FAILURE;
    if (player->is_in_inv)
        display_inventory(win, player);
    display_other_elements(win, player, map);
    sfRenderWindow_drawCircleShape(win->window, player->visor, NULL);
    return EXIT_SUCCESS;
}

static int manage_window(window_t *win, player_t *player, map_t *map)
{
    if (win->is_menu == true){
        display_menu(win);
        if (win->menu.music_started == false){
            sfMusic_play(win->menu.music);
            sfMusic_setLoop(win->menu.music, sfTrue);
            win->menu.music_started = true;
        }
    }
    if (win->is_single == true) {
        win->is_param = false;
        sfMusic_stop(win->menu.music);
        if (display_game_elements(win, player, map) == EXIT_FAILURE)
            return EXIT_FAILURE;
        if (display_hud(win, player, map) == EXIT_FAILURE)
            return EXIT_FAILURE;
    }
    if (win->is_param == true)
        display_param(win);
    return EXIT_SUCCESS;
}

static int render_window(window_t *win, player_t *player, map_t *map)
{
    exctract(map, player, player->inventory, win);
    verif_play_sound(player, map, win);
    verif_footsteps(player, win);
    player->is_moving = false;
    stamina_regen(player);
    sfRenderWindow_clear(win->window, win->bg_color);
    win->clock.time = sfClock_restart(win->clock.clock);
    sfClock_restart(win->clock.trans_clock);
    win->clock.elapsed_time_trans += win->clock.time.microseconds /
        SECOND;
    win->clock.elapsed_time_bg += win->clock.time.microseconds /
        SECOND;
    if (manage_window(win, player, map) == EXIT_FAILURE)
        return EXIT_FAILURE;
    manage_keyboard(player, map, win);
    sfRenderWindow_display(win->window);
    manage_client_network(win, map);
    return EXIT_SUCCESS;
}

static int game_loop(window_t *wolf_win, player_t *player, map_t *map)
{
    sfVector2i mouse_pos;

    create_hud(wolf_win);
    sfMusic_play(wolf_win->menu.music);
    sfMusic_setLoop(wolf_win->menu.music, sfTrue);
    while (sfRenderWindow_isOpen(wolf_win->window)) {
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

static int init_all(window_t *win, map_t **map, player_t **player)
{
    win->client = NULL;
    if (!win)
        return EXIT_FAILURE;
    if (init_player(player) == EXIT_FAILURE) {
        destroy_assets(win, *player);
        return EXIT_FAILURE;
    }
    if (init_map(map) == EXIT_FAILURE) {
        destroy_assets(win, *player);
        return EXIT_FAILURE;
    }
    if (init_window(win) == EXIT_FAILURE)
        return EXIT_FAILURE;
    init_weapons(win);
    init_hand_inv(player, win);
    init_visor(player, win);
    return EXIT_SUCCESS;
}

int wolf(void)
{
    window_t *wolf_win = malloc(sizeof(window_t));
    player_t *player = malloc(sizeof(*player));
    map_t *map = NULL;

    if (init_all(wolf_win, &map, &player) == EXIT_FAILURE)
        return EXIT_FAILURE;
    init_minimap(wolf_win);
    //load_save(player, map);
    if (game_loop(wolf_win, player, map) == EXIT_FAILURE)
        return EXIT_FAILURE;
    save_in_file(player, map);
    destroy_assets(wolf_win, player);
    return EXIT_SUCCESS;
}
