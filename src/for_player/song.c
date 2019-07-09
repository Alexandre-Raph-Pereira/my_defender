/*
** EPITECH PROJECT, 2019
** My Defender
** File description:
** Song file
*/

#include "prototype.h"

int damage_r(scene_t *scene)
{
    int y = r_number(scene, 27);

    if (y == 9)
        sfMusic_play(scene->music->damage);
    if (y == 9)
        sfMusic_play(scene->music->damage2);
    if (y == 9)
        sfMusic_play(scene->music->damage3);
    return (0);
}
