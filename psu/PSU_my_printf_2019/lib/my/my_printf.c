/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** main
*/

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <inttypes.h>
#include "../../include/my.h"

void cformat(void (**fptr)(format_t *, va_list),
            va_list arg, char const *format, format_t *form)
{
    int j = 0;
    char tab[] = "cdsiouxXbSp";

    for (j = 0 ; tab[j] != format[0] && tab[j] != '\0'
            && format[0] != '\0' ; j++);
    if (tab[j] == '\0') {
        my_putchar('%');
        my_putchar(format[0]);
        return;
    }
    (fptr[j])(form, arg);
}

void find_prec(char const *format, int spec_pos, format_t *form)
{
    int i = 0;
    int tmp = 0;

    for (i = 0 ; i != spec_pos ; i++){
        if (format[i] == '.' && format[i - 1] >= '0' && format[i - 1] <= '9') {
            form->width = my_getnbr(format);
            tmp = 1;
        }
        if (format[i] == '.') {
            form->precision = my_getnbr(&format[i + 1]);
            tmp = 1;
        }
    }
    for (i = 0 ; i != spec_pos ; i++) {
        if (format[i] <= '9' && format[i] >= '0' && tmp == 0) {
            form->width = my_getnbr(format);
        }
    }
}

void argument_traitement(char const *format, int spec_pos,
                        va_list arg, void (**fptr)(format_t *, va_list))
{
    int i = 0;
    int j = 0;
    int l = 0;
    format_t *form = malloc(sizeof(format_t));
    char modifi[] = "hljzt";

    form->precision = -1;
    form->width = 0;
    form->modifier = 0;
    for (i = 0 ; format[i] != format[spec_pos]
            && format[i] != modifi[j] ; i++)
        for (j = 0 ; modifi[j] != '\0' ; j++) {
            (format[i] == modifi[j]) ? form->modifier = modifi[j] : i;
            (format[i - 1] == modifi[j]) ? form->modifier = modifi[j] * 2 : i;
        }
    find_prec(format, spec_pos, form);
    find_flags(format, spec_pos, form);
    cformat(fptr, arg, &format[spec_pos], form);
    free(form);
}

int find_specifier(char const *format)
{
    int i = 0;
    int j = 0;
    int l = 0;
    char tab[] = "cdsiouxXbSp";

    for (i = 0 ; format[i] != '\0' && format[i] != tab[j] && l == 0 ; i++)
        for (j = 0 ; tab[j] != '\0' ; j++)
            (format[i] == tab[j]) ? l = 1 : i;
    i--;
    if (format[i] == '\0')
        return (0);
    return (i);
}

int my_printf(char const *format, ...)
{
    va_list arg;
    int spec_pos;
    void (**fptr)(format_t *, va_list);

    fptr = malloc(sizeof(void *) * 11);
    initfptr(fptr);
    va_start(arg, format);
    for (int i = 0 ; format[i] != '\0' ; i++) {
        if (format[i] == '%' && format[i + 1] != '%') {
            spec_pos = find_specifier(&format[i]);
            argument_traitement(&format[i], spec_pos, arg, fptr);
            i += spec_pos;
        } else if (format[i] == '%' && format[i + 1] == '%') {
            write(1, "%", 1);
            i++;
        } else
            write(1, &format[i], 1);
    }
    va_end(arg);
    free(fptr);
}
