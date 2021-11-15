/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** error handling
*/

#include <stdlib.h>

void check_map(char *buff)
{
    for (int i = 0 ; buff[i] != '\0' ; i++) {
        if (buff[i] != ' ' && buff[i] != '\n'
            && buff[i] != '#' && buff[i] != 'P'
            && buff[i] != 'X' && buff[i] != 'O')
            exit(84);
    }
}
