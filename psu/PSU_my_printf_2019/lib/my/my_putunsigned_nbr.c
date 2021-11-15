/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** put a nbr unsigned
*/

#include "../../include/my.h"
#include <unistd.h>
#include <stdlib.h>

void my_putunsigned_nbr(format_t *form, va_list arg)
{
    char *buff = malloc(sizeof(char) * 512);
    int i = 0;
    char less = '-';
    uintmax_t nb = va_arg(arg, uintmax_t);

    nb = ucast(nb, form);
    for (; nb != 0 ; i++) {
        buff[i] = (nb % 10) + '0';
        nb = nb / 10;
    }
    buff[i] = '\0';
    buff = my_revstr(buff);
    print_string(buff, form);
}
