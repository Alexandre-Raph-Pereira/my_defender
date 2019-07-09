/*
** EPITECH PROJECT, 2019
** clone_def3
** File description:
** how_to_play
*/

#include "prototype.h"

void cond_how_to_play(scene_t *scene, but_s *button)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(scene->window);

    if (button_is_clicked(button->but, mouse) == 0)
        sfRectangleShape_setOutlineColor(button->but, sfWhite);
    else
        sfRectangleShape_setOutlineColor(button->but, sfRed);
}

int init_how_to_play_button(but_s *button)
{
    sfVector2f pos;
    sfVector2f size;
    sfTexture *start = sfTexture_createFromFile("assets/htp.png", NULL);

    pos.x = 765;
    pos.y = 300;
    size.x = 400;
    size.y = 37;
    button->is_clicked = 0;
    button->but = sfRectangleShape_create();
    sfRectangleShape_setOutlineColor(button->but, sfRed);
    sfRectangleShape_setOutlineThickness(button->but, 5);
    sfRectangleShape_setFillColor(button->but, sfWhite);
    sfRectangleShape_setSize(button->but, size);
    sfRectangleShape_setPosition(button->but, pos);
    sfRectangleShape_setTexture(button->but, start, sfFalse);
    return (1);
}
