/*
** EPITECH PROJECT, 2019
** my_putstr
** File description:
** print str
*/

#include <stdlib.h>
#include <unistd.h>

void my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        write(1, &str[i], 1);
        i++;
    }
}
