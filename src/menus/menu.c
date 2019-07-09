/*
** EPITECH PROJECT, 2019
** Tower Defense
** File description:
** Menu file
*/

#include "prototype.h"

void disp_menu(scene_t *scene)
{
    int i = 0;

    sfRenderWindow_clear(scene->window, sfBlack);
    while (scene->button[i] != NULL) {
        sfRenderWindow_drawRectangleShape(scene->window,
                                          scene->button[i]->but, NULL);
        i++;
    }
    sfRenderWindow_display(scene->window);
}

void screenevent(sfEvent *event, scene_t *scene, int *gamemode)
{
    sfVector2i mouse;

    if (event->type == sfEvtMouseButtonPressed) {
        mouse = sfMouse_getPositionRenderWindow(scene->window);
        check_move(scene);
        if (button_is_clicked(scene->button[0]->but, mouse) == 0) {
            sfRectangleShape_setOutlineColor(scene->button[0]->but, sfBlue);
            (*gamemode) = 1;
        }
        if (button_is_clicked(scene->button[2]->but, mouse) == 0)
            *gamemode = how_to_play_gestion(scene);
        if (button_is_clicked(scene->button[1]->but, mouse) == 0) {
            (*gamemode) = 3;
        }
    }
    if (event->type == sfEvtClosed)
        *gamemode = 3;
}

int init_menu_scene(scene_t *scene)
{
    scene->button = malloc(sizeof(but_s) * 4);
    if (scene->button == NULL)
        return (84);
    scene->button[0] = malloc(sizeof(but_s));
    scene->button[1] = malloc(sizeof(but_s));
    scene->button[2] = malloc(sizeof(but_s));
    scene->button[3] = NULL;
    if (scene->button[0] == NULL || scene->button[1] == NULL ||
        scene->button[2] == NULL)
        return (84);
    init_start_button(scene->button[0]);
    init_end_button(scene->button[1]);
    init_how_to_play_button(scene->button[2]);
    scene->perso = NULL;
    return (0);
}

void destroy_menu(scene_t *scene)
{
    int i = 0;

    while (scene->button[i] != NULL) {
        sfRectangleShape_destroy(scene->button[i]->but);
        free(scene->button[i]);
        i++;
    }
    free(scene->button);
    sfRenderWindow_close(scene->window);
}

int mainscreen(int *gamemode)
{
    scene_t scene;
    sfEvent click;
    int a = 0;

    scene.window = createmywindow(1920, 1080);
    *gamemode = init_menu_scene(&scene);
    if (*gamemode == 84)
        return (84);
    while (sfRenderWindow_isOpen(scene.window) && *gamemode == 0) {
        disp_menu(&scene);
        cond_mouse(&scene);
        while (sfRenderWindow_pollEvent(scene.window, &click)) {
            screenevent(&click, &scene, gamemode);
        }
    }
    destroy_menu(&scene);
    return (0);
}