/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** upgrade
*/

#include "prototype.h"

void add_txt(obj_t **tower)
{
    char *str = NULL;
    sfVector2f up_sq = sfRectangleShape_getPosition((*tower)->up.but);
    sfFont *font = sfFont_createFromFile("./assets/info.ttf");

    up_sq.x = up_sq.x + 50;
    str = int_to_char((*tower)->damage.cost, str);
    (*tower)->up.txt = sfText_create();
    sfText_setString((*tower)->up.txt, str);
    sfText_setFont((*tower)->up.txt, font);
    sfText_setPosition((*tower)->up.txt, up_sq);
    sfText_setColor((*tower)->up.txt, sfRed);
    sfText_setCharacterSize((*tower)->up.txt, 20);
    free(str);
}

void pos_up(obj_t *tower, sfVector2f tow, sfFloatRect pos_tow)
{
    if (tower->up.is_clicked == 1)
        tower->up.is_clicked = 0;
    else
        tower->up.is_clicked = 1;
    tow.x = pos_tow.left;
    tow.y = pos_tow.top - 35;
    sfRectangleShape_setPosition(tower->up.but, tow);
    sfSprite_setPosition(tower->up.sprite, tow);
}

void up1(obj_t *tower, sfFloatRect pos_tow, sfVector2i mouse, strct *strct)
{
    if (mouse.x > pos_tow.left && mouse.x <= pos_tow.left + 35 &&
        mouse.y > pos_tow.top - 35 && mouse.y <= pos_tow.top
        && tower->nb_tow == 0 && tower->nb_up < 3 &&
        strct->money.var > tower->damage.cost) {
        strct->money.var = strct->money.var - tower->damage.cost;
        tower->char_rect.left = tower->char_rect.left + 105;
        sfSprite_setTextureRect(tower->sprite_perso, tower->char_rect);
        tower->nb_up++;
        up_tower1(tower);
    }
    if (mouse.x > pos_tow.left && mouse.x <= pos_tow.left + 35 &&
        mouse.y > pos_tow.top - 35 && mouse.y <= pos_tow.top
        && tower->nb_tow == 1 && tower->nb_up < 3 &&
        strct->money.var > tower->damage.cost) {
        strct->money.var = strct->money.var - tower->damage.cost;
        tower->char_rect.left = tower->char_rect.left + 100;
        sfSprite_setTextureRect(tower->sprite_perso, tower->char_rect);
        tower->nb_up++;
        up_tower2(tower);
    }
}

void up2(obj_t *tower, sfFloatRect pos_tow, sfVector2i mouse, strct *strct)
{
    if (mouse.x > pos_tow.left && mouse.x <= pos_tow.left + 35 &&
        mouse.y > pos_tow.top - 35 && mouse.y <= pos_tow.top
        && tower->nb_tow == 2 && tower->nb_up < 3 &&
        strct->money.var > tower->damage.cost) {
        strct->money.var = strct->money.var - tower->damage.cost;
        tower->char_rect.left = tower->char_rect.left + 104;
        sfSprite_setTextureRect(tower->sprite_perso, tower->char_rect);
        tower->nb_up++;
        up_tower3(tower);
    }
    if (mouse.x > pos_tow.left && mouse.x <= pos_tow.left + 35 &&
        mouse.y > pos_tow.top - 35 && mouse.y <= pos_tow.top
        && tower->nb_tow == 3 && tower->nb_up < 3 &&
        strct->money.var > tower->damage.cost) {
        strct->money.var = strct->money.var - tower->damage.cost;
        tower->char_rect.left = tower->char_rect.left + 100;
        sfSprite_setTextureRect(tower->sprite_perso, tower->char_rect);
        tower->nb_up++;
        up_tower4(tower);
    }
}

int upgrade(scene_t *scene, sfVector2i mouse, strct *strct)
{
    obj_t *tower = scene->perso;
    sfFloatRect pos_tow;
    sfVector2f tow;

    while (scene->perso != NULL) {
        pos_tow = sfSprite_getGlobalBounds(scene->perso->sprite_perso);
        up1(scene->perso, pos_tow, mouse, strct);
        up2(scene->perso, pos_tow, mouse, strct);
        if (mouse.x > pos_tow.left && mouse.x <= pos_tow.left + pos_tow.width
            && mouse.y > pos_tow.top - 35 &&
            mouse.y <= pos_tow.top + pos_tow.height) {
            pos_up(scene->perso, tow, pos_tow);
            scene->perso = tower;
            return (1);
        }
        scene->perso->up.is_clicked = 0;
        scene->perso = scene->perso->next;
    }
    scene->perso = tower;
    return (0);
}
