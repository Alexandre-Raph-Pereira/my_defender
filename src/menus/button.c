/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** button
*/

#include "prototype.h"

void disp_button(scene_t *scene)
{
    but_s **button = scene->button;
    int i = 0;

    while (button[i] != NULL) {
        sfRenderWindow_drawRectangleShape(scene->window,
                                          button[i]->but, NULL);
        sfRenderWindow_drawSprite(scene->window, button[i]->sprite, NULL);
        sfRenderWindow_drawText(scene->window, button[i]->info.cost, NULL);
        sfRenderWindow_drawText(scene->window, button[i]->info.damage, NULL);
        sfRenderWindow_drawText(scene->window, button[i]->info.reload_time,
                                NULL);
        sfRenderWindow_drawText(scene->window, button[i]->info.slow, NULL);
        sfRenderWindow_drawText(scene->window, button[i]->info.zone, NULL);
        i++;
    }
}
