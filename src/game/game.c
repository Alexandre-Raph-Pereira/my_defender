/*
** EPITECH PROJECT, 2019
** Tower Defense
** File description:
** Game Loop
*/

#include "prototype.h"

void dips_tower(scene_t *scene)
{
    obj_t *head = scene->perso;

    while (head != NULL) {
        sfRenderWindow_drawSprite(scene->window, head->sprite_perso, NULL);
        sfRenderWindow_drawCircleShape(scene->window, head->zone, NULL);
        if (head->up.is_clicked == 1) {
            sfRenderWindow_drawRectangleShape(scene->window,
                                              head->up.but, NULL);
            sfRenderWindow_drawSprite(scene->window, head->up.sprite, NULL);
        }
        if (head->is_shot == 1)
            sfRenderWindow_drawSprite(scene->window, head->sprite_bullet, NULL);
        head = head->next;
    }
}

void disp_scene(scene_t *scene)
{
    check_t *check = scene->checkpoint;
    but_s *pos = scene->pos_tow;

    sfRenderWindow_drawSprite(scene->window, scene->fond.sprite, NULL);
    sfRenderWindow_drawSprite(scene->window, scene->castle.sprite, NULL);
    sfRenderWindow_drawRectangleShape(scene->window, scene->castle.life_r,
                                      NULL);
    sfRenderWindow_drawRectangleShape(scene->window, scene->castle.life_g,
                                      NULL);
    disp_button(scene);
    dips_tower(scene);
    disp_ennemi(scene);
}

int loop_function(scene_t *scene, timer *clock_castle)
{
    if (waves(scene) == 84)
        return (84);
    move_icon(scene);
    move_ennemis(scene);
    find_ennemis(scene);
    button_disp(scene);
    castle_damage(scene, clock_castle);
    return (1);
}

void game(int *gamemode)
{
    strct strct;
    sfEvent event;
    scene_t scene;
    pause_s pause;
    timer clock_castle;

    *gamemode = init_all(&scene, &strct, &pause, &clock_castle);
    sfMusic_play(scene.music->music);
    while (sfRenderWindow_isOpen(scene.window) && *gamemode == 1
           && castle_life(&scene) == 1) {
        sfRenderWindow_clear(scene.window, sfBlack);
        disp_scene(&scene);
        stats(&scene, &strct, scene.window);
        *gamemode = loop_function(&scene, &clock_castle);
        movement(&strct, &scene);
        while (sfRenderWindow_pollEvent(scene.window, &event))
            *gamemode = allevent(&scene, &event, &strct, &pause);
    } if (castle_life(&scene) != 1)
          *gamemode = disp_loose(&scene);
    close_window(&scene, &strct, &pause);
}
