/*
** EPITECH PROJECT, 2019
** move_icon.c
** File description:
** move_icon.c
*/

#include "prototype.h"

int compare_coord(obj_t *perso, sfVector2i mouse)
{
    sfVector2f sprite_pos = sfSprite_getPosition(perso->sprite_perso);

    if (sprite_pos.x > mouse.x
        || sprite_pos.x + 60 < mouse.x)
        return (0);
    if (sprite_pos.y > mouse.y
        || sprite_pos.y + 110 < mouse.y)
        return (0);
    return (1);
}

void check_move(scene_t *scene)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(scene->window);
    scene_t temp = *scene;

    while (scene->perso != NULL) {
        if (compare_coord(scene->perso, mouse) == 1) {
            scene->perso->is_drag = 1;
            *scene = temp;
            return;
        }
        scene->perso = scene->perso->next;
    }
    *scene = temp;
    return;
}

void move_icon(scene_t *scene)
{
    sfVector2i mouse;
    sfVector2f mouse_circ;
    sfVector2f mouse_pos;
    sfFloatRect tow_rect;
    scene_t temp = *scene;

    while (scene->perso != NULL) {
        if (scene->perso->is_drag == 1 && scene->perso->is_placed == 1) {
            tow_rect = sfSprite_getGlobalBounds(scene->perso->sprite_perso);
            mouse = sfMouse_getPositionRenderWindow(scene->window);
            mouse_circ.x = mouse.x;
            mouse_circ.y = mouse.y;
            mouse_pos.x = mouse.x - (tow_rect.width / 2);
            mouse_pos.y = mouse.y - (tow_rect.height / 2);
            sfCircleShape_setPosition(scene->perso->zone, mouse_circ);
            sfSprite_setPosition(scene->perso->sprite_perso, mouse_pos);
        }
        scene->perso = scene->perso->next;
    }
    *scene = temp;
}

void is_trashed(scene_t *scene, scene_t *temp, int i, strct *strct)
{
    scene_t *temp3 = temp;
    scene_t temp2 = *temp3;
    but_s *pos = scene->pos_tow;
    sfVector2f pos_p = sfSprite_getPosition(temp3->perso->sprite_perso);
    int a = 0;

    while (a != i) {
        temp3->perso = (&temp2)->perso->next;
        temp2 = *temp3;
        a ++;
    }
    if (cond_rel(pos_p, pos, scene) != 1 || double_pos(temp, scene) == 1) {
        strct->money.var = strct->money.var + (&temp2)->perso->damage.cost;
        (*temp3).perso = temp2.perso->next;
        return;
    }
    scene->perso->is_drag = 0;
    scene->perso->is_placed = 0;
    sfCircleShape_setOutlineColor(scene->perso->zone, sfTransparent);
    find_pos(scene->perso, scene);
}

void find_released(scene_t *scene, strct *strct)
{
    scene_t temp = *scene;
    int i = 0;

    while (scene->perso != NULL) {
        if (scene->perso->is_drag == 1) {
            is_trashed(scene, &temp, i, strct);
        }
        if (scene->perso == NULL)
            return;
        scene->perso = scene->perso->next;
        i ++;
    }
    *scene = temp;
}
