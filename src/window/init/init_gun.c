/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** init_gun
*/

#include "wolf.h"

void init_gun(window_t *win)
{
    win->game.gun = sfSprite_create();
    win->game.t_gun =
        sfTexture_createFromFile("assets/sprite_sheet/gun.png", NULL);
    sfSprite_setTexture(win->game.gun, win->game.t_gun, sfTrue);
    win->game.rect_gun = (sfIntRect){0, 0, SIZE_X_GUN, SIZE_Y_GUN - 5};
    win->game.col_ss_gun = 0;
    win->game.line_ss_gun = 0;
    win->game.current_frame = 0;
    win->game.anim_time = 0;
    win->game.shoot = false;
    sfSprite_setTextureRect(win->game.gun, win->game.rect_gun);
    sfSprite_setScale(win->game.gun, (sfVector2f){3, 3});
    sfSprite_setPosition(win->game.gun, (sfVector2f){990, 600});
    //win->gun_sound = sfMusic_createFromFile();///////////////:
}
