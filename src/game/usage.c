/*
** EPITECH PROJECT, 2019
** Tower Defense
** File description:
** Usage
*/

#include "prototype.h"

int usage(void)
{
    my_putstr("\e[96m\e[1mUSAGE\n");
    my_putstr("\t./my_defender\n");
    my_putstr("\tOnly \"-h\" if you want some info ;)\n");
    my_putstr("\nDESCRIPTION\n");
    my_putstr("\tThe defender, is a game where you have ");
    my_putstr("to protect your castle.\n\tSome ennemi will try ");
    my_putstr("to destroy it, you have to stop them,\n\twith towers !\n");
    my_putstr("\t\t\e[0m\n");
    return (0);
}
