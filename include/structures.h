/*
** EPITECH PROJECT, 2018
** structures.h
** File description:
** HEADER
*/

#ifndef STRUCT_H
#define STRUCT_H

typedef struct musics
{
    sfMusic *music;
    sfMusic *damage;
    sfMusic *damage2;
    sfMusic *damage3;
    sfClock *music_cl;
    sfTime time_cl;
} musics;

typedef struct checkpoint
{
    sfVector2f pos;
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
    struct checkpoint *next;
} check_t;

typedef struct back_s
{
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
    sfVector2f size;
    sfVector2f pos;
    sfVector2f speed;
} ent_t;

typedef struct info
{
    sfFont *font;
    sfText *damage;
    sfText *slow;
    sfText *reload_time;
    sfText *cost;
    sfText *zone;
    sfText *up;
} info_t;

typedef struct  button_s 
{
    sfRectangleShape *but;
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect char_rect;
    sfVector2f pos;
    int is_clicked;
    int is_placed;
    info_t info;
    sfText *txt;
    struct button_s *next;
} but_s;

typedef struct linked_list
{
    void *data;
    struct linked_list *next;
} linked_list_t;

typedef struct ennemie
{
    int type;
    sfVector2f pos;
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
    int life;
    int is_zoned;
    sfClock *clock;
    sfTime time;
    float seconds;
    int is_slowed;
    sfRectangleShape *life_r;
    sfRectangleShape *life_g;
    struct ennemie *next;
    struct checkpoint *next_check;
} ennemi_t;

typedef struct textes_variables
{
    int var;
    sfText *descrip;
    sfText *txt;
    sfFont *font;
    char *str;
} vartxt;

typedef struct horloge
{
    sfClock *clock;
    sfTime time;
    float second;
} timer;

typedef struct towers
{
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
    sfVector2f size;
    sfVector2f pos;
} tower;

typedef struct dammage
{
    int dam;
    float slow;
    float reload;
    int zone;
    int cost;
    int up;
} dam_s;

typedef struct obj_s
{
    sfTexture *texture;
    sfSprite *sprite_perso;
    sfVector2f initialisation;
    sfIntRect char_rect;
    sfCircleShape *zone;
    int is_drag;
    int is_placed;
    sfTexture *texture_bullet;
    sfSprite *sprite_bullet;
    sfVector2f bullet_speed;
    int is_shot;
    int nb_tow;
    int nb_up;
    timer bullet_clock;
    timer rel;
    dam_s damage;
    struct button_s up;
    struct obj_s *next;
} obj_t;

typedef struct pause_t
{
    sfFont *font;
    sfRectangleShape *filter;
    sfText **txt;
    sfText *txt_q;
    sfText *txt_qg;
} pause_s;

typedef struct scene_s
{
    sfRenderWindow *window;
    sfClock *clocks;
    musics *music;
    sfTime times;
    struct back_s fond;
    struct ennemie castle;
    struct  obj_s *perso;
    struct button_s **button;
    struct checkpoint *checkpoint;
    struct button_s *pos_tow;
    struct ennemie *ennemi;
} scene_t;

typedef struct structure
{
    sfEvent event;
    ent_t back;
    timer timer[3];
    float counter;
    vartxt money;
    vartxt score;
} strct;

#endif /* ! STRUCT_H */
