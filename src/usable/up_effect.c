/*
** EPITECH PROJECT, 2019
** clone_def3
** File description:
** up_effect
*/

#include "prototype.h"

void up_tower1(obj_t *tower)
{
    tower->damage.dam = tower->damage.dam + 1;
}

void up_tower2(obj_t *tower)
{
    tower->damage.dam = tower->damage.dam + 5;
}

void up_tower3(obj_t *tower)
{
    tower->damage.dam = tower->damage.dam + 1;
    tower->damage.reload = tower->damage.reload - 0.2;
    tower->damage.slow++;
}

void up_tower4(obj_t *tower)
{
    tower->damage.dam = tower->damage.dam + 3;
    tower->damage.reload = tower->damage.reload - 0.2;
}