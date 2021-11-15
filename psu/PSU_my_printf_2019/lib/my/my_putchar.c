/*
** EPITECH PROJECT, 2019
** my_putchar
** File description:
** put a char
*/

#include "../../include/my.h"
#include <unistd.h>

void my_putchar_2(format_t *form, va_list arg)
{
    char c;

    c = va_arg(arg, int);
    for (int i = 0 ; i < form->width - 1 ; i++)
        write(1, " ", 1);
    write(1, &c, 1);
}
