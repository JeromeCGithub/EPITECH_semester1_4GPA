/*
** EPITECH PROJECT, 2019
** bistro-matic
** File description:
** synthax error main
*/

#include "../include/my.h"
#include "../include/bistromatic.h"

int is_already_here(char const *str, char const c)
{
    int occurrences = 0;

    for (int i = 0 ; str[i] != '\0' ; i++)
        if (str[i] == c)
            occurrences++;
    if (occurrences > 1) {
        my_putstr2(SYNTAX_ERROR_MSG);
        return (EXIT_OPS);
    }
    return (0);
}

int verif_op(char const *str)
{
    int mandatory_size = 7;
    char c;

    if (my_strlen(str) != mandatory_size) {
        my_putstr2(SYNTAX_ERROR_MSG);
        return (EXIT_OPS);
    }
    for (int j = 0 ; str[j] != '\0' ; j++) {
        c = str[j];
        if (is_already_here(str, c) == EXIT_OPS)
            exit(EXIT_OPS);
    }
    return (0);
}

int verif_base(char const *base, char const *op)
{
    int tmp = 0;
    char c;

    for (int x = 0 ; op[x] != '\0' ; x++) {
        for (int i = 0 ; base[i] != '\0' ; i++) {
            tmp = (base[i] == op[x]) ? 1 : tmp;
        }
        if (tmp == 1) {
            my_putstr2(SYNTAX_ERROR_MSG);
            exit(EXIT_BASE);
        }
    }
    for (tmp = 0 ; base[tmp] != '\0' ; tmp++) {
        if (is_already_here(base, base[tmp]) == EXIT_OPS)
            exit(EXIT_BASE);
    }
    return (0);
}

int verif_string(char const *str)
{
    int open_par = 0;
    int close_par = 0;

    for (int i = 0 ; str[i] != '\0' ; i++) {
        if (str[i] == '(')
            open_par++;
        if (str[i] == '(' && str[i + 1] == ')')
            open_par += 2;
        if (str[i] == ')' && str[i + 1] == '(')
            open_par += 2;
        if (str[i] == ')')
            close_par++;
    }
    if (open_par != close_par) {
        my_putstr2(SYNTAX_ERROR_MSG);
        exit(EXIT_USAGE);
    }
    return (0);
}

int verif_expr(char const *str, char const *op_base)
{
    int tmp = 0;

    for (int i = 0 ; i < my_strlen(str) ; i++) {
        if (str[i] == op_base[4] || str[i] == op_base[5] ||
            str[i] == op_base[6] || str[i] == op_base[3] ||
            str[i] == op_base[2])
            tmp++;
        if (str[i + 1] == op_base[4] || str[i + 1] == op_base[5] ||
            str[i + 1] == op_base[6] || str[i + 1] == op_base[1])
            tmp++;
        if (tmp > 1) {
            my_putstr2(SYNTAX_ERROR_MSG);
            exit(EXIT_USAGE);
        } else {
            tmp = 0;
        }
    }
    return (0);
}
