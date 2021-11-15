/*
** EPITECH PROJECT, 2020
** my ls
** File description:
** print time
*/

#include <my.h>

void print_time(char *the_time)
{
    int index = 4;

    while (index < 16) {
        write(1, &the_time[index], 1);
        index++;
    }
    write(1, " ", 1);
}
