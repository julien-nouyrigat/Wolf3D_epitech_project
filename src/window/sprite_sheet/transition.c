/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** transition
*/

#include "wolf.h"

void init_transition(window_t *win)
{
    win->transition.s_bg = sfSprite_create();
    win->transition.t_bg = sfTexture_createFromFile(
        "./assets/sprite_sheet/transiition.png", NULL);
    sfSprite_setTexture(win->transition.s_bg, win->transition.t_bg, sfTrue);
    win->transition.rect_bg.top = 0;
    win->transition.rect_bg.left = 0;
    win->transition.rect_bg.width = SIZE_X_TRANS;
    win->transition.rect_bg.height = SIZE_Y_TRANS;
    win->transition.col = 0;
    win->transition.line = 0;
    sfSprite_setTextureRect(win->transition.s_bg, win->transition.rect_bg);
    sfSprite_setScale(win->transition.s_bg, (sfVector2f){7.8, 8.2});
    sfSprite_setPosition(win->transition.s_bg, (sfVector2f){-10, -10});
}

void display_transition(window_t *win)
{
    if (win->clock.elapsed_time_trans >= IPS_TRANS) {
        win->clock.elapsed_time_trans -= IPS_TRANS;
        win->transition.col++;
        if (win->transition.col >= COL_TRANS) {
            win->transition.col = 0;
            win->transition.line++;
            win->transition.line = win->transition.line >= LINE_TRANS ? 0 :
                win->transition.line;
        }
        if (win->transition.line == LINE_TRANS - 1 &&
            win->transition.col == LAST_LINE_TRANS) {
            win->transition.is_play = true;
            win->transition.col = 0;
            win->transition.line = 0;
        }
        win->transition.rect_bg.left = win->transition.col * SIZE_X_TRANS;
        win->transition.rect_bg.top = win->transition.line * SIZE_Y_TRANS;
        sfSprite_setTextureRect(win->transition.s_bg, win->transition.rect_bg);
    }
    sfRenderWindow_drawSprite(win->window, win->transition.s_bg, NULL);
}
