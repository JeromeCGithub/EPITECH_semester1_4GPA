/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main bisstro
*/

#include <stdlib.h>
#include <unistd.h>
#include "../include/bistromatic.h"
#include "../include/my.h"

static char *get_expr(unsigned int size)
{
    char *expr;

    if (size <= 0) {
        my_putstr2(SYNTAX_ERROR_MSG);
        exit(EXIT_SIZE_NEG);
    }
    expr = malloc(size + 1);
    if (expr == 0) {
        my_putstr2(ERROR_MSG);
        exit(EXIT_MALLOC);
    }
    if (read(0, expr, size) != size) {
        my_putstr2(ERROR_MSG);
        exit(EXIT_READ);
    }
    expr[size] = 0;
    return (expr);
}

static void check_ops(char const *ops)
{
    if (my_strlen(ops) != 7) {
        my_putstr2(SYNTAX_ERROR_MSG);
        exit(EXIT_OPS);
    }
}

static void check_base(char const *b)
{
    if (my_strlen(b) < 2) {
        my_putstr2(SYNTAX_ERROR_MSG);
        exit(EXIT_BASE);
    }
}

int main(int ac, char **av)
{
    unsigned int size;
    char *expr;
    char *result;

    print_h(ac, av);
    if (ac != 4) {
        my_putstr("Usage: ./calc base ops\"()+_*/%\" exp_len\n");
        return (EXIT_USAGE);
    }
    check_base(av[1]);
    check_ops(av[2]);
    size = my_getnbr(av[3]);
    expr = get_expr(size);
    unknow_digit(expr, av[2], av[1]);
    expr = convert_to10(clean_str(expr, av[1], av[2]), av[1]);
    result = reconvert(eval_expr(av[1], av[2], expr, size), av[1], av[2]);
    my_putstr(result);
    free(result);
    return (EXIT_SUCCESS);
}
