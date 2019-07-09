/*
** EPITECH PROJECT, 2019
** clone_def3
** File description:
** for_norm2
*/

#include "prototype.h"

void move_clock_ennemi(scene_t *scene)
{
    if (scene->perso->is_shot == 1)
        sfSprite_move(scene->perso->sprite_bullet, scene->perso->bullet_speed);
    sfClock_restart(scene->perso->bullet_clock.clock);
}