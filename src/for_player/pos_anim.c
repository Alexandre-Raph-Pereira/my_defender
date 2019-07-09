/*
** EPITECH PROJECT, 2019
** My Defender
** File description:
** pos for mouvement
*/

#include "prototype.h"

int anim_red_d(scene_t *scene)
{
    if (scene->ennemi->rect.left < 350)
        scene->ennemi->rect.left += scene->ennemi->rect.width;
    else
        scene->ennemi->rect.left = 287;
    sfSprite_setTexture(scene->ennemi->sprite,
                        scene->ennemi->texture, sfTrue);
    sfSprite_setTextureRect(scene->ennemi->sprite, scene->ennemi->rect);
    return (0);
}

int anim_blue_d(scene_t *scene)
{
    if (scene->ennemi->rect.left < 153)
        scene->ennemi->rect.left += scene->ennemi->rect.width;
    else
        scene->ennemi->rect.left = 95;
    sfSprite_setTexture(scene->ennemi->sprite,
                        scene->ennemi->texture, sfTrue);
    sfSprite_setTextureRect(scene->ennemi->sprite, scene->ennemi->rect);
    return (0);
}

int anim_light_d(scene_t *scene)
{
    if (scene->ennemi->rect.left < 153)
        scene->ennemi->rect.left += scene->ennemi->rect.width;
    else
        scene->ennemi->rect.left = 95;
    sfSprite_setTexture(scene->ennemi->sprite,
                        scene->ennemi->texture, sfTrue);
    sfSprite_setTextureRect(scene->ennemi->sprite, scene->ennemi->rect);
    return (0);
}

int anim_dark_d(scene_t *scene)
{
    if (scene->ennemi->rect.left < 63)
        scene->ennemi->rect.left += scene->ennemi->rect.width;
    else
        scene->ennemi->rect.left = 0;
    sfSprite_setTexture(scene->ennemi->sprite,
                        scene->ennemi->texture, sfTrue);
    sfSprite_setTextureRect(scene->ennemi->sprite, scene->ennemi->rect);
    return (0);
}

int anim_pos(scene_t *scene)
{
    ennemi_t *enn = scene->ennemi;

    while (scene->ennemi != NULL) {
        if (scene->ennemi->type == 4 && scene->ennemi != NULL)
            anim_dark_d(scene);
        if (scene->ennemi->type == 3 && scene->ennemi != NULL)
            anim_light_d(scene);
        if (scene->ennemi->type == 2 && scene->ennemi != NULL)
            anim_blue_d(scene);
        if (scene->ennemi->type == 1 && scene->ennemi != NULL)
            anim_red_d(scene);
        scene->ennemi = scene->ennemi->next;
    }
    scene->ennemi = enn;
    return (0);
}
