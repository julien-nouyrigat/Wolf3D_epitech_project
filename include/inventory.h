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

    #define NB_MAX_ITEM 16
    #define EMPTY_SLOT -1

enum item_indx_t {
    AXE,
    PAPER,
    NB_ITEM
};

typedef struct {
    int weight;
    int price;
    int durability;
    char *asset_path;
    sfVector2f pos;
} item_t;

static const item_t inv_tab[NB_ITEM] = {
    {10, 100, 200, "assets/item/axe.png", {0, 0}},
    {5, 60, 10, "assets/item/paper.png", {0, 0}},
};

typedef struct {
    sfTexture *t_inventory;
    sfSprite *s_inventory;
    sfVector2f pos;
    int *inventory;
} inventory_t;

#endif /* INVENTORY_H_ */
