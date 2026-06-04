/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** manage_game_mouse
*/

#include "wolf.h"

static bool can_shoot(player_t *player)
{
    sfTime cooldown = sfClock_getElapsedTime(player->in_hand->w_clock);

    if (player->in_hand == NULL)
        return false;
    if (player->in_hand->bullets == 0 || cooldown.microseconds / SECOND <
        player->in_hand->stats->cooldown)
        return false;
    return true;
}

static void manage_mouse_buttons(window_t *win, player_t *player, map_t *map)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) && can_shoot(player)) {
        player->shoots = true;
        sfClock_restart(player->in_hand->animation);
        shoot_weapon(win, player, map);
        sfClock_restart(player->in_hand->w_clock);
    }
}

void manage_game_mouse(window_t *win, player_t *player, map_t *map)
{
    if (win->event.type == sfEvtMouseWheelScrolled) {
        if (win->event.mouseWheelScroll.delta > 0)
            inv_sup(player, map);
        else
            inv_inf(player, map);
    }
    if (win->event.type == sfEvtMouseButtonPressed)
        manage_mouse_buttons(win, player, map);
}
