/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** gun
*/
#include <unistd.h>
#include "wolf.h"

static bool not_shooting(window_t *win)
{
    if (!win->game.shoot) {
        win->game.rect_gun.left = 0;
        win->game.rect_gun.top = 5;
        sfSprite_setTextureRect(win->game.gun, win->game.rect_gun);
        return true;
    }
    return false;
}

static void animate_gun(window_t *win)
{
    float frame_time = 0.01f;

    if (not_shooting(win))
        return;
    win->game.anim_time += win->clock.time.microseconds / SECOND;
    if (win->game.anim_time >= frame_time) {
        win->game.anim_time = 0;
        win->game.current_frame++;
        if (win->game.current_frame >= COL_GUN * LINE_GUN) {
            win->game.current_frame = 0;
            win->game.shoot = false;
            win->game.rect_gun.left = 0;
            win->game.rect_gun.top = 5;
        } else {
            win->game.rect_gun.left = (win->game.current_frame % COL_GUN) * SIZE_X_GUN;
            win->game.rect_gun.top = ((win->game.current_frame / LINE_GUN) * SIZE_Y_GUN) + 5;
        }
        sfSprite_setTextureRect(win->game.gun, win->game.rect_gun);
    }
}

void draw_gun(window_t *win)
{
    win->clock.time = sfClock_restart(win->clock.clock);
    animate_gun(win);
    sfRenderWindow_drawSprite(win->window, win->game.gun, NULL);
}
