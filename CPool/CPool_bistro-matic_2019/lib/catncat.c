/*
** EPITECH PROJECT, 2019
** bistro-matic
** File description:
** my_strcat & my_strncat.c
*/

#include "../include/my.h"

char *my_strcat(char const *str1, char const *str2)
{
    int len = my_strlen(str1) + my_strlen(str2);
    char *new_str = malloc(sizeof(char) * (len + 1));
    int j = 0;
    int i = 0;

    test_malloc(new_str);
    for (; str1[i] != '\0' ; i++)
        new_str[i] = str1[i];
    for (; str2[j] != '\0' ; j++, i++)
        new_str[i] = str2[j];
    new_str[i] = '\0';
    return (new_str);
}

char *my_strndog(char const *str1, char const *str2, int n)
{
    char *new_str = malloc(sizeof(char) * (my_strlen(str1) + n + 1));
    int j = 0;
    int i = 0;

    test_malloc(new_str);
    for (; str1[i] != '\0' ; i++)
        new_str[i] = str1[i];
    for (; j < n ; j++, i++)
        new_str[i] = str2[j];
    new_str[i] = '\0';
    return (new_str);
}
