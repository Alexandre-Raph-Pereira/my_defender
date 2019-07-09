/*
** EPITECH PROJECT, 2019
** ennemie.c
** File description:
** ennemie
*/

#include "prototype.h"

void disp_ennemi(scene_t *scene)
{
    ennemi_t *enn = scene->ennemi;

    while (enn != NULL && enn->sprite != NULL) {
        sfRenderWindow_drawSprite(scene->window, enn->sprite, NULL);
        sfRenderWindow_drawRectangleShape(scene->window, enn->life_r, NULL);
        sfRenderWindow_drawRectangleShape(scene->window, enn->life_g, NULL);
        enn = enn->next;
    }
}

void init_char_enn(ennemi_t *ennemi)
{
    ennemi->texture = sfTexture_createFromFile("assets/dragon.png", NULL);
    ennemi->sprite = sfSprite_create();
    sfSprite_setTexture(ennemi->sprite, ennemi->texture, sfTrue);
    sfSprite_setTextureRect(ennemi->sprite, ennemi->rect);
}

void create_life(ennemi_t *ennemi, sfVector2f pos, int x, int y)
{
    sfVector2f size;

    size.x = x;
    size.y = y;
    pos.y = pos.y - y - 10;
    ennemi->life_r = sfRectangleShape_create();
    sfRectangleShape_setOutlineColor(ennemi->life_r, sfTransparent);
    sfRectangleShape_setOutlineThickness(ennemi->life_r, 0);
    sfRectangleShape_setFillColor(ennemi->life_r, sfRed);
    sfRectangleShape_setSize(ennemi->life_r, size);
    sfRectangleShape_setPosition(ennemi->life_r, pos);
    ennemi->life_g = sfRectangleShape_create();
    sfRectangleShape_setOutlineColor(ennemi->life_g, sfTransparent);
    sfRectangleShape_setOutlineThickness(ennemi->life_g, 0);
    sfRectangleShape_setFillColor(ennemi->life_g, sfGreen);
    sfRectangleShape_setSize(ennemi->life_g, size);
    sfRectangleShape_setPosition(ennemi->life_g, pos);
    ennemi->is_zoned = 0;
    ennemi->is_slowed = 0;
}

int init_ennemi(scene_t *scene)
{
    ennemi_t *ennemi = malloc(sizeof(ennemi_t) * 2);
    ennemi_t *list_enn = scene->ennemi;
    sfVector2f pos;

    if (ennemi == NULL)
        return (84);
    memset(ennemi, 0, sizeof(ennemi_t) * 2);
    pos.x = -50;
    pos.y = 515 + r_number(scene, 500);
    ennemi->clock = sfClock_create();
    red_d(scene, ennemi, pos);
    ennemi->next_check = scene->checkpoint;
    if (scene->ennemi != NULL) {
        while (scene->ennemi->next != NULL)
            scene->ennemi = scene->ennemi->next;
        scene->ennemi->next = ennemi;
        scene->ennemi = list_enn;
    }
    else {
        ennemi->next = scene->ennemi;
        scene->ennemi = ennemi;
    }
    return (0);
}

int nbr_ennemi(scene_t *scene)
{
    int r = 0;

    scene->times = sfClock_getElapsedTime(scene->clocks);
    if (scene->times.microseconds >= 2000000) {
        if (init_ennemi(scene) == 84)
            return (84);
        scene->times = sfClock_getElapsedTime(scene->clocks);
        sfClock_restart(scene->clocks);
        return (1);
    }
    return (0);
}
