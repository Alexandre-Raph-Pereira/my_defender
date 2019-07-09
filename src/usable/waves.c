/*
** EPITECH PROJECT, 2019
** My Defender
** File description:
** Waves
*/

#include "prototype.h"

int count_ennemi(scene_t *scene)
{
    ennemi_t *ennemi = scene->ennemi;
    int i = 0;

    while (ennemi != NULL) {
        i ++;
        ennemi = ennemi->next;
    }
    return (i);
}

int waves(scene_t *scene)
{
    static int i = 0;
    static int wa = 3;
    int enn = count_ennemi(scene);
    int r = 0;

    if (i < wa) {
        r = nbr_ennemi(scene);
        if (r == 1)
            i ++;
        if (r == 84)
            return (84);
    }
    if (i == wa && enn == 0) {
        wa += 3;
        i = 0;
    }
    return (0);
}
