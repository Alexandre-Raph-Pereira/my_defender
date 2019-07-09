/*
** EPITECH PROJECT, 2019
** Tower Defense
** File description:
** Event gestion
*/

#include "prototype.h"

int button_click(scene_t *scene, sfVector2i mouse, strct *strct)
{
    int i = 0;

    while (scene->button[i] != NULL) {
        if (button_is_clicked(scene->button[i]->but, mouse) == 0) {
            scene->button[i]->is_clicked = 1;
            add_ruby(scene, i, strct);
            return (1);
        }
        i++;
    }
    return (0);
}

void reboot(scene_t *scene)
{
    int i = 0;

    while (scene->button[i] != NULL) {
        scene->button[i]->is_clicked = 0;
        i++;
    }
}

int allevent(scene_t *scene, sfEvent *event, strct *strct, pause_s *pause)
{
    sfVector2i mouse;

    if (event->type == sfEvtMouseButtonPressed) {
        mouse = sfMouse_getPositionRenderWindow(scene->window);
        if (button_click(scene, mouse, strct) == 1)
            return (1);
        if (upgrade(scene, mouse, strct) == 1)
            return (1);
    }
    if (event->type == sfEvtMouseButtonReleased) {
        reboot(scene);
        find_released(scene, strct);
    }
    if (event->key.code == sfKeyEscape)
        return (pause_function(scene, pause));
    if (event->type == sfEvtClosed)
        return (3);
    return (1);
}
