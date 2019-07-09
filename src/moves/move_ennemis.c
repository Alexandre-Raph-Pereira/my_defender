/*
** EPITECH PROJECT, 2019
** move_ennemie.c
** File description:
** move_ennemi
*/

#include "prototype.h"

int cond_x(ennemi_t *enn, check_t *check)
{
    sfVector2f enn_pos = sfSprite_getPosition(enn->sprite);
    sfVector2f check_pos = sfSprite_getPosition(check->sprite);

    if (enn_pos.x > check_pos.x + 5)
        return (-3);
    else if (enn_pos.x < check_pos.x - 5)
        return (3);
    return (0);
}

int cond_y(ennemi_t *enn, check_t *check)
{
    sfVector2f enn_pos = sfSprite_getPosition(enn->sprite);
    sfVector2f check_pos = sfSprite_getPosition(check->sprite);

    if (enn_pos.y > check_pos.y + 5)
        return (-3);
    else if (enn_pos.y < check_pos.y - 5)
        return (3);
    return (0);
}

void move_function(scene_t *scene, sfVector2f move)
{
    sfFloatRect enn;
    sfFloatRect ch;

    enn = sfSprite_getGlobalBounds(scene->ennemi->sprite);
    ch = sfSprite_getGlobalBounds(scene->ennemi->next_check->sprite);
    sfSprite_move(scene->ennemi->sprite, move);
    sfRectangleShape_move(scene->ennemi->life_r, move);
    sfRectangleShape_move(scene->ennemi->life_g, move);
    if (sfFloatRect_intersects(&enn, &ch, NULL) == sfTrue
        && scene->ennemi->next_check->next != NULL) {
        scene->ennemi->next_check = scene->ennemi->next_check->next;
    }
}

void move_ennemis(scene_t *scene)
{
    ennemi_t *ennemie = scene->ennemi;
    sfVector2f move;

    while (scene->ennemi != NULL) {
        scene->ennemi->time = sfClock_getElapsedTime(scene->ennemi->clock);
        scene->ennemi->seconds = scene->ennemi->time.microseconds / 1000000.0;
        if (scene->ennemi->seconds > 0.1) {
            move.x = cond_x(scene->ennemi, scene->ennemi->next_check);
            move.y = cond_y(scene->ennemi, scene->ennemi->next_check);
            if (scene->ennemi->is_slowed > 1) {
                move.x = move.x / scene->ennemi->is_slowed;
                move.y = move.y / scene->ennemi->is_slowed;
            }
            move_function(scene, move);
            sfClock_restart(scene->ennemi->clock);
        }
        scene->ennemi = scene->ennemi->next;
    }
    scene->ennemi = ennemie;
}
