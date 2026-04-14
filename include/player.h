/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** player
*/

#ifndef PLAYER_H_
    #define PLAYER_H_

    #define NB_RAYS 60
    #define OFFSET 0.0001

typedef struct {
    float x;
    float y;
    float angle;
    float delta_x;
    float delta_y;
} player_t;

#endif /* PLAYER_H_ */
