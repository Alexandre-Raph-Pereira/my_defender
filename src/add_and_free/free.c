/*
** EPITECH PROJECT, 2019
** clone_def3
** File description:
** free
*/

#include "prototype.h"

void free_perso(scene_t *scene)
{
    while (scene->perso != NULL) {
        sfSprite_destroy(scene->perso->sprite_perso);
        sfTexture_destroy(scene->perso->texture);
        sfCircleShape_destroy(scene->perso->zone);
        sfTexture_destroy(scene->perso->texture_bullet);
        sfSprite_destroy(scene->perso->sprite_bullet);
        sfRectangleShape_destroy(scene->perso->up.but);
        sfTexture_destroy(scene->perso->up.texture);
        sfSprite_destroy(scene->perso->up.sprite);
        scene->perso = scene->perso->next;
    }
    free(scene->perso);
}

void free_ennemi(scene_t *scene)
{
    while (scene->ennemi != NULL) {
        sfSprite_destroy(scene->ennemi->sprite);
        sfTexture_destroy(scene->ennemi->texture);
        sfRectangleShape_destroy(scene->ennemi->life_g);
        sfRectangleShape_destroy(scene->ennemi->life_r);
        sfClock_destroy(scene->ennemi->clock);
        scene->ennemi = scene->ennemi->next;
    }
    free(scene->ennemi);
}

void free_button(scene_t *scene)
{
    int i = 0;

    while (scene->button[i] != NULL) {
        sfSprite_destroy(scene->button[i]->sprite);
        sfTexture_destroy(scene->button[i]->texture);
        sfRectangleShape_destroy(scene->button[i]->but);
        sfFont_destroy(scene->button[i]->info.font);
        sfText_destroy(scene->button[i]->info.cost);
        sfText_destroy(scene->button[i]->info.damage);
        sfText_destroy(scene->button[i]->info.slow);
        sfText_destroy(scene->button[i]->info.reload_time);
        sfText_destroy(scene->button[i]->info.zone);
        i++;
    }
    free(scene->button);
}

void free_checkpoint(scene_t *scene)
{
    while (scene->checkpoint != NULL) {
        sfSprite_destroy(scene->checkpoint->sprite);
        sfTexture_destroy(scene->checkpoint->texture);
        scene->checkpoint = scene->checkpoint->next;
    }
    while (scene->pos_tow != NULL) {
        sfRectangleShape_destroy(scene->pos_tow->but);
        scene->pos_tow = scene->pos_tow->next;
    }
}

void free_music(scene_t *scene)
{
    sfMusic_destroy(scene->music->music);
    sfMusic_destroy(scene->music->damage);
    sfMusic_destroy(scene->music->damage2);
    sfMusic_destroy(scene->music->damage3);
    return;
}
