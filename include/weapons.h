/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** weapons
*/

#ifndef WEAPONS_H_
    #define WEAPONS_H_

    #define INFINITE_RANGE 10000000

enum weapons {
    SWORD,
    GUN,
    SHOTGUN,
    PHOTON_BLASTER,
    BOLTZAP,
    TRANQ_GUN,
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
    {80, 1.0, 0.5, 15, INFINITE_RANGE},
    {300, 2.0, 1.5, 5, 200},
    {270, 3.0, 3.0, 5, 600},
    {8, 1.0, 4.0, 20, INFINITE_RANGE},
    {0, 1.0, 15.0, 8, 600}
};  

#endif /* WEAPONS_H_ */
