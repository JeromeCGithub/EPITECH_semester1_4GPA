/*
** EPITECH PROJECT, 2020
** matchstick
** File description:
** error handling
*/

#include <my.h>

int is_only_nb(char *str)
{
    for (int i = 0 ; str[i] ; i++) {
        if (str[i] < '0' || str[i] > '9')
            return (0);
    }
    return (1);
}

int is_error_line(char *nb_read, int nb_line, int matchs, int *tab)
{
    if (nb_read[0] == '\0')
        return (1);
    if (!(is_only_nb(nb_read))) {
        write(1, "Error: invalid input (positive number expected)\n", 48);
        return (1);
    }
    if (my_atoi(nb_read) > nb_line || my_atoi(nb_read) <= 0) {
        write(1, "Error: this line is out of range\n", 33);
        return (1);
    }
    return (0);
}

int is_error_match(int *tab, char *nb_match, int line, int max_match)
{
    if (!(is_only_nb(nb_match))) {
        write(1, "Error: invalid input (positive number expected)\n", 48);
        return (1);
    }
    if (my_atoi(nb_match) > max_match) {
        write(1, "Error: you cannot remove more than ", 35);
        my_put_nbr(max_match);
        write(1, " matches per turn\n", 18);
        return (1);
    }
    if (my_atoi(nb_match) == 0) {
        write(1, "Error: you have to remove at least one match\n", 45);
        return (1);
    }
    if (tab[line - 1] - my_atoi(nb_match) < 0) {
        write(1, "Error: not enough matches on this line\n", 39);
        return (1);
    }
    return (0);
}
