/*
** EPITECH PROJECT, 2019
** clone_def3
** File description:
** zone_impact
*/

#include "prototype.h"

int cond_zone(sfFloatRect enn_rect, sfVector2f impact, int i)
{
    if (enn_rect.top < impact.y - i ||
        enn_rect.top > impact.y + i ||
        enn_rect.left < impact.x - i ||
        enn_rect.left > impact.x + i)
        return (0);
    if (enn_rect.top + enn_rect.height < impact.y - i &&
        enn_rect.top + enn_rect.height > impact.y + i &&
        enn_rect.left + enn_rect.width < impact.x - i &&
        enn_rect.left + enn_rect.width > impact.x + i)
        return (0);
    return (1);
}

void check_explosion(scene_t *scene)
{
    ennemi_t *zoned_ennemi = scene->ennemi;
    ennemi_t *enn = scene->ennemi;
    sfFloatRect enn_rect;
    sfVector2f life;
    sfVector2f pos_enn_zone;
    int i = 0;

    while (zoned_ennemi != NULL && zoned_ennemi->is_zoned == 0)
        zoned_ennemi = zoned_ennemi->next;
    while (zoned_ennemi != NULL && scene->ennemi != NULL) {
        set_zone_zone_enn(&i, &pos_enn_zone, zoned_ennemi);
        set_zone_scene(&enn_rect, &life, scene);
        if (scene->ennemi != zoned_ennemi &&
            cond_zone(enn_rect, pos_enn_zone, i) == 1) {
            life.x = life.x - scene->perso->damage.dam;
            sfRectangleShape_setSize(scene->ennemi->life_g, life);
        }
        scene->ennemi = scene->ennemi->next;
    }
    scene->ennemi = enn;
}
