/*
** EPITECH PROJECT, 2019
** my_putstr
** File description:
** print str
*/

#include <stdlib.h>
#include <unistd.h>
#include "../../include/my.h"

void input_zero(char z)
{
    if (z < 8) {
        my_putchar('0');
        my_putchar('0');
    }
    else if (z < 64)
        my_putchar('0');
}

void my_put_octal2(unsigned int nb)
{
    if (nb == 0)
        return;
    my_put_octal2(nb / 8);
    my_putchar(nb % 8 + '0');
}

void my_putstr2(format_t *form, va_list arg)
{
    char *str = va_arg(arg, char *);

    for (int i = 0 ; str[i] != '\0' ; i++) {
        if (str[i] < 32 || str[i] >= 127) {
            my_putchar('\\');
            input_zero(str[i]);
            my_put_octal2(str[i]);
        }
        else
            write(1, &str[i], 1);
    }
}

void prec_w(format_t *form, char *str)
{
    if (form->precision <= my_strlen(str)) {
        if (form->precision == -1)
            form->precision = my_strlen(str);
        for (int j = 0 ; j < form->width - form->precision ; j++)
            write(1, " ", 1);
    }
    else {
        for (int j = 0 ; j < form->width - my_strlen(str) ; j++)
            write(1, " ", 1);
        if (form->precision == -1)
            form->precision = my_strlen(str);
    }
}

void my_putstr(format_t *form, va_list arg)
{
    int i = 0;
    char *str = va_arg(arg, char *);

    if (form->width == 0 && form->precision == 0) {
        for (int j = 0 ; str[j] != '\0' ; j++)
            write(1, &str[j], 1);
        return;
    }
    prec_w(form, str);
    while (str[i] != '\0' && i < form->precision) {
        my_putchar(str[i]);
        i++;
    }
}
