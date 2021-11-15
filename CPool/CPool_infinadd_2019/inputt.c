/*
** EPITECH PROJECT, 2019
** inputt
** File description:
** inputtt lol
*/

#include "include/my.h"

void is_inputable3(int strlen1, int strlen2, char *str1, char *str2)
{
    if (str1[0] == '-')
        subinf(strlen1, strlen2, &str1[1], str2);
    else if (str2[0] == '-')
        subinf(strlen1, strlen2, str1, &str2[1]);
    else
        subinf(strlen1, strlen2, str1, str2);
}
