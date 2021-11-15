/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** %o
*/

#include "../../include/my.h"
#include <stdlib.h>
#include <unistd.h>

void my_put_octal(format_t *form, va_list arg)
{
    int i = 0;
    char *buffer = malloc(sizeof(char) * 512);
    uintmax_t nb = va_arg(arg, uintmax_t);

    nb = ucast(nb, form);
    if (nb == 0) {
        write(1, "0", 1);
        return;
    }
    for (i = 0 ; nb != 0 ; i++) {
        buffer[i] = nb % 8 + '0';
        nb = nb / 8;
    }
    buffer[i] = '\0';
    buffer = my_revstr(buffer);
    if (form->flags.hashtag == 1)
        print_stringp(buffer, form, 2);
    else
        print_string(buffer, form);
}
