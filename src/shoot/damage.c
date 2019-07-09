/*
** EPITECH PROJECT, 2019
** clone_def3
** File description:
** damage
*/

#include "prototype.h"

dam_s damage(float slow, int dam, float time_r, int zone)
{
    dam_s damage;

    damage.slow = slow;
    damage.dam = dam;
    damage.reload = time_r;
    damage.zone = zone;
    return (damage);
}