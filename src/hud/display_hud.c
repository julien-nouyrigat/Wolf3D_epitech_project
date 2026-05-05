/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** display_hud
*/

#include <string.h>
#include <stdlib.h>

#include "wolf.h"

int display_hud(window_t *win, player_t *player)
{
    char *life = calloc(sizeof(char), LIFE_LEN + 1);
    char *stamina = calloc(sizeof(char), STAM_LEN + 1);

    if (!life || !stamina)
        return EXIT_FAILURE;
    sprintf(life, "%zu/%zu", player->life, player->max_life);
    sprintf(stamina, "%zu/%zu", player->stamina, player->max_stamina);
    sfText_setString(win->hud.life, life);
    sfText_setString(win->hud.stamina, stamina);
    sfRenderWindow_drawText(win->window, win->hud.life, NULL);
    sfRenderWindow_drawText(win->window, win->hud.stamina, NULL);
    sfRenderWindow_drawSprite(win->window, win->hud.cross, NULL);
    sfRenderWindow_drawSprite(win->window, win->hud.lightning, NULL);
    free(life);
    free(stamina);
    return EXIT_SUCCESS;
}
