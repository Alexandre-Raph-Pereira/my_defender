/*
** EPITECH PROJECT, 2019
** clone_def3
** File description:
** init_loose
*/

#include "prototype.h"

int what_button_is_clicked(but_s **button, sfVector2i mouse)
{
    int i = 0;

    while (button[i] != NULL) {
        if (button_is_clicked(button[i]->but, mouse) == 0)
            return (i + 1);
        i++;
    }
    return (0);
}

void init_restart_button(but_s*button)
{
    sfVector2f pos;
    sfVector2f size;
    sfTexture *start = sfTexture_createFromFile("assets/restart.png", NULL);

    pos.x = 773;
    pos.y = 300;
    size.x = 400;
    size.y = 40;
    button->is_clicked = 0;
    button->but = sfRectangleShape_create();
    sfRectangleShape_setOutlineColor(button->but, sfRed);
    sfRectangleShape_setOutlineThickness(button->but, 5);
    sfRectangleShape_setFillColor(button->but, sfWhite);
    sfRectangleShape_setSize(button->but, size);
    sfRectangleShape_setPosition(button->but, pos);
    sfRectangleShape_setTexture(button->but, start, sfFalse);
}

void init_menu_button(but_s *button)
{
    sfVector2f pos;
    sfVector2f size;
    sfTexture *start = sfTexture_createFromFile("assets/screen.png", NULL);

    pos.x = 773;
    pos.y = 500;
    size.x = 400;
    size.y = 40;
    button->is_clicked = 0;
    button->but = sfRectangleShape_create();
    sfRectangleShape_setOutlineColor(button->but, sfRed);
    sfRectangleShape_setOutlineThickness(button->but, 5);
    sfRectangleShape_setFillColor(button->but, sfWhite);
    sfRectangleShape_setSize(button->but, size);
    sfRectangleShape_setPosition(button->but, pos);
    sfRectangleShape_setTexture(button->but, start, sfFalse);
}

void cond_button_loose(but_s **button, scene_t *scene)
{
    int i = 0;

    while (button[i] != NULL) {
        if (button_is_clicked(button[i]->but,
                              sfMouse_getPositionRenderWindow
                              (scene->window)) == 0 &&
            scene->button[i]->is_clicked == 0)
            sfRectangleShape_setOutlineColor(button[i]->but, sfWhite);
        else if (scene->button[i]->is_clicked == 0)
            sfRectangleShape_setOutlineColor(button[i]->but, sfRed);
        i++;
    }
}
