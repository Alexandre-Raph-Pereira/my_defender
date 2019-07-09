/*
** EPITECH PROJECT, 2019
** release.c
** File description:
** release
*/

#include "prototype.h"

int double_pos(scene_t *scene, scene_t *pos_scene)
{
    obj_t *tow = pos_scene->perso;
    obj_t *tow2 = scene->perso;
    sfFloatRect pos_tow;
    sfFloatRect pos_tow2;

    while (tow2 != NULL) {
        pos_tow = sfSprite_getGlobalBounds(tow->sprite_perso);
        pos_tow2 = sfSprite_getGlobalBounds(tow2->sprite_perso);
        if (tow != tow2 &&
            sfFloatRect_intersects(&pos_tow2, &pos_tow, NULL) == sfTrue) {
            return (1);
        }
        tow2 = tow2->next;
    }
    return (0);
}

void find_pos(obj_t *perso, scene_t *scene)
{
    but_s *pos = scene->pos_tow;
    sfVector2f pos_tow;
    sfVector2f pos_perso = sfSprite_getPosition(perso->sprite_perso);

    while (pos != NULL) {
        pos_tow = sfRectangleShape_getPosition(pos->but);
        if (pos_perso.x + 30 >= pos_tow.x &&
            pos_perso.x + 30 <= pos_tow.x + 100 &&
            pos_perso.y + 55 >= pos_tow.y &&
            pos_perso.y + 55 <= pos_tow.y + 100) {
            pos_tow.y = pos_tow.y - 30;
            sfSprite_setPosition(perso->sprite_perso, pos_tow);
            pos_perso = sfSprite_getPosition(perso->sprite_perso);
            sfSprite_setPosition(perso->sprite_bullet, pos_perso);
        }
        pos = pos->next;
    }
}

int cond_rel(sfVector2f pos1, but_s *checkpoint, scene_t *scene)
{
    sfVector2f pos;
    sfVector2i mouse = sfMouse_getPositionRenderWindow(scene->window);

    while (checkpoint != NULL) {
        pos = sfRectangleShape_getPosition(checkpoint->but);
        if (mouse.x >= pos.x && mouse.x <= pos.x + 100 &&
            mouse.y >= pos.y && mouse.y <= pos.y + 100) {
            return (1);
        }
        checkpoint = checkpoint->next;
    }
    return (0);
}
