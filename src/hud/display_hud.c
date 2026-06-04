/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** display_hud
*/

#include <string.h>
#include <stdlib.h>

#include "wolf.h"

static void display_dead_text(window_t *win)
{
    sfText_setString(win->hud.go_back, "Press [A] to return to the game menu");
    sfText_setString(win->hud.dead_text, "GAME OVER");
    sfRenderWindow_drawText(win->window, win->hud.dead_text, NULL);
    sfRenderWindow_drawText(win->window, win->hud.go_back, NULL);
}

static void free_two_string(char *string, char *string2)
{
    free(string);
    free(string2);
}

static int display_money(window_t *win, player_t *player, map_t *map)
{
    char *lvl_money = calloc(sizeof(char), 14 + 1);
    char *player_money = calloc(sizeof(char), 14 + 1);

    if (!lvl_money || !player_money)
        return EXIT_FAILURE;
    sprintf(lvl_money, "%zu$ / %zu$", map->level->cur_money,
        level_data[map->level->lvl_id].lvl_money);
    sprintf(player_money, "%zu$", player->inventory->player_money);
    sfText_setString(win->hud.lvl_money, lvl_money);
    sfText_setString(win->hud.player_money, player_money);
    sfRenderWindow_drawText(win->window, win->hud.lvl_money, NULL);
    sfRenderWindow_drawText(win->window, win->hud.player_money, NULL);
    free_two_string(lvl_money, player_money);
    return EXIT_SUCCESS;
}

int display_hud(window_t *win, player_t *player, map_t *map)
{
    char *life = calloc(sizeof(char), LIFE_LEN + 1);
    char *stamina = calloc(sizeof(char), STAM_LEN + 1);

    if (!life || !stamina)
        return EXIT_FAILURE;
    if (player->life == 0){
        display_dead_text(win);
        free_two_string(life, stamina);
        return EXIT_SUCCESS;
    }
    sprintf(life, "%zu/%zu", player->life, player->max_life);
    sprintf(stamina, "%zu/%zu", player->stamina, player->max_stamina);
    sfText_setString(win->hud.life, life);
    sfText_setString(win->hud.stamina, stamina);
    sfRenderWindow_drawText(win->window, win->hud.life, NULL);
    sfRenderWindow_drawText(win->window, win->hud.stamina, NULL);
    sfRenderWindow_drawSprite(win->window, win->hud.cross, NULL);
    sfRenderWindow_drawSprite(win->window, win->hud.lightning, NULL);
    free_two_string(life, stamina);
    return display_money(win, player, map);
}
