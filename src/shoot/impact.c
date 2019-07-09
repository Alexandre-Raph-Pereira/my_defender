/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** impact
*/

#include "prototype.h"

void modif_life(scene_t *scene, ennemi_t *temp_enn)
{
    sfVector2f size = sfRectangleShape_getSize(scene->ennemi->life_g);

    damage_r(scene);
    if (size.x > 0) {
        size.x = size.x - scene->perso->damage.dam;
        sfRectangleShape_setSize(scene->ennemi->life_g, size);
    }
    if (scene->perso->damage.slow > 1)
        scene->ennemi->is_slowed = scene->perso->damage.slow;
    if (scene->perso->damage.zone != 0)
        scene->ennemi->is_zoned = scene->perso->damage.zone;
}

int check_bullet(sfFloatRect bullet, scene_t *scene)
{
    ennemi_t *ennemie = scene->ennemi;
    ennemi_t *temp_enn = scene->ennemi;
    sfFloatRect enn;

    while (scene->ennemi != NULL && scene->ennemi->sprite != NULL) {
        enn = sfSprite_getGlobalBounds(scene->ennemi->sprite);
        if (sfFloatRect_intersects(&enn, &bullet, NULL) == sfTrue) {
            modif_life(scene, temp_enn);
            restart_bullet(scene, ennemie, temp_enn);
            return (1);
        }
        if (bullet.top < 0 || bullet.top > 1080 || bullet.left < 0
            || bullet.left > 1920) {
            restart_bullet(scene, ennemie, temp_enn);
            return (0);
        }
        scene->ennemi = scene->ennemi->next;
    }
    scene->ennemi = ennemie;
    return (0);
}

void remove_ennemie(ennemi_t *enn_to_rm, ennemi_t *ennemie, strct *strct)
{
    ennemi_t *prev_enn = ennemie;

    while (prev_enn->next != enn_to_rm) {
        prev_enn = ennemie;
        ennemie = ennemie->next;
    }
    prev_enn->next = prev_enn->next->next;
    strct->money.var = strct->money.var + 5;
}

void check_dead(scene_t *scene, strct *strct)
{
    ennemi_t *ennemie = scene->ennemi;
    ennemi_t *list_enn = scene->ennemi;
    sfVector2f life;

    while (ennemie != NULL) {
        life = sfRectangleShape_getSize(ennemie->life_g);
        if (life.x <= 0 && ennemie == scene->ennemi) {
            scene->ennemi = scene->ennemi->next;
            strct->money.var = strct->money.var + 5;
            strct->score.var++;
        }
        else if (life.x <= 0) {
            remove_ennemie(ennemie, scene->ennemi, strct);
        }
        ennemie = ennemie->next;
    }
}

void check_impact(scene_t *scene, strct *strct)
{
    obj_t *tower = scene->perso;
    ennemi_t *ennemie = scene->ennemi;
    sfFloatRect bullet;
    sfFloatRect enn;

    while (scene->perso != NULL) {
        bullet = sfSprite_getGlobalBounds(scene->perso->sprite_bullet);
        if (check_bullet(bullet, scene) == 1)
            check_explosion(scene);
        scene->perso = scene->perso->next;
    }
    check_dead(scene, strct);
    scene->perso = tower;
}
