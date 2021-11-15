/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** my func
*/

#include <stddef.h>
#include <inttypes.h>
#include <stdarg.h>

typedef struct flagstype {
    int hashtag;
    int zero;
    int less;
    int more;
    int space;
} flagstype_t;

typedef struct format {
    flagstype_t flags;
    int modifier;
    int precision;
    int width;
} format_t;

void find_flags(char const *format, int spec_pos, format_t *form);
void print_stringp(char const *buff, format_t *form, int caps);
void initfptr(void (**fptr)(format_t *, va_list));
char *my_strcpy(char *dest, char const *src);
void print_string(char const *buff, format_t *form);
int my_getnbr(char const *str);
int my_strlen(char const *str);
char *my_revstr(char *str);
int my_printf(char const *format, ...);
void cformat(void (**fptr)(format_t *, va_list), va_list arg,
            char const *format, format_t *form);
void my_puthex(format_t *form, va_list arg);
void my_putstr2(format_t *form, va_list arg);
void my_put_nbr(format_t *form, va_list arg);
intmax_t cast(intmax_t nb, format_t *form);
uintmax_t ucast(uintmax_t nb, format_t *form);
void my_putchar_2(format_t *form, va_list arg);
void my_putstr(format_t *form, va_list arg);
void my_put_octal(format_t *form, va_list arg);
void my_putunsigned_nbr(format_t *form, va_list arg);
void my_put_hexa(format_t *form, va_list arg);
void my_put_hexacaps(format_t *form, va_list arg);
void my_put_binary(format_t *form, va_list arg);
void my_putchar(char c);
