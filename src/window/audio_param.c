/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** audio_param
*/

#include <string.h>
#include "wolf.h"

static void apply_volume(window_t *win, uint8_t modif)
{
    if (modif == 1) {
        if (win->param.audio.volume > 0)
            win->param.audio.volume--;
    } else
        if (win->param.audio.volume < 100)
            win->param.audio.volume++;
}

static void change_volume(window_t *win)
{
    sfVector2f size;
    sfVector2i pos_mouse = sfMouse_getPositionRenderWindow(win->window);

    if (sfFloatRect_contains(&win->param.audio.audio_txt[2].bound,
            pos_mouse.x, pos_mouse.y)) {
        if (win->event.type == sfEvtMouseButtonPressed)
            apply_volume(win, 1);
    }
    if (sfFloatRect_contains(&win->param.audio.audio_txt[3].bound,
            pos_mouse.x, pos_mouse.y)) {
        if (win->event.type == sfEvtMouseButtonPressed)
            apply_volume(win, 2);
    }
    strcpy(win->param.audio.string_pourcent, my_itoa(win->param.audio.volume));
    strcat(win->param.audio.string_pourcent, "%");
    size.x = (380 / 100) * win->param.audio.volume;
    size.y = 35;
    sfRectangleShape_setSize(win->param.audio.audio_rect[2].rect, size);
    sfText_setString(win->param.audio.audio_txt[4].text,
        win->param.audio.string_pourcent);
}

void display_audio(window_t *win)
{
    change_volume(win);
    sfMusic_setVolume(win->menu.music, win->param.audio.volume);
    for (size_t i = 0; i < NB_RECT_AUDIO; i++)
        sfRenderWindow_drawRectangleShape(win->window,
            win->param.audio.audio_rect[i].rect, NULL);
    for (size_t i = 0; i < NB_TEXT_AUDIO; i++)
        sfRenderWindow_drawText(win->window, win->param.audio.audio_txt[i].text,
            NULL);
}
