/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** init_weapons
*/

#include <stdlib.h>

#include "wolf.h"

static sfVector2f get_scale(window_t *win, size_t i)
{
    sfVector2u size = sfTexture_getSize(win->icons_texts[i]);
    sfVector2f scale = (sfVector2f){ICON_SIZE / (float)size.x,
        ICON_SIZE / (float)size.y};

    return scale;
}

static void create_weapon(window_t *win, size_t i)
{
    win->weapons_tab[i]->type = i;
    win->weapons_tab[i]->stats = calloc(sizeof(weapons_data_t), 1);
    if (win->weapons_tab[i]->stats == NULL)
        return;
    win->weapons_tab[i]->stats->damage = weapons_data[i].damage;
    win->weapons_tab[i]->stats->cooldown = weapons_data[i].cooldown;
    win->weapons_tab[i]->stats->stun_time = weapons_data[i].stun_time;
    win->weapons_tab[i]->stats->charge = weapons_data[i].charge;
    win->weapons_tab[i]->stats->range = weapons_data[i].range;
    win->weapons_tab[i]->sprite = sfSprite_create();
    sfSprite_setTexture(win->weapons_tab[i]->sprite, win->weapons_texts[i],
        true);
    win->weapons_tab[i]->icon = sfSprite_create();
    sfSprite_setTexture(win->weapons_tab[i]->icon, win->icons_texts[i], true);
    sfSprite_setScale(win->weapons_tab[i]->icon, get_scale(win, i));
    win->weapons_tab[i]->bullets = win->weapons_tab[i]->stats->charge;
}

void init_weapons(window_t *win)
{
    win->weapons_tab = calloc(sizeof(weapon_t *), NB_WEAPONS);
    if (win->weapons_tab == NULL)
        return;
    for (size_t i = 0; i < NB_WEAPONS; i++) {
        win->weapons_tab[i] = calloc(sizeof(weapon_t), 1);
        if (win->weapons_tab[i] == NULL)
            return;
        create_weapon(win, i);
    }
}
