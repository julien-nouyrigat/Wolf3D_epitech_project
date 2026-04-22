/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** background_menu
*/

#include "wolf.h"

int init_brackground_menu(window_t *win)
{
    win->menu.s_bg = sfSprite_create();
    win->menu.t_bg = sfTexture_createFromFile(
        "./assets/sprite_sheet/spritesheet.png", NULL);
    sfSprite_setTexture(win->menu.s_bg, win->menu.t_bg, sfTrue);
    win->menu.rect_bg.top = 0;
    win->menu.rect_bg.left = 0;
    win->menu.rect_bg.width = SIZE_X_BG;
    win->menu.rect_bg.height = SIZE_Y_BG;
    win->menu.col_ss_bg = 0;
    win->menu.line_ss_bg = 0;
    sfSprite_setTextureRect(win->menu.s_bg, win->menu.rect_bg);
    sfSprite_setScale(win->menu.s_bg, (sfVector2f){6.3, 6.1});
    sfSprite_setPosition(win->menu.s_bg, (sfVector2f){-10, -10});
    return EXIT_SUCCESS;
}

void display_background_menu(window_t *win)
{
    if (win->clock.elapsed_time_bg >= IPS_BG) {
        win->clock.elapsed_time_bg -= IPS_BG;
        win->menu.col_ss_bg++;
        if (win->menu.col_ss_bg >= COL_BG) {
            win->menu.col_ss_bg = 0;
            win->menu.line_ss_bg++;
            win->menu.line_ss_bg = win->menu.line_ss_bg >= LINE_BG ? 0 :
                win->menu.line_ss_bg;
        }
        if (win->menu.line_ss_bg == LINE_BG - 1 &&
            win->menu.col_ss_bg == LAST_LINE_BG) {
            win->menu.col_ss_bg = 0;
            win->menu.line_ss_bg = 0;
        }
        win->menu.rect_bg.left = win->menu.col_ss_bg * SIZE_X_BG;
        win->menu.rect_bg.top = win->menu.line_ss_bg * SIZE_Y_BG;
        sfSprite_setTextureRect(win->menu.s_bg, win->menu.rect_bg);
    }
    sfRenderWindow_drawSprite(win->window, win->menu.s_bg, NULL);
}
