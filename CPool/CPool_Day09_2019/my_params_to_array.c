/*
** EPITECH PROJECT, 2019
** my_params_to_array
** File description:
** Params to array struct.
*/

#include <stdlib.h>
#include "include/my.h"

struct info_param *my_params_to_array(int ac, char **av)
{
    struct info_param *parameter;
    int j = 0;

    parameter = malloc(sizeof(struct info_param) * ac);
    for (j = 0 ; av[j] != 0 ; j++)
    {
        parameter[j].length = my_strlen(av[j]);
        parameter[j].str = &av[j][0];
        parameter[j].copy = malloc(sizeof(char) * my_strlen(av[j]));
        parameter[j].copy = my_strcpy(parameter[j].copy, av[j]);
        parameter[j].word_array = my_str_to_word_array(av[j]);
    }
    parameter[j].str = 0;
    return (parameter);
}
