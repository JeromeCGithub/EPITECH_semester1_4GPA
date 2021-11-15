/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** init ptr
*/

#include "../../include/my.h"

void initfptr(void (**fptr)(format_t *, va_list))
{
    (fptr[0]) = (void *)&my_putchar_2;
    (fptr[1]) = (void *)&my_put_nbr;
    (fptr[2]) = (void *)&my_putstr;
    (fptr[3]) = (void *)&my_put_nbr;
    (fptr[4]) = (void *)&my_put_octal;
    (fptr[5]) = (void *)&my_putunsigned_nbr;
    (fptr[6]) = (void *)&my_put_hexa;
    (fptr[7]) = (void *)&my_put_hexacaps;
    (fptr[8]) = (void *)&my_put_binary;
    (fptr[9]) = (void *)&my_putstr2;
    (fptr[10]) = (void *)&my_puthex;
}
