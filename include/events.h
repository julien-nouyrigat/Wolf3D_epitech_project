/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** events
*/

#ifndef EVENTS_H_
    #define EVENTS_H_

    #define END 84
    #define DEAD_ZONE 15.0

typedef void (evt_fct_t)(window_t *win, player_t *player, map_t *map);

typedef struct evt_pfs_s {
    sfEventType type;
    evt_fct_t *function;
} evt_pfs_t;

#endif /* EVENTS_H_ */
