/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** init_weapons
*/

#include <stdlib.h>

#include "wolf.h"

void init_weapons(window_t *win)
{
    for (size_t i = 0; i < NB_WEAPONS; i++) {
        win->weapons[i].type = i;
        win->weapons[i].stats = calloc(sizeof(weapons_data_t), 1);
        if (win->weapons[i].stats == NULL)
            return;
        win->weapons[i].stats->damage = weapons_data[i].damage;
        win->weapons[i].stats->cooldown = weapons_data[i].cooldown;
        win->weapons[i].stats->stun_time = weapons_data[i].stun_time;
        win->weapons[i].stats->charge = weapons_data[i].charge;
        win->weapons[i].stats->range = weapons_data[i].range;
        win->weapons[i].sprite = sfSprite_create();
        sfSprite_setTexture(win->weapons[i].sprite, win->weapons_texts[i],
            true);
        win->weapons[i].icon = sfSprite_create();
        sfSprite_setTexture(win->weapons[i].icon, win->icons_texts[i], true);
        win->weapons[i].bullets = win->weapons[i].stats->charge;
    }
}
