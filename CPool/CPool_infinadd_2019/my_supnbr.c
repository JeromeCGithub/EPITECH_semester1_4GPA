/*
** EPITECH PROJECT, 2019
** sub_nbr
** File description:
** my sup nbr
*/

#include "include/my.h"

void is_inputable(int strlen1, int strlen2, char *str1, char *str2)
{
    if (str1[0] == '-') {
        my_putchar('-');
        subinf(strlen1, strlen2, &str1[1], str2);
    }
    else if (str2[0] == '-')
        subinf(strlen1, strlen2, str1, &str2[1]);
    else
        subinf(strlen1, strlen2, str1, str2);
}

void is_inputable2(int strlen1, int strlen2, char *str1, char *str2)
{
    if (str2[0] == '-') {
        my_putchar('-');
        subinf(strlen2, strlen1, &str2[1], str1);
    }
    else if (str1[0] == '-')
        subinf(strlen2, strlen1, str2, &str1[1]);
    else
        subinf(strlen2, strlen1, str2, str1);
}

int true_or_false(char *c1, char *c2, int *i, int *j)
{
    if (c1[*i] == '-')
        *i = *i + 1;
    else if (c2[*j] == '-')
        *j = *j + 1;
    if (c1[*i] > c2[*j])
        return (1);
    else if (c1[*i] < c2[*j])
        return (2);
    else
        return (0);
}

void comparethis(char *str1, char *str2, int strlen1, int strlen2)
{
    int is = 0;
    int j = 0;

    for (int i = 0 ; i <= strlen1 ; i++) {
        if (true_or_false(str1, str2, &i, &j) == 1) {
            is = 1;
            is_inputable(strlen1, strlen2, str1, str2);
            break;
        }
        else if (true_or_false(str1, str2, &i, &j) == 2) {
            is = 1;
            is_inputable2(strlen1, strlen2, str1, str2);
            break;
        }
        j++;
    }
    if (is == 0)
        is_inputable3(strlen1, strlen2, str1, str2);
}

void my_supnbr(int strlen1, int strlen2, char *str1, char *str2)
{
    if (strlen1 > strlen2) {
        is_inputable(strlen1, strlen2, str1, str2);
    }
    else if (strlen1 < strlen2) {
        if (str2[0] == '-') {
            my_putchar('-');
            subinf(strlen2, strlen1, &str2[1], str1);
        }
        else if (str1[0] == '-')
            subinf(strlen2, strlen1, str2, &str1[1]);
        else
            subinf(strlen2, strlen1, str2, str1);
    }
    else
        comparethis(str1, str2, strlen1, strlen2);
}
