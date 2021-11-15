/*
** EPITECH PROJECT, 2020
** 107transfer
** File description:
** parser
*/

#include <my.h>

static int count_nb_number(char *str)
{
    int nb = 0;

    for (int i = 0; str[i]; i++) {
        if (str[i] == '*')
            nb++;
    }
    return (nb + 1);
}

static char *jump_to_next_nb(char *str)
{
    int i = 0;

    for (i = 0; str[i]; i++)
        if (str[i] == '*')
            return (&str[i + 1]);
    return (str);
}

rational_func_t **parse(int ac, char **av)
{
    int nb_num = 0;
    int nb_den = 0;
    int index = 0;
    rational_func_t **my_rational = malloc(sizeof(rational_func_t *) * (ac / 2 + 1));

    for (int i = 1 ; av[i] ; i += 2) {
        my_rational[index] = malloc(sizeof(rational_func_t));
        my_rational[index]->num = malloc(sizeof(double) * count_nb_number(av[i]));
        nb_num = count_nb_number(av[i]);
        for (int j = 0; j < nb_num; j++) {
            my_rational[index]->num[j] = atof(av[i]);
            my_rational[index]->nb_num = j + 1;
            av[i] = jump_to_next_nb(av[i]);
        }
        my_rational[index]->den = malloc(sizeof(double) * count_nb_number(av[i + 1]));
        nb_den = count_nb_number(av[i + 1]);
        for (int j = 0; j < nb_den; j++) {
            my_rational[index]->den[j] = atof(av[i + 1]);
            my_rational[index]->nb_den = j + 1;
            av[i + 1] = jump_to_next_nb(av[i + 1]);
        }
        index++;
    }
    my_rational[index] = NULL;
    return (my_rational);
}
