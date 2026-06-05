/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** boutique
*/

#include <stdlib.h>
#include <stdio.h>
#include "wolf.h"
#include "boutique.h"

static void apply_shop_bonus(player_t *player, shop_item_t *item)
{
    if (item->type == ITEM_BONUS && item->id >= 0 && item->id < NB_BONUS)
        BONUS_FUNCTIONS[item->id](player);
    if (item->type == ITEM_WEAPON) {
        return;
    }
}

static void resize_shop_item(shop_item_t *item)
{
    sfVector2f custom_scale = {1.0f, 1.0f};

    if (item->type == ITEM_WEAPON)
        custom_scale = WEAPON_SCALES[item->id];
    else
        custom_scale = BONUS_SCALES[item->id];
    sfSprite_setScale(item->sprite, custom_scale);
}

static void assign_item_texture(shop_item_t *item)
{
    if (rand() % 5 == 0) {
        item->type = ITEM_WEAPON;
        item->id = rand() % NB_WEAPONS;
        item->price = WEAPON_PRICES[item->id];
        item->texture = sfTexture_createFromFile(
            weapons_icons[item->id].texture, NULL);
    } else {
        item->type = ITEM_BONUS;
        item->id = rand() % NB_BONUS;
        item->price = BONUS_PRICES[item->id];
        item->texture = sfTexture_createFromFile(
            BONUS_ICONS_PATHS[item->id], NULL);
    }
}

static void generate_single_item(shop_item_t *item, int i)
{
    sfVector2f pos = {300.0f + (i * 400.0f), 700.0f};

    item->is_bought = false;
    if (item->texture)
        sfTexture_destroy(item->texture);
    assign_item_texture(item);
    if (item->sprite == NULL)
        item->sprite = sfSprite_create();
    sfSprite_setTexture(item->sprite, item->texture, sfTrue);
    resize_shop_item(item);
    sfSprite_setPosition(item->sprite, pos);
    item->bound = sfSprite_getGlobalBounds(item->sprite);
}

void generate_shop_items(shop_t *shop)
{
    shop->total_spent = 0;
    sfText_setString(shop->spent_text, "0$");
    for (int i = 0; i < 3; i++)
        generate_single_item(&shop->items[i], i);
}

static void display_single_item(sfRenderWindow *win, shop_t *shop, int i,
    sfVector2f *mp)
{
    char str[32] = {0};
    sfVector2f t_pos = {shop->items[i].bound.left,
        shop->items[i].bound.top + shop->items[i].bound.height + 15.0f};

    if (shop->items[i].is_bought)
        return;
    if (shop->items[i].sprite)
        sfRenderWindow_drawSprite(win, shop->items[i].sprite, NULL);
    if (sfFloatRect_contains(&(shop->items[i].bound), mp->x, mp->y)) {
        sprintf(str, "%d$", shop->items[i].price);
        sfText_setString(shop->price_text, str);
        sfText_setPosition(shop->price_text, t_pos);
        sfRenderWindow_drawText(win, shop->price_text, NULL);
    }
}

void display_shop(sfRenderWindow *window, shop_t *shop)
{
    sfVector2i m_pos = sfMouse_getPositionRenderWindow(window);
    sfVector2f mp = {(float)m_pos.x, (float)m_pos.y};

    sfRenderWindow_drawSprite(window, shop->s_bg, NULL);
    for (int i = 0; i < 3; i++)
        display_single_item(window, shop, i, &mp);
    if (shop->spent_text)
        sfRenderWindow_drawText(window, shop->spent_text, NULL);
}

static void init_shop_texts(shop_t *shop)
{
    shop->font = sfFont_createFromFile("./assets/fonts/teko.ttf");
    shop->price_text = sfText_create();
    sfText_setFont(shop->price_text, shop->font);
    sfText_setCharacterSize(shop->price_text, 30);
    sfText_setFillColor(shop->price_text, sfYellow);
    sfText_setOutlineColor(shop->price_text, sfBlack);
    sfText_setOutlineThickness(shop->price_text, 2.0f);
    shop->total_spent = 0;
    shop->spent_text = sfText_create();
    sfText_setFont(shop->spent_text, shop->font);
    sfText_setCharacterSize(shop->spent_text, 45);
    sfText_setFillColor(shop->spent_text, sfGreen);
    sfText_setOutlineColor(shop->spent_text, sfBlack);
    sfText_setOutlineThickness(shop->spent_text, 3.0f);
    sfText_setPosition(shop->spent_text, (sfVector2f){1400.0f, 300.0f});
    sfText_setString(shop->spent_text, "0$");
}

shop_t *init_shop(void)
{
    shop_t *shop = malloc(sizeof(shop_t));

    shop->is_open = false;
    shop->t_bg = sfTexture_createFromFile("./assets/image/shop_bg.png", NULL);
    shop->s_bg = sfSprite_create();
    if (shop->t_bg)
        sfSprite_setTexture(shop->s_bg, shop->t_bg, sfTrue);
    sfSprite_setScale(shop->s_bg, (sfVector2f){1.17, 1.17});
    for (int i = 0; i < 3; i++) {
        shop->items[i].sprite = NULL;
        shop->items[i].texture = NULL;
    }
    init_shop_texts(shop);
    generate_shop_items(shop);
    return shop;
}

static void try_buy_item(shop_t *shop, player_t *player, int i)
{
    char str[64] = {0};

    if ((int)player->inventory->player_money >= shop->items[i].price) {
        shop->total_spent += shop->items[i].price;
        sprintf(str, "%d $", shop->total_spent);
        sfText_setString(shop->spent_text, str);
        shop->items[i].is_bought = true;
        apply_shop_bonus(player, &shop->items[i]);
    }
}

void handle_shop_click(window_t *win, player_t *p, int m_x, int m_y)
{
    if (!win->is_shop || !win->shop)
        return;
    for (int i = 0; i < 3; i++) {
        if (!win->shop->items[i].is_bought &&
            sfFloatRect_contains(&win->shop->items[i].bound, m_x, m_y)) {
            try_buy_item(win->shop, p, i);
        }
    }
}
