/*
** EPITECH PROJECT, 2019
** bistro-matic
** File description:
** my_strdup
*/

#include <stdlib.h>
#include "../include/my.h"

char *my_strndup(char const *str, int n)
{
    char *new;
    int i = 0;

    new = malloc(sizeof(char) * (my_strlen(str) + 1));
    test_malloc(new);
    for (; i != n ; i++)
        new[i] = str[i];
    new[i] = '\0';
    return (new);
}
