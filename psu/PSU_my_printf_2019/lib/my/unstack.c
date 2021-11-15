/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** cast.c
*/

#include <sys/types.h>
#include <unistd.h>
#include "../../include/my.h"

intmax_t cast(intmax_t nb, format_t *form)
{
    switch (form->modifier) {
    case 'h':
        return ((short int)nb);
    case 'l':
        return ((long int)nb);
    case 2 * 'h':
        return ((char)nb);
    case 2 * 'l':
        return ((long long int)nb);
    case 'j':
        return ((intmax_t)nb);
    case 'z':
        return ((size_t)nb);
    case 't':
        return ((ptrdiff_t)nb);
    default:
        return ((int)nb);
    }
}

uintmax_t ucast(uintmax_t nb, format_t *form)
{
    switch (form->modifier) {
    case 'h':
        return ((unsigned short int)nb);
    case 'l':
        return ((unsigned long int)nb);
    case 2 * 'h':
        return ((unsigned char)nb);
    case 2 * 'l':
        return ((unsigned long long int)nb);
    case 'j':
        return ((uintmax_t)nb);
    case 'z':
        return ((ssize_t)nb);
    case 't':
        return ((ptrdiff_t)nb);
    default:
        return ((unsigned int)nb);
    }
}
