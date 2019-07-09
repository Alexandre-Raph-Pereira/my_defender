/*
** EPITECH PROJECT, 2019
** My Defender
** File description:
** Stats in game
*/

#include "prototype.h"

sfText *place_money(strct *strct, char *arr, int x, int y)
{
    char *str = malloc(sizeof(char) * (my_strlen(arr) + 1));
    sfVector2f pos;
    sfText *text = sfText_create();

    if (str == NULL)
        return (NULL);
    pos.x = x;
    pos.y = y;
    my_strcpy(str, arr);
    sfText_setString(text, str);
    sfText_setFont(text, strct->money.font);
    sfText_setColor(text, sfWhite);
    sfText_setPosition(text, pos);
    sfText_setCharacterSize(text, 40);
    pos.x = pos.x + 180;
    if (my_str(str, "money = ") == 0)
        sfText_setPosition(strct->money.txt, pos);
    if (my_str(str, "score = ") == 0)
        sfText_setPosition(strct->score.txt, pos);
    free(str);
    return (text);
}

int println(strct *strct, sfRenderWindow *window)
{
    strct->score.str = int_to_char(strct->score.var, strct->score.str);
    strct->money.str = int_to_char(strct->money.var, strct->money.str);
    if (strct->money.str == NULL || strct->score.str == NULL)
        return (84);
    sfText_setString(strct->score.txt, strct->score.str);
    sfText_setString(strct->money.txt, strct->money.str);
    sfText_setFont(strct->score.txt, strct->money.font);
    sfText_setFont(strct->money.txt, strct->money.font);
    sfText_setColor(strct->score.txt, sfWhite);
    sfText_setColor(strct->money.txt, sfWhite);
    sfText_setCharacterSize(strct->score.txt, 40);
    sfText_setCharacterSize(strct->money.txt, 40);
    sfRenderWindow_drawText(window, strct->score.descrip, NULL);
    sfRenderWindow_drawText(window, strct->money.txt, NULL);
    sfRenderWindow_drawText(window, strct->money.descrip, NULL);
    sfRenderWindow_drawText(window, strct->score.txt, NULL);
    free(strct->score.str);
    free(strct->money.str);
    return (0);
}

int money_inc(strct *strct)
{
    clockelapsed(strct, 3);
    if (strct->timer[2].time.microseconds > 700000) {
        strct->money.var += 1;
        sfClock_restart(strct->timer[2].clock);
    }
}

int stats(scene_t *scene, strct *strct, sfRenderWindow *window)
{
    money_inc(strct);
    if (println(strct, window) == 84)
        return (84);
    sfMusic_setLoop(scene->music->music, sfTrue);
    sfRenderWindow_display(scene->window);
    return (0);
}
