/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** print h
*/

#include <unistd.h>
#include "../include/my.h"

void print_h(char **av)
{
    if (av[1][0] == '-' && av[1][1] == 'h') {
        my_putstr("USAGE\n./my_sokoban map\nDESCRIPTION\n     map  file repr");
        my_putstr("esenting the warehouse map, containing '#' for walls,\n");
        my_putstr("          'P' for the player, 'X' for boxes and 'O' for");
        my_putstr(" storage locations.");
    }
}
