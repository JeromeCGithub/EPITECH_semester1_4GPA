/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** find flags
*/

#include "../../include/my.h"
#include <stdlib.h>

void init_flag(format_t *form)
{
    form->flags.hashtag = 0;
    form->flags.zero = 0;
    form->flags.less = 0;
    form->flags.space = 0;
    form->flags.more = 0;
}

void find_flags(char const *format, int spec_pos, format_t *form)
{
    init_flag(form);
    for (int i = 1 ; format[i] == ' ' || format[i] == '+' || format[i] == '#'
            || format[i] == '0' || format[i] == '-' ; i++)
        switch (format[i]) {
        case '#':
            form->flags.hashtag = 1;
            break;
        case '0':
            form->flags.zero = 1;
            break;
        case '-':
            form->flags.less = 1;
            break;
        case ' ':
            form->flags.space = 1;
            break;
        case '+':
            form->flags.more = 1;
        }
}
