/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** put in hex %p
*/

#include <inttypes.h>
#include <stdlib.h>
#include "../../include/my.h"

void puthex2(uintptr_t nb, char *buff)
{
    int i = 0;

    if (nb == 0) {
        buff[0] = '0';
        buff[1] = '\0';
    }
    for (i = 0 ; nb != 0 ; i++) {
        if (nb % 16 > 9)
            buff[i] = (nb % 16) + 'a' - 10;
        else
            buff[i] = (nb % 16) + '0';
        nb = nb / 16;
    }
    buff[i] = '\0';
    buff = my_revstr(buff);
}

void my_puthex(format_t *form, va_list arg)
{
    uintptr_t nb = va_arg(arg, uintptr_t);
    char *buff = malloc(sizeof(char) * 512);

    puthex2(nb, buff);
    print_stringp(buff, form, 0);
}
