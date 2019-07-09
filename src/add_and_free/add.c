/*
** EPITECH PROJECT, 2019
** add.c
** File description:
** add
*/

#include "prototype.h"

void create_circle(obj_t *obj, sfVector2f mouse)
{
    sfVector2f pos = sfSprite_getPosition(obj->sprite_perso);
    sfFloatRect size_sp = sfSprite_getGlobalBounds(obj->sprite_perso);
    sfVector2f size;

    pos.x = pos.x + 30;
    pos.y = pos.y + 55;
    size.x = 150;
    size.y = 150;
    obj->zone = sfCircleShape_create();
    sfCircleShape_setOutlineColor(obj->zone, sfGreen);
    sfCircleShape_setOutlineThickness(obj->zone, 2);
    sfCircleShape_setFillColor(obj->zone, sfTransparent);
    sfCircleShape_setRadius(obj->zone, 150);
    sfCircleShape_setOrigin(obj->zone, size);
    sfCircleShape_setPosition(obj->zone, mouse);
}

void create_tower(obj_t *obj, int i)
{
    if (i == 0) {
        obj->char_rect = create_char_rect(64, 64, 86, 113);
        obj->nb_tow = 0;
        obj->damage = damage(1, 1, 0.1, 0);
    }
    if (i == 1) {
        obj->char_rect = create_char_rect(367, 68, 88, 110);
        obj->damage = damage(1, 5, 1, 0);
        obj->nb_tow = 1;
    }
    if (i == 2) {
        obj->char_rect = create_char_rect(64, 224, 86, 116);
        obj->damage = damage(5, 1, 0.5, 0);
        obj->nb_tow = 2;
    }
    if (i == 3) {
        obj->char_rect = create_char_rect(372, 172, 100, 168);
        obj->nb_tow = 3;
        obj->damage = damage(1, 3, 1, 150);
    }
}

void create_tool_bar(obj_t *obj, sfVector2f mouse_pos)
{
    sfVector2f size;
    sfVector2f scale;

    size.x = 110;
    size.y = 35;
    scale.x = 0.65;
    scale.y = 0.65;
    obj->up.char_rect = create_char_rect(200, 224, 54, 54);
    obj->up.texture = sfTexture_createFromFile("assets/up.png", NULL);
    obj->up.sprite = sfSprite_create();
    sfSprite_setTexture(obj->up.sprite, obj->up.texture, sfTrue);
    sfSprite_setTextureRect(obj->up.sprite, obj->up.char_rect);
    sfSprite_setPosition(obj->up.sprite, mouse_pos);
    sfSprite_setScale(obj->up.sprite, scale);
    obj->up.but = sfRectangleShape_create();
    sfRectangleShape_setFillColor(obj->up.but, sfWhite);
    sfRectangleShape_setSize(obj->up.but, size);
    sfRectangleShape_setPosition(obj->up.but, mouse_pos);
    obj->up.is_clicked = 0;
}

void init_tower(scene_t *scene, obj_t *obj, int i, sfVector2f mouse_pos)
{
    obj->texture = sfTexture_createFromFile("assets/magic_tower.png", NULL);
    obj->bullet_clock.clock = sfClock_create();
    obj->rel.clock = sfClock_create();
    create_tower(obj, i);
    obj->sprite_perso = sfSprite_create();
    obj->nb_up = 1;
    sfSprite_setTexture(obj->sprite_perso, obj->texture, sfTrue);
    sfSprite_setTextureRect(obj->sprite_perso, obj->char_rect);
    obj->texture_bullet = sfTexture_createFromFile("assets/bullet.png", NULL);
    obj->sprite_bullet = sfSprite_create();
    obj->is_drag = 1;
    obj->is_placed = 1;
    sfSprite_setTexture(obj->sprite_bullet, obj->texture_bullet, sfTrue);
    obj->is_shot = 0;
    sfSprite_setPosition(obj->sprite_perso, mouse_pos);
    create_circle(obj, mouse_pos);
    create_tool_bar(obj, mouse_pos);
}

int add_ruby(scene_t *scene, int i, strct *strct)
{
    obj_t *obj = malloc(sizeof(obj_t));
    sfVector2i mouse = sfMouse_getPositionRenderWindow(scene->window);
    sfVector2f mouse_pos;
    int cost = 0;

    if (i == 1 || i == 3)
        cost = 50;
    if (i == 2)
        cost = 15;
    if (i == 0)
        cost = 10;
    if (strct->money.var > cost) {
        mouse_pos = convert_mouse(mouse);
        strct->money.var -= cost;
        init_tower(scene, obj, i, mouse_pos);
        obj->damage.cost = cost;
        obj->next = scene->perso;
        scene->perso = obj;
    }
    return (0);
}
