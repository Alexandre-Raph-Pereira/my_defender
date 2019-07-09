/*
** EPITECH PROJECT, 2019
** Tower Defense
** File description:
** Animation for sprites
*/

#include "prototype.h"

int animation(scene_t *scene)
{
    ennemi_t *enn = scene->ennemi;

    anim_pos(scene);
    scene->ennemi = enn;
}

void fire(scene_t *scene)
{
    obj_t *tower = scene->perso;

    while (scene->perso != NULL) {
        scene->perso->bullet_clock.time = sfClock_getElapsedTime(
            scene->perso->bullet_clock.clock);
        scene->perso->bullet_clock.second =
            scene->perso->bullet_clock.time.microseconds / 1000000.0;
        if (scene->perso->bullet_clock.second > 0.01) {
            move_clock_ennemi(scene);
        }
        scene->perso = scene->perso->next;
    }
    scene->perso = tower;
}

int movement(strct *strct, scene_t *scene)
{
    clockelapsed(strct, 3);
    if (strct->timer[1].time.microseconds > 105000) {
        animation(scene);
        sfClock_restart(strct->timer[1].clock);
    }
    fire(scene);
    check_impact(scene, strct);
    return (0);
}
