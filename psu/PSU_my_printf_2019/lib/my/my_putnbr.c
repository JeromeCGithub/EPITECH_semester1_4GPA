/*
** EPITECH PROJECT, 2019
** my_putnbr
** File description:
** put a nbr
*/

#include <unistd.h>
#include <stdlib.h>
#include "../../include/my.h"

void its_zero(format_t *form, char *buff)
{
    buff[0] = '0';
    buff[1] = '\0';
    if (form->flags.more == 1 && buff[my_strlen(buff) - 1] != '-') {
        buff[0] = '+';
        buff[1] = '0';
        buff[2] = '\0';
    }
    print_string(buff, form);
}

void flag_nbr(char *buff, format_t *form)
{
    if (form->flags.more == 1 && buff[my_strlen(buff) - 1] != '-') {
        buff[my_strlen(buff)] = '+';
        buff[my_strlen(buff) + 1] = '\0';
    }
    print_string(my_revstr(buff), form);
}

intmax_t neg(intmax_t nb, int *tmp)
{
    if (nb < 0) {
        nb = nb * (-1);
        *tmp = 1;
    }
    return (nb);
}

void my_put_nbr(format_t *form, va_list arg)
{
    char *buff = malloc(sizeof(char) * 512);
    int i = 0;
    int tmp = 0;
    intmax_t nb = va_arg(arg, intmax_t);

    nb = cast(nb, form);
    if (nb >= 0 && form->flags.more == 0 && form->flags.space == 1)
        form->flags.space = 2;
    if (nb == 0) {
        its_zero(form, buff);
        return;
    }
    nb = neg(nb, &tmp);
    for (; nb != 0 ; i++) {
        buff[i] = (nb % 10) + '0';
        nb = nb / 10;
    }
    (tmp == 1) ? (buff[i] = '-') : (buff[i] = '\0');
    buff[i + 1] = '\0';
    flag_nbr(buff, form);
}
