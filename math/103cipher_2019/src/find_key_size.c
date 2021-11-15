/*
** EPITECH PROJECT, 2019
** 103cipher
** File description:
** find key size
*/

#include <my.h>

int find_key_size(char const *str)
{
    int len = my_strlen(str);
    int i = 0;

    for (; i * i < len; i++);
    return (i);
}
