/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** inventory
*/

#ifndef INVENTORY_H_
    #define INVENTORY_H_

    #include <stdio.h>
    #include <SFML/Graphics.h>
    #include <SFML/Graphics/Export.h>
    #include <SFML/Graphics/BlendMode.h>
    #include <SFML/Graphics/Color.h>
    #include <SFML/Graphics/Rect.h>
    #include <SFML/Graphics/Transform.h>
    #include <SFML/Graphics/Types.h>
    #include <SFML/System/Vector2.h>
    #include <SFML/Audio.h>
    #include <stdbool.h>

    #include "weapons.h"

    #define NB_MAX_ITEM 16
    #define EMPTY_SLOT -1
    #define HAND_INV_SIZE 150
    #define EMPTY_HAND_INV 1000
    #define INV_COLOR sfColor_fromRGB(96, 96, 96)
    #define INV_FONT "./assets/fonts/teko.ttf"

enum type_loot_s {
    BONSAI,
    BRACELET,
    WATCH,
    PETRI,
    NB_ITEMS
};

typedef struct item_s {
    int weight;
    int price;
    int durability;
    sfVector2f position;
    sfVector2f direction;
    sfTexture *textures;
    bool is_grab;
    float order_dist;
} item_t;

typedef struct loot_s {
    size_t type;
    item_t *item;
    struct loot_s *next;
} loot_t;


typedef struct {
    int weight;
    int price;
    int durability;
    char *asset_path;
} item_data_t;

static const item_data_t item_data[NB_ITEMS] = {
    {10, 100, 200, "assets/items/Bonsai_Tree.png"},
    {5, 60, 10, "assets/items/Bracelet.png"},
    {5, 60, 10, "assets/items/Pocket_Watch.png"},
    {5, 60, 10, "assets/items/Uranium_Petri_Dish.png"},
};

typedef struct {
    sfTexture *t_inventory;
    sfSprite *s_inventory;
    sfVector2f pos;
    int *inventory;
} inventory_t;

typedef struct {
    sfRectangleShape *one;
    sfText *t_one;
    weapon_t *w_one;
    sfRectangleShape *two;
    sfText *t_two;
    weapon_t *w_two;
    sfRectangleShape *three;
    sfText *t_three;
    weapon_t *w_three;
} hand_inv_t;

#endif /* INVENTORY_H_ */
