/*
** EPITECH PROJECT, 2019
** checkpoint.c
** File description:
** checkpoint
*/

#include "prototype.h"

void init_char_check(check_t *checkpoint)
{
    checkpoint->rect.top = 18;
    checkpoint->rect.left = 980;
    checkpoint->rect.width = 440;
    checkpoint->rect.height = 440;
}

int init_checkpoint_tower(scene_t *scene)
{
    if (init_pos_check(scene, 345, 340) == 84 ||
        init_pos_check(scene, 345, 500) == 84 ||
        init_pos_check(scene, 632, 520) == 84 ||
        init_pos_check(scene, 795, 520) == 84 ||
        init_pos_check(scene, 735, 740) == 84 ||
        init_pos_check(scene, 1055, 537) == 84 ||
        init_pos_check(scene, 1040, 295) == 84 ||
        init_pos_check(scene, 1405, 537) == 84)
        return (84);
}

int init_pos_check(scene_t *scene, int x, int y)
{
    but_s *checkpoint = malloc(sizeof(but_s));
    sfVector2f pos;
    sfVector2f scale;

    if (checkpoint == NULL)
        return (84);
    pos.x = x;
    pos.y = y;
    scale.x = 100;
    scale.y = 100;
    checkpoint->but = sfRectangleShape_create();
    sfRectangleShape_setOutlineColor(checkpoint->but, sfRed);
    sfRectangleShape_setOutlineThickness(checkpoint->but, 5);
    sfRectangleShape_setFillColor(checkpoint->but, sfTransparent);
    sfRectangleShape_setSize(checkpoint->but, scale);
    sfRectangleShape_setPosition(checkpoint->but, pos);
    checkpoint->next = scene->pos_tow;
    scene->pos_tow = checkpoint;
    return (0);
}

int init_checkpoint(scene_t *scene, int x, int y)
{
    check_t *checkpoint = malloc(sizeof(check_t));
    sfVector2f pos;
    sfVector2f scale;

    if (checkpoint == NULL)
        return (84);
    pos.x = x;
    pos.y = y;
    scale.x = 0.2;
    scale.y = 0.2;
    checkpoint->texture = sfTexture_createFromFile("assets/block.jpg", NULL);
    checkpoint->sprite = sfSprite_create();
    init_char_check(checkpoint);
    sfSprite_setTexture(checkpoint->sprite, checkpoint->texture, sfTrue);
    sfSprite_setTextureRect(checkpoint->sprite, checkpoint->rect);
    sfSprite_setPosition(checkpoint->sprite, pos);
    sfSprite_setScale(checkpoint->sprite, scale);
    checkpoint->next = scene->checkpoint;
    scene->checkpoint = checkpoint;
    return (0);
}
