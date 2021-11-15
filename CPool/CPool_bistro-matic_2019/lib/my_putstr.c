/*
** EPITECH PROJECT, 2019
** my_putstr
** File description:
** print str
*/

#include <stdlib.h>
#include <unistd.h>

void my_putchar(char c);

void my_putstr2(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        write(2, &str[i], 1);
        i++;
    }
}

void my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
}
