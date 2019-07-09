/*
** EPITECH PROJECT, 2019
** clone_def3
** File description:
** castle
*/

#include "prototype.h"

int castle_life(scene_t *scene)
{
    sfVector2f life_castle = sfRectangleShape_getSize(scene->castle.life_g);

    if (life_castle.x <= 0)
        return (0);
    return (1);
}

void castle_damage(scene_t *scene, timer *clock_castle)
{
    ennemi_t *enn = scene->ennemi;
    sfFloatRect check_pos;
    sfFloatRect enn_pos;
    sfVector2f size;

    clock_castle->time = sfClock_getElapsedTime(clock_castle->clock);
    clock_castle->second = clock_castle->time.microseconds / 1000000.0;
    while (enn != NULL && enn->sprite != NULL) {
        check_pos = sfSprite_getGlobalBounds(enn->next_check->sprite);
        enn_pos = sfSprite_getGlobalBounds(enn->sprite);
        if (enn->next_check->next == NULL &&
            sfFloatRect_intersects(&check_pos, &enn_pos, NULL) == sfTrue &&
            clock_castle->second > 0.5) {
            size = sfRectangleShape_getSize(scene->castle.life_g);
            size.x = size.x - 1;
            sfRectangleShape_setSize(scene->castle.life_g, size);
            sfClock_restart(clock_castle->clock);
        }
        enn = enn->next;
    }
}
