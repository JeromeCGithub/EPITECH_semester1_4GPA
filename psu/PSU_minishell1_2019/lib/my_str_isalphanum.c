/*
** EPITECH PROJECT, 2020
** lib
** File description:
** str is alpha num
*/

#include <minishell.h>

int is_num(char const *str)
{
    for (int i = 0 ; str[i] ; i++) {
        if (str[i] > '9' || str[i] < '0')
            return (0);
    }
    return (1);
}

int is_alpha(char const *str)
{
    for (int i = 0 ; str[i] ; i++) {
        if ((str[i] < 'a' || str[i] > 'z')
            && (str[i] < 'A' || str[i] > 'Z')
            && (str[i] > '9' || str[i] < '0')
            && str[i] != '.')
            return (0);
    }
    return (1);
}
