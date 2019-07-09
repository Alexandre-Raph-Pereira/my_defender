/*
** EPITECH PROJECT, 2019
** shot.c
** File description:
** shot
*/

#include "prototype.h"

int is_in_circle(sfVector2f pos_enn, sfVector2f pos_tow)
{
    if ((pos_tow.x - 150 > pos_enn.x && pos_tow.x - 150 > pos_enn.x + 30)
        || (pos_tow.x + 150 < pos_enn.x))
        return (0);
    if ((pos_tow.y - 150 > pos_enn.y && pos_tow.y - 150 > pos_enn.y + 66)
        || (pos_tow.y + 150 < pos_enn.y))
        return (0);
    return (1);
}

void find_who_shot(sfVector2f pos_tow, scene_t *scene, sfFloatRect rect_tow)
{
    ennemi_t *enn = scene->ennemi;
    sfVector2f pos_enn;
    sfFloatRect rect_enn;

    scene->perso->rel.time = sfClock_getElapsedTime(scene->perso->rel.clock);
    scene->perso->rel.second = scene->perso->rel.time.microseconds / 1000000.0;
    while (scene->ennemi != NULL && scene->ennemi->sprite != NULL) {
        rect_enn = sfSprite_getGlobalBounds(scene->ennemi->sprite);
        pos_enn = sfSprite_getPosition(scene->ennemi->sprite);
        if (scene->perso->rel.second > scene->perso->damage.reload &&
            sfFloatRect_intersects(&rect_enn, &rect_tow, NULL) == sfTrue) {
            scene->perso->bullet_speed.x = ((pos_enn.x + 25) - pos_tow.x) / 5;
            scene->perso->bullet_speed.y = ((pos_enn.y + 25) - pos_tow.y) / 5;
            scene->perso->is_shot = 1;
            scene->ennemi = enn;
            return;
        } else
            scene->perso->is_shot = 0;
        scene->ennemi = scene->ennemi->next;
    }
    scene->ennemi = enn;
}

int find_ennemis(scene_t *scene)
{
    obj_t *tower = scene->perso;
    sfVector2f pos_tow;
    sfFloatRect rect_tow;

    while (scene->perso != NULL) {
        rect_tow = sfCircleShape_getGlobalBounds(scene->perso->zone);
        pos_tow = sfSprite_getPosition(scene->perso->sprite_perso);
        if (scene->perso->is_drag != 1)
            find_who_shot(pos_tow, scene, rect_tow);
        scene->perso = scene->perso->next;
    }
    scene->perso = tower;
    return (0);
}
