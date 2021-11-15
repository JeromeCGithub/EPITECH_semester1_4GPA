/*
** EPITECH PROJECT, 2019
** my_show_param_array
** File description:
** show param array
*/

#include "include/my.h"

int my_show_param_array(struct info_param const *par)
{
    for (int j = 0 ; par[j].length != 0 ; j++)
    {
        my_putstr(par[j].copy);
        my_putchar('\n');
        my_put_nbr(par[j].length);
        my_putchar('\n');
        my_show_word_array(par[j].word_array);
    }
    return (0);
}
