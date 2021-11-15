/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** putchar
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
