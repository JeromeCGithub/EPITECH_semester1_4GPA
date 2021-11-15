/*
** EPITECH PROJECT, 2019
** strdup
** File description:
** Allocate dynamics for a string.
*/

#include <stdlib.h>

int my_strlen5(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}

char *my_strdup(char const *src)
{
    char *str = NULL;
    int i = 0;

    str = malloc(sizeof(char) * (my_strlen5(src) + 1));
    for (i = 0 ; src[i] != '\0' ; i++)
    {
        str[i] = src[i];
    }
    str[i] = '\0';
    return (str);
}
