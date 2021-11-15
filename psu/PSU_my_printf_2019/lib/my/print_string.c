/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** print
*/

#include "../../include/my.h"
#include <unistd.h>

void flag_space(char const *buff, format_t *form)
{
    if (form->flags.space == 2) {
        write(1, " ", 1);
        form->width -= 1;
    }
    if (form->flags.more == 1)
        form->width -= 1;
}

void ecrire(format_t *form, char const *buff)
{
    for (int i = 0 ; i < form->precision - my_strlen(buff) ; i++)
        write(1, "0", 1);
    for (int i = 0 ; buff[i] != '\0' ; i++)
        write(1, &buff[i], 1);
}

void print_width(format_t *form, int len)
{
    if (form->flags.zero == 0)
        for (int i = 0 ; i < form->width - form->precision
                && i < form->width - len ; i++)
            write(1, " ", 1);
    else if (form->flags.zero == 1 && (form->precision == -1
                                        || form->precision == 0)) {
        for (int i = 0 ; i < form->width - form->precision
                && i < form->width - len ; i++)
            write(1, "0", 1);
    }
    else
        for (int i = 0 ; i < form->width - form->precision
                && i < form->width - len ; i++)
            write(1, " ", 1);
}

void print_string(char const *buff, format_t *form)
{
    int len = 0;
    int result = form->width - form->precision;

    if (buff[0] == '-') {
        len = my_strlen(buff) - 1;
        form->width -= 1;
    } else
        len = my_strlen(buff);
    flag_space(buff, form);
    print_width(form, len);
    if (buff[0] == '-') {
        write(1, "-", 1);
        buff = &buff[1];
    }
    else if (buff[0] == '+') {
        write(1, "+", 1);
        buff = &buff[1];
    }
    ecrire(form, buff);
}

void print_stringp(char const *buff, format_t *form, int caps)
{
    int len = 0;
    int result = form->width - form->precision;

    len = my_strlen(buff) + 2;
    for (int i = 0 ; i < result - 2 && i < form->width - len ; i++)
        write(1, " ", 1);
    if (caps == 1)
        write(1, "0X", 2);
    else if (caps == 2)
        write(1, "0", 2);
    else
        write(1, "0x", 2);
    for (int i = 0 ; i < form->precision - my_strlen(buff) ; i++)
        write(1, "0", 1);
    for (int i = 0 ; buff[i] != '\0' ; i++)
        write(1, &buff[i], 1);
}
