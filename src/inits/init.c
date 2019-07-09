/*
** EPITECH PROJECT, 2019
** Tower Defense
** File description:
** Initialisatitialasisation
*/

#include "prototype.h"

int init_strct(strct *strct)
{
    strct->money.font = sfFont_createFromFile("./assets/info.ttf");
    strct->money.var = 1;
    strct->money.txt = sfText_create();
    strct->score.var = 1;
    strct->score.txt = sfText_create();
    strct->money.descrip = place_money(strct, "money = ", 1565, 5);
    strct->score.descrip = place_money(strct, "score = ", 1565, 100);
    if (strct->money.descrip == NULL)
        return (84);
    return(0);
}

void init_castle(scene_t *scene)
{
    char *str = "./assets/castle.png";
    sfVector2f aug;

    aug.x = 1.5;
    aug.y = 1.5;
    scene->castle.sprite = sfSprite_create();
    scene->castle.texture = sfTexture_createFromFile(str, NULL);
    sfSprite_setTexture(scene->castle.sprite, scene->castle.texture, sfTrue);
    scene->castle.pos.x = 1300;
    scene->castle.pos.y = 150;
    sfSprite_setScale(scene->castle.sprite, aug);
    sfSprite_setPosition(scene->castle.sprite, scene->castle.pos);
    create_life(&(scene->castle), scene->castle.pos, 250, 25);
}

int init_scene(scene_t *scene)
{
    scene->perso = NULL;
    scene->checkpoint = NULL;
    scene->ennemi = NULL;
    scene->pos_tow = NULL;
    scene->clocks = sfClock_create();
    init_button(scene);
    init_castle(scene);
    if (init_checkpoint(scene, 1400, 420) == 84 ||
        init_checkpoint(scene, 940, 420) == 84 ||
        init_checkpoint(scene, 940, 620) == 84 ||
        init_checkpoint(scene, 520, 620) == 84 ||
        init_checkpoint(scene, 520, 220) == 84 ||
        init_checkpoint(scene, 205, 220) == 84 ||
        init_checkpoint(scene, 205, 515) == 84 ||
        init_checkpoint_tower(scene) == 84)
        return (84);
    if (nbr_ennemi(scene) == 84)
        return (84);
    return (0);
}

int init_music(scene_t *scene)
{
    scene->music = malloc(sizeof(musics));
    if (scene->music == NULL)
        return (84);
    scene->music->music = sfMusic_createFromFile("assets/Music.ogg");
    scene->music->damage = sfMusic_createFromFile("assets/damage.ogg");
    scene->music->damage2 = sfMusic_createFromFile("assets/damage_2.ogg");
    scene->music->damage3 = sfMusic_createFromFile("assets/damage_3.ogg");
}

int init_all(scene_t *scene, strct *strct, pause_s *pause, timer *clock_castle)
{
    clock_castle->clock = sfClock_create();
    scene->window = createmywindow(1920, 1080);
    sfRenderWindow_setFramerateLimit(scene->window, 30);
    if (init_scene(scene) == 84)
        return (84);
    map(&scene->fond);
    if (init_strct(strct) == 84)
        return (84);
    if (init_pause(pause) == 84)
        return (84);
    if (init_music(scene) == 84)
        return (84);
    clockcreate(strct, 3);
    return (1);
}
