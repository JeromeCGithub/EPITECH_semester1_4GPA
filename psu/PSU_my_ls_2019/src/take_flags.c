/*
** EPITECH PROJECT, 2020
** my ls
** File description:
** take flag
*/

#include <stdio.h>
#include <my.h>

void check_flag(size_t *flag, char *flag_char)
{
    for (int i = 1 ; flag_char[i] != '\0' ; i++) {
        if (flag_char[i] == 'l')
            *flag |= L_FLAG;
        if (flag_char[i] == 'r')
            *flag |= LITTLE_R_FLAG;
        if (flag_char[i] == 't')
            *flag |= 8;
        if (flag_char[i] == 'R')
            *flag |= BIG_R_FLAG;
        if (flag_char[i] == 'd')
            *flag |= D_FLAG;
        if (flag_char[i] != 'R' && flag_char[i] != 'l' && flag_char[i] != 't'
            && flag_char[i] != 'r' && flag_char[i] != 'd') {
            write(2, "ls: invalid option -- '", 23);
            write(2, &flag_char[i], 1);
            write(2, "'\ntry 'ls --help' for more information.\n", 40);
            exit(84);
        }
    }
}

size_t take_flag(char **av)
{
    size_t flag = 0;

    for (int i = 0 ; av[i] ; i++) {
        if (av[i][0] == '-')
            check_flag(&flag, av[i]);
    }
    return (flag);
}
