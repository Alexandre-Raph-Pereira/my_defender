/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** create_tower
*/

#include "prototype.h"

void create_square(but_s *button, sfVector2f pos, sfVector2f size)
{
    button->but = sfRectangleShape_create();
    sfRectangleShape_setOutlineColor(button->but, sfTransparent);
    sfRectangleShape_setOutlineThickness(button->but, 1);
    sfRectangleShape_setFillColor(button->but, sfBlack);
    sfRectangleShape_setSize(button->but, size);
    sfRectangleShape_setPosition(button->but, pos);
}

void create_button1(but_s *but)
{
    sfVector2f pos;
    sfVector2f size;

    pos.x = 1565;
    pos.y = 195;
    size.x = 295;
    size.y = 200;
    but->char_rect = create_char_rect(64, 88, 86, 90);
    but->texture = sfTexture_createFromFile("assets/magic_tower.png", NULL);
    but->sprite = sfSprite_create();
    create_square(but, pos, size);
    but->info.font = sfFont_createFromFile("./assets/info.ttf");
    sfSprite_setTexture(but->sprite, but->texture, sfTrue);
    sfSprite_setTextureRect(but->sprite, but->char_rect);
    sfSprite_setPosition(but->sprite, pos);
    but->is_clicked = 0;
    create_cost(but, "cost/up = 10", 1665, 200);
    create_damage(but, "damage = 1", 1665, 235);
    create_reload(but, "reload = 0,1", 1665, 270);
    create_slow(but, "slow = 0", 1665, 305);
    create_zone(but, "zone = 1", 1665, 340);
}

void create_button3(but_s *but)
{
    sfVector2f pos;
    sfVector2f size;

    pos.x = 1565;
    pos.y = 605;
    size.x = 295;
    size.y = 200;
    but->char_rect = create_char_rect(64, 224, 86, 116);
    but->texture = sfTexture_createFromFile("assets/magic_tower.png", NULL);
    but->sprite = sfSprite_create();
    create_square(but, pos, size);
    but->info.font = sfFont_createFromFile("./assets/info.ttf");
    sfSprite_setTexture(but->sprite, but->texture, sfTrue);
    sfSprite_setTextureRect(but->sprite, but->char_rect);
    sfSprite_setPosition(but->sprite, pos);
    but->is_clicked = 0;
    create_cost(but, "cost/up = 15", 1665, 605);
    create_damage(but, "damage = 0", 1665, 640);
    create_reload(but, "reload = 0,5", 1665, 675);
    create_slow(but, "slow = 2", 1665, 700);
    create_zone(but, "zone = 1", 1665, 735);
}

void create_button2(but_s *but)
{
    sfVector2f pos;
    sfVector2f size;

    pos.x = 1565;
    pos.y = 400;
    size.x = 295;
    size.y = 200;
    but->char_rect = create_char_rect(380, 68, 80, 110);
    but->texture = sfTexture_createFromFile("assets/magic_tower.png", NULL);
    but->sprite = sfSprite_create();
    create_square(but, pos, size);
    but->info.font = sfFont_createFromFile("./assets/info.ttf");
    sfSprite_setTexture(but->sprite, but->texture, sfTrue);
    sfSprite_setTextureRect(but->sprite, but->char_rect);
    sfSprite_setPosition(but->sprite, pos);
    but->is_clicked = 0;
    create_cost(but, "cost/up = 50", 1665, 400);
    create_damage(but, "damage = 5", 1665, 445);
    create_reload(but, "reload = 0.5", 1665, 480);
    create_slow(but, "slow = 0", 1665, 515);
    create_zone(but, "zone = 1", 1665, 550);
}

void create_button4(but_s *but)
{
    sfVector2f pos;
    sfVector2f size;

    pos.x = 1565;
    pos.y = 810;
    size.x = 295;
    size.y = 200;
    but->char_rect = create_char_rect(372, 172, 100, 168);
    but->texture = sfTexture_createFromFile("assets/magic_tower.png", NULL);
    but->sprite = sfSprite_create();
    create_square(but, pos, size);
    but->info.font = sfFont_createFromFile("./assets/info.ttf");
    sfSprite_setTexture(but->sprite, but->texture, sfTrue);
    sfSprite_setTextureRect(but->sprite, but->char_rect);
    sfSprite_setPosition(but->sprite, pos);
    but->is_clicked = 0;
    create_cost(but, "cost/up = 50", 1665, 810);
    create_damage(but, "damage = 3", 1665, 845);
    create_reload(but, "reload = 1", 1665, 880);
    create_slow(but, "slow = 0", 1665, 915);
    create_zone(but, "zone = 150", 1665, 950);
}