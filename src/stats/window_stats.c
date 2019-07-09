/*
** EPITECH PROJECT, 2018
** window_stats.c
** File description:
** HEADER
*/

#include "prototype.h"

sfRenderWindow *createmywindow(unsigned int width, unsigned int height)
{
    sfRenderWindow *window;
    sfVideoMode video_mode;

    video_mode.width = width;
    video_mode.height = height;
    video_mode.bitsPerPixel = 32;
    window = sfRenderWindow_create(video_mode,
                                   "My_Defender/v1.0.5", sfDefaultStyle, NULL);
    return (window);
}

void free_strct(strct *strct)
{
    sfFont_destroy(strct->money.font);
    sfText_destroy(strct->money.txt);
    sfText_destroy(strct->money.descrip);
    sfText_destroy(strct->score.txt);
    sfText_destroy(strct->score.descrip);
    sfClock_destroy(strct->timer[0].clock);
    sfClock_destroy(strct->timer[1].clock);
    sfClock_destroy(strct->timer[2].clock);
}

void free_pause(pause_s *pause)
{
    sfRectangleShape_destroy(pause->filter);
    sfFont_destroy(pause->font);
    sfText_destroy(pause->txt[0]);
    sfText_destroy(pause->txt[1]);
    sfText_destroy(pause->txt[2]);
    free(pause->txt);
}

void close_window(scene_t *scene, strct *strct, pause_s *pause)
{
    free_music(scene);
    free_perso(scene);
    free_ennemi(scene);
    free_button(scene);
    free_checkpoint(scene);
    sfSprite_destroy(scene->fond.sprite);
    sfTexture_destroy(scene->fond.texture);
    sfSprite_destroy(scene->castle.sprite);
    sfTexture_destroy(scene->castle.texture);
    sfRectangleShape_destroy(scene->castle.life_g);
    sfRectangleShape_destroy(scene->castle.life_r);
    free_strct(strct);
    free_pause(pause);
    sfRenderWindow_close(scene->window);
}
