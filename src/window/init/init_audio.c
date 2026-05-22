/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** init_audio
*/

#include <string.h>
#include "wolf.h"

static void init_bound_arrow(window_t *win)
{
    sfText_setString(win->param.audio.audio_txt[2].text, "<");
    sfText_setString(win->param.audio.audio_txt[3].text, ">");
    sfText_setPosition(win->param.audio.audio_txt[2].text,
        (sfVector2f){1250, 412});
    sfText_setPosition(win->param.audio.audio_txt[3].text,
        (sfVector2f){1630, 412});
    for (int i = 2; i < NB_TEXT_AUDIO - 1; i++) {
        sfText_setCharacterSize(win->param.audio.audio_txt[i].text, 50);
        win->param.audio.audio_txt[i].bound = sfText_getGlobalBounds(
            win->param.audio.audio_txt[i].text);
    }
}

static void init_audio_text(window_t *win)
{
    sfText_setString(win->param.audio.audio_txt[0].text, "AUDIO");
    sfText_setString(win->param.audio.audio_txt[1].text, "MUSIC VOLUME");
    sfText_setString(win->param.audio.audio_txt[4].text,
        win->param.audio.string_pourcent);
    sfText_setPosition(win->param.audio.audio_txt[0].text,
        (sfVector2f){1130, 95});
    sfText_setPosition(win->param.audio.audio_txt[1].text,
        (sfVector2f){900, 400});
    sfText_setPosition(win->param.audio.audio_txt[4].text,
        (sfVector2f){1435, 416});
    sfText_setCharacterSize(win->param.audio.audio_txt[0].text, 180);
    sfText_setCharacterSize(win->param.audio.audio_txt[1].text, 70);
    sfText_setCharacterSize(win->param.audio.audio_txt[4].text, 40);
    sfText_setColor(win->param.audio.audio_txt[4].text, sfBlack);
    init_bound_arrow(win);
}

static void init_rect_pourcent(window_t *win)
{
    sfColor orange = sfColor_fromRGB(255, 165, 0);
    sfVector2f size;

    size.x = (350 / 100) * win->param.audio.volume;
    size.y = 35;
    sfRectangleShape_setFillColor(win->param.audio.audio_rect[2].rect, orange);
    sfRectangleShape_setPosition(win->param.audio.audio_rect[2].rect,
        (sfVector2f){1300, 427});
    sfRectangleShape_setSize(win->param.audio.audio_rect[2].rect, size);
}

static void init_audio_rect(window_t *win)
{
    sfColor outline_blue = sfColor_fromRGB(33, 140, 255);
    sfColor blue_in = sfColor_fromRGB(70, 104, 138);

    sfRectangleShape_setFillColor(win->param.audio.audio_rect[0].rect, sfBlack);
    sfRectangleShape_setOutlineThickness(win->param.audio.audio_rect[0].rect,
        2);
    sfRectangleShape_setOutlineColor(win->param.audio.audio_rect[0].rect,
        outline_blue);
    sfRectangleShape_setPosition(win->param.audio.audio_rect[0].rect,
        (sfVector2f){885, 412});
    sfRectangleShape_setSize(win->param.audio.audio_rect[0].rect,
        (sfVector2f){780, 70});
    sfRectangleShape_setFillColor(win->param.audio.audio_rect[1].rect, blue_in);
    sfRectangleShape_setPosition(win->param.audio.audio_rect[1].rect,
        (sfVector2f){1290, 420});
    sfRectangleShape_setSize(win->param.audio.audio_rect[1].rect,
        (sfVector2f){320, 50});
    init_rect_pourcent(win);
}

void init_audio(window_t *win)
{
    sfColor orange = sfColor_fromRGB(255, 165, 0);

    win->param.is_audio = false;
    win->param.audio.volume = 75;
    strcpy(win->param.audio.string_pourcent, "75%");
    for (int i = 0; i < NB_RECT_AUDIO; i++)
        win->param.audio.audio_rect[i].rect = sfRectangleShape_create();
    for (int i = 0; i < NB_TEXT_AUDIO; i++) {
        win->param.audio.audio_txt[i].text = sfText_create();
        sfText_setFont(win->param.audio.audio_txt[i].text, win->font);
    }
    init_audio_text(win);
    sfText_setColor(win->param.audio.audio_txt[0].text, orange);
    init_audio_rect(win);
}
