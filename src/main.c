/*
** EPITECH PROJECT, 2019
** Tower Defense
** File description:
** Main
*/

#include "prototype.h"

int main(int ac, char **argv)
{
    int gamemode = 0;

    if (ac == 2 && my_str("-h", argv[1]) == 0)
        return (usage());
    while (gamemode >= 0)
        switch (gamemode) {
        case 0: mainscreen(&gamemode);
            break;
        case 1: game(&gamemode);
            break;
        case 2: mainscreen(&gamemode);
            break;
        case 3: return (0);
            break;
        default: return (84);
        }
    return (0);
}
