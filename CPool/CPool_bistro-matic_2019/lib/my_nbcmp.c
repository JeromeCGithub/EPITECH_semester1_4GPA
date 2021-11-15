/*
** EPITECH PROJECT, 2019
** bistro-matic
** File description:
** my_nbcmp
*/

#include "../include/my.h"

int my_nbcmp(char const *nb1, char const *nb2)
{
    int i = 0;

    if (my_strlen(nb1) == my_strlen(nb2))
        for (; nb1[i] == nb2[i] && nb1[i] != '\0' ; i++);
    else if (my_strlen(nb1) > my_strlen(nb2))
        return (1);
    else
        return (-1);
    if (nb2[i] == '\0')
        return (0);
    return (nb1[i] - nb2[i] > 0) ? (1) : (-1);
}
