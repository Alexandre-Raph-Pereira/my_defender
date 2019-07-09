/*
** EPITECH PROJECT, 2019
** clone_def3
** File description:
** disp_info
*/

#include "prototype.h"

void create_cost(but_s *button, char *str, int x, int y)
{
    sfVector2f pos;

    pos.x = x;
    pos.y = y;
    button->info.cost = sfText_create();
    sfText_setString(button->info.cost, str);
    sfText_setFont(button->info.cost, button->info.font);
    sfText_setColor(button->info.cost, sfWhite);
    sfText_setCharacterSize(button->info.cost, 30);
    sfText_setPosition(button->info.cost, pos);
}

void create_damage(but_s *button, char *str, int x, int y)
{
    sfVector2f pos;

    pos.x = x;
    pos.y = y;
    button->info.damage = sfText_create();
    sfText_setString(button->info.damage, str);
    sfText_setFont(button->info.damage, button->info.font);
    sfText_setColor(button->info.damage, sfWhite);
    sfText_setPosition(button->info.damage, pos);
    sfText_setCharacterSize(button->info.damage, 30);
}

void create_reload(but_s *button, char *str, int x, int y)
{
    sfVector2f pos;

    pos.x = x;
    pos.y = y;
    button->info.reload_time = sfText_create();
    sfText_setString(button->info.reload_time, str);
    sfText_setFont(button->info.reload_time, button->info.font);
    sfText_setColor(button->info.reload_time, sfWhite);
    sfText_setPosition(button->info.reload_time, pos);
    sfText_setCharacterSize(button->info.reload_time, 30);
}

void create_slow(but_s *button, char *str, int x, int y)
{
    sfVector2f pos;

    pos.x = x;
    pos.y = y;
    button->info.slow = sfText_create();
    sfText_setString(button->info.slow, str);
    sfText_setFont(button->info.slow, button->info.font);
    sfText_setColor(button->info.slow, sfWhite);
    sfText_setPosition(button->info.slow, pos);
    sfText_setCharacterSize(button->info.slow, 30);
}

void create_zone(but_s *button, char *str, int x, int y)
{
    sfVector2f pos;

    pos.x = x;
    pos.y = y;
    button->info.zone = sfText_create();
    sfText_setString(button->info.zone, str);
    sfText_setFont(button->info.zone, button->info.font);
    sfText_setColor(button->info.zone, sfWhite);
    sfText_setPosition(button->info.zone, pos);
    sfText_setCharacterSize(button->info.zone, 30);
}