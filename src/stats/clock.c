/*
** EPITECH PROJECT, 2018
** clock.c
** File description:
** HEADER
*/

#include "prototype.h"

int r_number(scene_t *scene, int nb)
{
    int o = 0;
    int y = 0;

    scene->times = sfClock_getElapsedTime(scene->clocks);
    o = (int)scene->times.microseconds;
    y = o % nb;
    return (y);
}

void clock_ennemie(ennemi_t *ennemi)
{
    ennemi->time = sfClock_getElapsedTime(ennemi->clock);
    ennemi->seconds = ennemi->time.microseconds / 1000000.0;
}

void clockcreate(strct *strct, int nbr)
{
    int k = 0;

    while (k != nbr) {
        strct->timer[k].clock = sfClock_create();
        k ++;
    }
}

void clockelapsed(strct *strct, int nbr)
{
    int k = 0;

    while (k != nbr) {
        strct->timer[k].time = sfClock_getElapsedTime(strct->timer[k].clock);
        k ++;
    }
}
