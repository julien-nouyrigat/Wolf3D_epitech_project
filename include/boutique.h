/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** boutique
*/

#ifndef BOUTIQUE_H
    #define BOUTIQUE_H

    #include <SFML/Graphics.h>
    #include <stdbool.h>
    #include "weapons.h"
    #include "player.h"
    #include "window.h"

    #define NB_ITEMS_SHOP 3

typedef void (*bonus_effect_t)(player_t *player);

enum item_type {
    ITEM_WEAPON,
    ITEM_BONUS
};

enum bonus {
    REGEN_25,
    REGEN_50,
    REGEN_75,
    REGEN_100,
    STAMINA_20,
    LIFE_20,
    STRENGHT,
    AMMOS,
    NB_BONUS
};

static const int WEAPON_PRICES[NB_WEAPONS] = {
    50, 150, 400, 800
};

static const int BONUS_PRICES[NB_BONUS] = {
    25, 50, 7, 10, 10, 10, 20, 50
};

static const sfVector2f WEAPON_SCALES[NB_WEAPONS] = {
    {0.2f, 0.2f},
    {0.3f, 0.3f},
    {0.2f, 0.2f},
    {0.3f, 0.3f}
};

static const sfVector2f BONUS_SCALES[NB_BONUS] = {
    {1.0f, 1.0f},
    {1.0f, 1.0f},
    {1.0f, 1.0f},
    {1.0f, 1.0f},
    {1.0f, 1.0f},
    {0.8f, 0.8f},
    {1.0f, 1.0f},
    {1.0f, 1.0f}
};

static const char *const BONUS_ICONS_PATHS[NB_BONUS] = {
    "./assets/image/regen25.png",
    "./assets/image/regen50.png",
    "./assets/image/regen100.png",
    "./assets/image/regen100.png",
    "./assets/image/stamina.png",
    "./assets/image/life.png",
    "./assets/image/strenght.png",
    "./assets/image/ammos.png"
};

typedef struct {
    enum item_type type;
    int id;
    int price;
    sfSprite *sprite;
    sfTexture *texture;
    sfFloatRect bound;
    bool is_bought;
} shop_item_t;

typedef struct {
    sfSprite *s_bg;
    sfTexture *t_bg;
    shop_item_t items[NB_ITEMS_SHOP];
    sfFont *font;
    sfText *price_text;
    bool is_open;
    int total_spent;
    sfText *spent_text;
} shop_t;

shop_t *init_shop(void);
void generate_shop_items(shop_t *shop);
void display_shop(sfRenderWindow *window, shop_t *shop);
void destroy_shop(shop_t *shop);
void apply_regen_25(player_t *player);
void apply_regen_50(player_t *player);
void apply_regen_100(player_t *player);
void apply_stamina_20(player_t *player);
void apply_life_20(player_t *player);
void apply_nothing(player_t __attribute_maybe_unused__ *player);
void apply_strenght(player_t *player);

static const bonus_effect_t BONUS_FUNCTIONS[NB_BONUS] = {
    &apply_regen_25,
    &apply_regen_50,
    &apply_nothing,
    &apply_regen_100,
    &apply_stamina_20,
    &apply_life_20,
    &apply_strenght,
    &apply_nothing
};

#endif
