/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** display_pseudo
*/

#include "wolf.h"

void display_pseudo(window_t *win_wolf)
{
    sfRenderWindow_drawSprite(win_wolf->window, win_wolf->background, NULL);
    sfRenderWindow_drawRectangleShape(win_wolf->window, win_wolf->pseudo->butt,
        NULL);
    sfText_setString(win_wolf->pseudo->text, win_wolf->pseudo->pseudo);
    sfRenderWindow_drawText(win_wolf->window, win_wolf->pseudo->title, NULL);
    sfRenderWindow_drawText(win_wolf->window, win_wolf->pseudo->text, NULL);
}
