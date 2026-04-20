/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** window
*/

#ifndef WINDOW_H_
    #define WINDOW_H_

    #include <stdio.h>
    #include <SFML/Graphics.h>
    #include <SFML/Graphics/Export.h>
    #include <SFML/Graphics/BlendMode.h>
    #include <SFML/Graphics/Color.h>
    #include <SFML/Graphics/Rect.h>
    #include <SFML/Graphics/Transform.h>
    #include <SFML/Graphics/Types.h>
    #include <SFML/System/Vector2.h>
    #include <stdbool.h>
    #include <SFML/Audio.h>

    #define FRAMES_LIMIT 60
    #define WIN_WIDTH 1980
    #define WIN_HEIGHT 1080
    #define WIN_BPP 32
    #define LINE_SIZE 3

typedef struct {
    char pseudo[BUFSIZ];
    int index_pseudo;
    sfText *text;
    sfText *start;
    sfText *title;
    sfRectangleShape *rect;
    sfRectangleShape *butt;
} pseudo_t;

typedef struct {
    char ip[BUFSIZ];
    int index_ip;
    sfText *text;
    sfText *start;
    sfRectangleShape *rect;
    sfRectangleShape *butt;
} ip_t;

typedef struct {
    sfRenderWindow *window;
    sfEvent event;
    sfColor bg_color;
    bool is_pseudo;
    bool is_connect;
    bool launch_game;
    pseudo_t *pseudo;
    ip_t *ip;
    sfTexture *texture;
    sfSprite *background;
} window_t;

#endif /* WINDOW_H_ */
