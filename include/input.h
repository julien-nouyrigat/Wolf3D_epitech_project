/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** input
*/

#ifndef INPUT_H_
    #define INPUT_H_

    #include "wolf.h"

typedef void(*function_t)(player_t *player, map_t *map);

typedef struct keyboard_fpt_s {
    sfKeyCode code;
    function_t function;
} keyboard_fpt_t;

#endif /* INPUT_H_ */
