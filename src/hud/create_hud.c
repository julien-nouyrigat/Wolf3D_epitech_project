/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** create_hud
*/

#include "textures.h"
#include "wolf.h"

static void create_and_set_icons(window_t *win)
{
    win->hud.cross = sfSprite_create();
    win->hud.lightning = sfSprite_create();
    sfSprite_setTexture(win->hud.cross,
        win->textures[HEALTH_ICON - TEXT_TYPES], true);
    sfSprite_setTexture(win->hud.lightning,
        win->textures[STAMINA_ICON - TEXT_TYPES], true);
    sfSprite_setScale(win->hud.cross, (sfVector2f){2, 2});
    sfSprite_setPosition(win->hud.cross, (sfVector2f){250, 250});
}

static void set_text_pos(window_t *win)
{
    sfText_setPosition(win->hud.life, (sfVector2f){7, 7});
    sfText_setPosition(win->hud.stamina, (sfVector2f){7, 65});
}

void create_hud(window_t *win)
{
    win->hud.life = sfText_create();
    win->hud.stamina = sfText_create();
    sfText_setFont(win->hud.life, win->font);
    sfText_setFont(win->hud.stamina, win->font);
    sfText_setColor(win->hud.life, HEALTH_COLOR);
    sfText_setColor(win->hud.stamina, STAMINA_COLOR);
    sfText_setCharacterSize(win->hud.life, HUD_TEXT_SIZE);
    sfText_setCharacterSize(win->hud.stamina, HUD_TEXT_SIZE);
    set_text_pos(win);
    create_and_set_icons(win);
}
