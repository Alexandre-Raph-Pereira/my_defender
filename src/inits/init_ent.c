/*
** EPITECH PROJECT, 2019
** Tower Defense
** File description:
** Initialisation
*/

#include "prototype.h"

int map(ent_t *back)
{
    back->texture = sfTexture_createFromFile("assets/tmp.png", NULL);
    back->sprite = sfSprite_create();
    back->rect.top = 0;
    back->rect.left = 0;
    back->rect.width = 1920;
    back->rect.height = 1080;
    back->pos.x = 0;
    back->pos.y = 0;
    back->size.x = 2.6;
    back->size.y = 2.6;
    sfSprite_setScale(back->sprite, back->size);
    sfSprite_setPosition(back->sprite, back->pos);
    sfSprite_setTexture(back->sprite, back->texture, sfFalse);
    sfSprite_setTextureRect(back->sprite, back->rect);
    return (0);
}

int text_init(strct *strct)
{
    strct->money.var = 1;
    strct->score.var = 1;
    strct->money.str = malloc(sizeof(char) * 15);
    strct->score.str = malloc(sizeof(char) * 15);
    strct->money.txt = sfText_create();
    strct->score.txt = sfText_create();
    strct->money.font = sfFont_createFromFile("assets/info.ttf");
    strct->score.font = sfFont_createFromFile("assets/info.ttf");
    sfText_setFont(strct->money.txt, strct->money.font);
    sfText_setFont(strct->score.txt, strct->score.font);
}
