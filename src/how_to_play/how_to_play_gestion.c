/*
** EPITECH PROJECT, 2019
** clone_def3
** File description:
** how_to_play_gestion
*/

#include "prototype.h"

void create_done_button(but_s *button)
{
    sfVector2f pos;
    sfVector2f size;
    sfTexture *start = sfTexture_createFromFile("assets/done.png", NULL);

    pos.x = 773;
    pos.y = 800;
    size.x = 800;
    size.y = 80;
    button->is_clicked = 0;
    button->but = sfRectangleShape_create();
    sfRectangleShape_setOutlineColor(button->but, sfRed);
    sfRectangleShape_setOutlineThickness(button->but, 5);
    sfRectangleShape_setFillColor(button->but, sfWhite);
    sfRectangleShape_setSize(button->but, size);
    sfRectangleShape_setPosition(button->but, pos);
    sfRectangleShape_setTexture(button->but, start, sfFalse);
}

int how_to_play_event(sfEvent *event, scene_t *scene, but_s *button)
{
    sfVector2i mouse;

    if (event->type == sfEvtMouseButtonPressed) {
        mouse = sfMouse_getPositionRenderWindow(scene->window);
        if (button_is_clicked(button->but, mouse) == 0)
            return (1);
    }
    if (event->type == sfEvtClosed)
        return (3);
    return (0);
}

void display_how_to_play(scene_t *scene, sfSprite *sprite, but_s button)
{
    sfRenderWindow_clear(scene->window, sfBlack);
    sfRenderWindow_drawSprite(scene->window, sprite, NULL);
    sfRenderWindow_drawRectangleShape(scene->window, button.but, NULL);
    sfRenderWindow_display(scene->window);
}

int how_to_play_gestion(scene_t *scene)
{
    but_s button;
    sfTexture *texture = sfTexture_createFromFile("assets/descrip.png", NULL);
    sfSprite *sprite = sfSprite_create();
    sfEvent event;
    int i = 0;

    create_done_button(&button);
    sfSprite_setTexture(sprite, texture, sfTrue);
    while (i == 0) {
        display_how_to_play(scene, sprite, button);
        cond_how_to_play(scene, &button);
        while (sfRenderWindow_pollEvent(scene->window, &event)) {
            i = how_to_play_event(&event, scene, &button);
        }
    }
    if (i == 1)
        return (0);
    return (i);
}