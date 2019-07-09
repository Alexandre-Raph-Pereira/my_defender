/*
** EPITECH PROJECT, 2019
** clone_def3
** File description:
** loose
*/

#include "prototype.h"

int loose_event(but_s **button, scene_t *scene, sfEvent *event)
{
    sfVector2i mouse;

    if (event->type == sfEvtMouseButtonPressed) {
        mouse = sfMouse_getPositionRenderWindow(scene->window);
        return (what_button_is_clicked(button, mouse));
    }
    if (event->type == sfEvtClosed)
        return (3);
    return (0);
}

but_s **create_loose_button(but_s **button)
{
    button[0] = malloc(sizeof(but_s));
    button[1] = malloc(sizeof(but_s));
    button[2] = malloc(sizeof(but_s));
    button[3] = NULL;
    if (button[0] == NULL || button[1] == NULL ||
        button[2] == NULL)
        return (NULL);
    init_restart_button(button[0]);
    init_menu_button(button[1]);
    init_end_button(button[2]);
    return (button);
}

void disp_loose_button(but_s **button, scene_t *scene, sfSprite *sprite)
{
    int i = 0;

    sfRenderWindow_clear(scene->window, sfBlack);
    sfRenderWindow_drawSprite(scene->window, sprite, NULL);
    while (button[i] != NULL) {
        sfRenderWindow_drawRectangleShape(scene->window, button[i]->but, NULL);
        i++;
    }
    sfRenderWindow_display(scene->window);
}

void destroy_loose(but_s **button, sfSprite *sprite, sfTexture *texture)
{
    int i = 0;

    while (button[i] != NULL) {
        sfRectangleShape_destroy(button[i]->but);
        free(button[i]);
        i++;
    }
    free(button);
    sfTexture_destroy(texture);
    sfSprite_destroy(sprite);
}

int disp_loose(scene_t *scene)
{
    sfTexture *texture = sfTexture_createFromFile("assets/end.png", NULL);
    sfSprite *sprite = sfSprite_create();
    sfEvent event;
    but_s **button = malloc(sizeof(but_s *) * 4);;
    int i = 0;

    if (button == NULL)
        return (84);
    if (create_loose_button(button) == NULL)
        return (84);
    sfSprite_setTexture(sprite, texture, sfTrue);
    while (i == 0) {
        disp_loose_button(button, scene, sprite);
        cond_button_loose(button, scene);
        while (sfRenderWindow_pollEvent(scene->window, &event))
            i = loose_event(button, scene, &event);
    }
    destroy_loose(button, sprite, texture);
    return (i);
}
