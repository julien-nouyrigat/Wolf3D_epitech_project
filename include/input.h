/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** input
*/

#ifndef INPUT_H_
    #define INPUT_H_

    #include "wolf.h"

typedef void(*function_t)(player_t *player);

typedef struct keyboard_fpt_s {
    sfKeyCode code;
    input_enum_t input;
} keyboard_fpt_t;

#endif /* INPUT_H_ */
