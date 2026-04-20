/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** init_window
*/

#include <stdlib.h>
#include "wolf.h"

static void init_text(sfText *text, int size, sfVector2f *pos, sfFont *font)
{
    sfText_setCharacterSize(text, size);
    sfText_setFont(text, font);
    sfText_setPosition(text, *pos);
}

static int init_ip(window_t *wolf_win)
{
    wolf_win->ip = malloc(sizeof(*wolf_win->ip));
    if (!wolf_win->ip)
        return EXIT_FAILURE;
    wolf_win->ip->butt = sfRectangleShape_create();
    wolf_win->ip->index_ip = 0;
    wolf_win->ip->rect = sfRectangleShape_create();
    wolf_win->ip->text = sfText_create();
    if (!wolf_win->ip->butt || !wolf_win->ip->rect ||
        !wolf_win->ip->text)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

static void init_title(window_t *wolf_win)
{
    sfFont *agency = sfFont_createFromFile("./assets/font/AGENCYB.TTF");
    sfVector2f pos = {500, 300};
    sfColor yellow = sfColor_fromRGB(222, 185, 53);

    wolf_win->pseudo->title = sfText_create();
    init_text(wolf_win->pseudo->title, 100, &pos, agency);
    sfText_setFillColor(wolf_win->pseudo->title, yellow);
    sfText_setString(wolf_win->pseudo->title, "YOUR PSEUDO");
}

static int init_pseudo(window_t *wolf_win)
{
    sfVector2f pos_pseudo = {500, 500};
    sfVector2f pos_rect = {500, 900};
    sfFont *bug = sfFont_createFromFile("./assets/font/bugfast.ttf");

    wolf_win->pseudo = malloc(sizeof(*wolf_win->pseudo));
    if (!wolf_win->pseudo)
        return EXIT_FAILURE;
    wolf_win->pseudo->index_pseudo = 0;
    wolf_win->pseudo->pseudo[0] = '\0';
    wolf_win->pseudo->butt = sfRectangleShape_create();
    wolf_win->pseudo->rect = sfRectangleShape_create();
    wolf_win->pseudo->text = sfText_create();
    init_text(wolf_win->pseudo->text, 100, &pos_pseudo, bug);
    sfRectangleShape_setSize(wolf_win->pseudo->butt, (sfVector2f){400, 200});
    return EXIT_SUCCESS;
}

static int init_background(window_t *wolf_win)
{
    wolf_win->background = sfSprite_create();
    if (!wolf_win->background)
        return EXIT_FAILURE;
    wolf_win->texture = sfTexture_createFromFile(
        "./assets/png/background_truck.jpg", NULL);
    if (!wolf_win->texture)
        return EXIT_FAILURE;
    sfSprite_setTexture(wolf_win->background, wolf_win->texture, sfTrue);
    sfSprite_setScale(wolf_win->background, (sfVector2f){2, 2});
    sfSprite_setPosition(wolf_win->background, (sfVector2f){0, 0});
    return EXIT_SUCCESS;
}

int init_window(window_t *wolf_win)
{
    sfVideoMode mode = {WIN_WIDTH, WIN_HEIGHT, WIN_BPP};

    wolf_win->window = sfRenderWindow_create(mode, "Wolf3D",
        sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(wolf_win->window, FRAMES_LIMIT);
    if (!wolf_win->window)
        return EXIT_FAILURE;
    if (init_ip(wolf_win) != EXIT_SUCCESS)
        return EXIT_FAILURE;
    if (init_pseudo(wolf_win) != EXIT_SUCCESS)
        return EXIT_FAILURE;
    if (init_background(wolf_win) != EXIT_SUCCESS)
        return EXIT_FAILURE;
    init_title(wolf_win);
    wolf_win->bg_color = sfColor_fromRGB(96, 96, 96);
    return EXIT_SUCCESS;
}
