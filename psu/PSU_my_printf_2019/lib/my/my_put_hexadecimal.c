/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** %x
*/

#include <unistd.h>
#include "../../include/my.h"
#include <stdlib.h>

void flag_hexacaps(char *buff, format_t *form)
{
    if (form->flags.hashtag == 1)
        print_stringp(buff, form, 1);
    else
        print_string(buff, form);
}

void flag_hexa(char *buff, format_t *form)
{
    if (form->flags.hashtag == 1)
        print_stringp(buff, form, 0);
    else
        print_string(buff, form);
}

void my_put_hexa(format_t *form, va_list arg)
{
    char *buff = malloc(sizeof(char) * 512);
    int i = 0;
    uintmax_t nb = va_arg(arg, uintmax_t);

    nb = ucast(nb, form);
    if (nb == 0) {
        buff[0] = '0';
        buff[1] = '\0';
        flag_hexa(buff, form);
    }
    for (; nb != 0 ; i++) {
        if (nb % 16 > 9)
            buff[i] = (nb % 16) + 'a' - 10;
        else
            buff[i] = (nb % 16) + '0';
        nb = nb / 16;
    }
    buff[i] = '\0';
    buff = my_revstr(buff);
    flag_hexa(buff, form);
}

void my_put_hexacaps(format_t *form, va_list arg)
{
    char *buff = malloc(sizeof(char) * 512);
    int i = 0;
    uintmax_t nb = va_arg(arg, uintmax_t);

    nb = ucast(nb, form);
    if (nb == 0) {
        write(1, "0", 1);
        return;
    }
    for (; nb != 0 ; i++) {
        if (nb % 16 > 9)
            buff[i] = (nb % 16) + 'A' - 10;
        else
            buff[i] = (nb % 16) + '0';
        nb = nb / 16;
    }
    buff[i] = '\0';
    buff = my_revstr(buff);
    flag_hexacaps(buff, form);
}
