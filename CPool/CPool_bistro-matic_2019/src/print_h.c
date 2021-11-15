/*
** EPITECH PROJECT, 2019
** print_h.c
** File description:
** print -h
*/

#include "../include/my.h"

void print_h(int ac, char **av)
{
    if (ac > 1 && av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0') {
        my_putstr("USAGE\n./calc base operators size_read\n\nDESCRIPTION");
        my_putstr("\n- base: all the symbols of the base\n");
        my_putstr("- operators: the symbols for the parentheses and the 5 ");
        my_putstr("operators\n- size_read: number of characters to be read\n");
        exit(0);
    }
}
