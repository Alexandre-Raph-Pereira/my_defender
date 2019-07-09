/*
** EPITECH PROJECT, 2019
** init_button.c
** File description:
** init_button
*/

#include "prototype.h"

sfIntRect create_char_rect(int x, int y, int width, int height)
{
    sfIntRect char_rec;

    char_rec.left = x;
    char_rec.top = y;
    char_rec.width = width;
    char_rec.height = height;
    return (char_rec);
}

int init_button(scene_t *scene)
{
    scene->button = malloc(sizeof(but_s *) * 5);

    if (scene->button == NULL)
        return (84);
    scene->button[0] = malloc(sizeof(but_s));
    scene->button[1] = malloc(sizeof(but_s));
    scene->button[2] = malloc(sizeof(but_s));
    scene->button[3] = malloc(sizeof(but_s));
    scene->button[4] = NULL;
    if (scene->button[0] == NULL || scene->button[1] == NULL ||
        scene->button[2] == NULL || scene->button[3] == NULL)
        return (84);
    create_button1(scene->button[0]);
    create_button2(scene->button[1]);
    create_button3(scene->button[2]);
    create_button4(scene->button[3]);
    return (0);
}
