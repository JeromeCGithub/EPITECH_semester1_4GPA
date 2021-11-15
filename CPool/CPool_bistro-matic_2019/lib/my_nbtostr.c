/*
** EPITECH PROJECT, 2019
** bistro-matic
** File description:
** nbtostr
*/

#include "../include/my.h"

char *my_nbtostr(int nb)
{
    int i = 0;
    int len = 0;
    char *str;

    for (len = nb ; len > 0 ; len /= 10, i++);
    str = malloc(sizeof(char) * (len + 1));
    test_malloc(str);
    for (i = 0 ; nb > 0 ; i++) {
        str[i] = NTA(nb % 10);
        nb /= 10;
    }
    str[i] = '\0';
    str = my_revstr(str);
    return (str);
}
