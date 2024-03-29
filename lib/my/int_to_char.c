/*
** EPITECH PROJECT, 2019
** clone_def3
** File description:
** int_to_char
*/

#include <stdlib.h>

char *int_to_char(int nb, char *str)
{
    int n = 1;
    int i = 0;
    char *str2 = malloc(sizeof(char) * 12);

    if (str2 == NULL)
        return (NULL);
    if (nb < 0) {
        str[i] = '-';
        nb = nb * -1;
        i++;
    }
    while ((nb / 10) / n != 0)
        n = n * 10;
    while (n > 0) {
        str2[i] = nb / n + '0';
        nb = nb % n;
        n = n / 10;
        i++;
    }
    str2[i] = '\0';
    return (str2);
}
