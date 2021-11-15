/*
** EPITECH PROJECT, 2019
** bistro-matic
** File description:
** clean_str
*/

#include "../../include/bistromatic.h"
#include "../../include/my.h"

char convert_char(char c, char const *base_nb, char const *base_op)
{
    char *index = "()+-*/%";

    for (int i = 0 ; base_nb[i] != '\0' ; i++)
        if (base_nb[i] == c)
            return (NTA(i));
    for (int i = 0 ; base_op[i] != '\0' ; i++)
        if (base_op[i] == c)
            return (index[i]);
    my_putstr(SYNTAX_ERROR_MSG);
    exit(84);
}

char *clean_str(char const *str, char const *base_nb, char const *base_op)
{
    char *result = my_strdup(str);
    int i = 0;

    for (; str[i] != '\0' ; i++)
        result[i] = convert_char(result[i], base_nb, base_op);
    result[i] = '\0';
    return (result);
}
