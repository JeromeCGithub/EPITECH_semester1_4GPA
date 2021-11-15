/*
** EPITECH PROJECT, 2019
** error_less.c
** File description:
** error less a
*/

#include <stdlib.h>
#include "../../include/my.h"

int countthis(char const *str, int *i)
{
    int counter = 0;

    for (; str[*i] == '-' || str[*i] == '+' ; *i = *i +1) {
        if (str[*i] == '-')
            counter++;
    }
    *i = *i - 1;
    return (counter % 2);
}

char *replaceit(int counter, char const *str, char *new_str, int *j)
{
    if (counter == 1)
        new_str[*j] = '-';
    else if (counter == 0)
        new_str[*j] = '+';
    return (new_str);
}

char *string_traitement(char const *str)
{
    char *new_str = malloc(sizeof(char *) * my_strlen(str));
    int counter = 0;
    int j = 0;

    test_malloc(new_str);
    for (int i = 0 ; str[i] != '\0' ; i++) {
        if (str[i] == '-' || str[i] == '+') {
            counter = countthis(str, &i);
            new_str = replaceit(counter, str, new_str, &j);
            j++;
        }
        else {
            new_str[j] = str[i];
            j++;
        }
    }
    new_str[j] = '\0';
    return (new_str);
}
