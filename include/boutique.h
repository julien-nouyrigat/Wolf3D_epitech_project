/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** boutique
*/

#ifndef BOUTIQUE_H
    #define BOUTIQUE_H

    #include <SFML/Graphics.h>
    #include "weapons.h"
    #define NB_ITEMS_SHOP 3

enum boost {
    REGEN_25,
    REGEN_50,
    REGEN_75,
    REGEN_100,
    LIFE,
    STAMINA,
    BULLETS,
    WEIGHT,
    NB_BOOST
};

typedef struct {
    size_t type;
    size_t price;
    sfSprite *icon;
} boost_data_t;

typedef struct {
    sfSprite *s_life;
    sfTexture *t_life;
    sfSprite *s_stam;
    sfTexture *t_stam;
    sfSprite *s_regen_25;
    sfSprite *s_regen_50;
    sfSprite *s_regen_75;
} boost_t;

typedef struct {
    
} items_t;

typedef struct shop_s {
    items_t items[NB_ITEMS_SHOP];
} shop_t;

#endif
