/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** wolf
*/

#ifndef WOLF_H_
    #define WOLF_H_

    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>
    #include <SFML/Graphics.h>
    #include <SFML/Graphics/Export.h>
    #include <SFML/Graphics/BlendMode.h>
    #include <SFML/Graphics/Color.h>
    #include <SFML/Graphics/Rect.h>
    #include <SFML/Graphics/Transform.h>
    #include <SFML/Graphics/Types.h>
    #include <SFML/System/Vector2.h>
    #include <SFML/Audio.h>

    #undef EXIT_SUCCESS
    #undef EXIT_FAILURE

    #define EXIT_SUCCESS 0
    #define EXIT_FAILURE 84

int flag_h(void);
int wolf(void);

#endif /* WOLF_H_ */
