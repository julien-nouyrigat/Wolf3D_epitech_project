/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** weapons
*/

#ifndef WEAPONS_H_
    #define WEAPONS_H_

    #include "textures.h"

enum weapons {
    SWORD,
    GUN,
    SHOTGUN,
    PHOTON_BLASTER,
    //BOLTZAP,
    //TRANQ_GUN,
    NB_WEAPONS
};

typedef struct {
    size_t damage;
    float cooldown;
    float stun_time;
    size_t charge;
    int range;
} weapons_data_t;

static const weapons_data_t weapons_data[NB_WEAPONS] = {
    {50, 0.5, 0, 15, 30},
    {80, 1.0, 0.5, 15, 2000},
    {300, 2.0, 1.5, 5, 200},
    {270, 3.0, 3.0, 5, 600},
    //{8, 1.0, 4.0, 20, 2000},
    //{0, 1.0, 15.0, 8, 600}
};

typedef struct {
    size_t type;
    weapons_data_t *stats;
    sfSprite *sprite;
    sfSprite *icon;
    size_t bullets;
} weapon_t;

static const textures_t weapons_textures[NB_WEAPONS] = {
    {"./assets/weapons/sword.png"},
    {"./assets/weapons/gun.png"},
    {"./assets/weapons/shotgun.png"},
    {"./assets/weapons/photon_blaster.png"}
};

static const textures_t weapons_icons[NB_WEAPONS] = {
    {"./assets/weapons/sword_icon.png"},
    {"./assets/weapons/gun_icon.png"},
    {"./assets/weapons/shotgun_icon.png"},
    {"./assets/weapons/photon_blaster_icon.png"}
};

#endif /* WEAPONS_H_ */
