/*
** EPITECH PROJECT, 2019
** bistro-matic
** File description:
** my_strdup
*/

#include "../include/my.h"
#include <stdlib.h>

char *my_strdup(char const *str)
{
    char *new;
    int i = 0;

    new = malloc(sizeof(char) * (my_strlen(str) + 1));
    test_malloc(new);
    for (; str[i] != '\0' ; i++)
        new[i] = str[i];
    new[i] = '\0';
    return (new);
}
