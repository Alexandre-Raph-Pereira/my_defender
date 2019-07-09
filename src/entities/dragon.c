/*
** EPITECH PROJECT, 2019
** My Defender
** File description:
** dragon type
*/

#include "prototype.h"

int dark_d(scene_t *scene, ennemi_t *ennemi, sfVector2f pos)
{
    sfVector2f scale;

    ennemi->life = 500;
    ennemi->type = 4;
    scale.x = 2;
    scale.y = 2;
    ennemi->next = NULL;
    ennemi->rect.top = 193;
    ennemi->rect.left = 0;
    ennemi->rect.width = 32;
    ennemi->rect.height = 30;
    init_char_enn(ennemi);
    sfSprite_setPosition(ennemi->sprite, pos);
    sfSprite_setScale(ennemi->sprite, scale);
    create_life(ennemi, pos, 100, 10);
    return (0);
}

int light_d(scene_t *scene, ennemi_t *ennemi, sfVector2f pos)
{
    sfVector2f scale;

    ennemi->life = 300;
    ennemi->type = 3;
    scale.x = 2;
    scale.y = 2;
    ennemi->next = NULL;
    ennemi->rect.top = 193;
    ennemi->rect.left = 95;
    ennemi->rect.width = 32;
    ennemi->rect.height = 30;
    init_char_enn(ennemi);
    sfSprite_setPosition(ennemi->sprite, pos);
    sfSprite_setScale(ennemi->sprite, scale);
    create_life(ennemi, pos, 100, 10);
    return (0);
}

int blue_d(scene_t *scene, ennemi_t *ennemi, sfVector2f pos)
{
    sfVector2f scale;

    ennemi->life = 100;
    ennemi->type = 2;
    scale.x = 2;
    scale.y = 2;
    ennemi->next = NULL;
    ennemi->rect.top = 67;
    ennemi->rect.left = 95;
    ennemi->rect.width = 32;
    ennemi->rect.height = 30;
    init_char_enn(ennemi);
    sfSprite_setPosition(ennemi->sprite, pos);
    sfSprite_setScale(ennemi->sprite, scale);
    create_life(ennemi, pos, 100, 10);
    return (0);
}

int red_d(scene_t *scene, ennemi_t *ennemi, sfVector2f pos)
{
    sfVector2f scale;

    ennemi->type = 1;
    ennemi->life = 100;
    scale.x = 2;
    scale.y = 2;
    ennemi->next = NULL;
    ennemi->rect.top = 67;
    ennemi->rect.left = 287;
    ennemi->rect.width = 32;
    ennemi->rect.height = 30;
    init_char_enn(ennemi);
    sfSprite_setPosition(ennemi->sprite, pos);
    sfSprite_setScale(ennemi->sprite, scale);
    create_life(ennemi, pos, 100, 10);
    return (0);
}

int ennemi_type(scene_t *scene, ennemi_t *ennemi, sfVector2f pos)
{
    int p = r_number(scene, 100);

    if (p < 40)
        red_d(scene, ennemi, pos);
    if (p > 40 && p < 80)
        blue_d(scene, ennemi, pos);
    if (p > 80 && p < 95)
        light_d(scene, ennemi, pos);
    if (p > 95)
        dark_d(scene, ennemi, pos);
    return (0);
}
