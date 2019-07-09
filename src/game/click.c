/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** click
*/

#include "prototype.h"

void button_disp(scene_t *scene)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(scene->window);
    int i = 0;

    while (scene->button[i] != NULL) {
        if (button_is_clicked(scene->button[i]->but, mouse) == 0 &&
            scene->button[i]->is_clicked == 0)
            sfRectangleShape_setOutlineColor(scene->button[i]->but, sfWhite);
        else if (scene->button[i]->is_clicked == 1 &&
                 button_is_clicked(scene->button[i]->but, mouse) == 0)
            sfRectangleShape_setOutlineColor(scene->button[i]->but, sfBlue);
        else
            sfRectangleShape_setOutlineColor(scene->button[i]->but, sfRed);
        i ++;
    }
}
