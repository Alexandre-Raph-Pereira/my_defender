/*
** EPITECH PROJECT, 2019
** clone_def3
** File description:
** for_norm
*/

#include "prototype.h"

void set_zone_scene(sfFloatRect *enn_rect, sfVector2f *life, scene_t *scene) 
{
    *enn_rect = sfSprite_getGlobalBounds(scene->ennemi->sprite);
    *life = sfRectangleShape_getSize(scene->ennemi->life_g);
}

void set_zone_zone_enn(int *i, sfVector2f *pos_enn_zone, ennemi_t *zoned_ennemi)
{
    *i = zoned_ennemi->is_zoned;
    *pos_enn_zone = sfSprite_getPosition(zoned_ennemi->sprite);
}

void restart_bullet(scene_t *scene, ennemi_t *ennemie, ennemi_t *temp_enn)
{
    sfVector2f pos_tow;

    pos_tow = sfSprite_getPosition(scene->perso->sprite_perso);
    sfSprite_setPosition(scene->perso->sprite_bullet, pos_tow);
    sfClock_restart(scene->perso->rel.clock);
    scene->ennemi = ennemie;
}

sfVector2f convert_mouse(sfVector2i mouse)
{
    sfVector2f mouse_pos;

    mouse_pos.x = mouse.x;
    mouse_pos.y = mouse.y;
}