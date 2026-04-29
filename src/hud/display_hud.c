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
    char *life = malloc(sizeof(char) * (strlen(my_itoa(player->life)) +
            strlen(my_itoa(player->max_life)) + 2));
    char *stamina = malloc(sizeof(char) * (strlen(my_itoa(player->life) +
                strlen(my_itoa(player->max_life)) + 2)));

    if (!life || !stamina)
        return EXIT_FAILURE;
    life = strcat(my_itoa(player->life), "/");
    life = strcat(life, my_itoa(player->max_life));
    stamina = strcat(my_itoa(player->stamina), "/");
    stamina = strcat(stamina, my_itoa(player->max_stamina));
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
