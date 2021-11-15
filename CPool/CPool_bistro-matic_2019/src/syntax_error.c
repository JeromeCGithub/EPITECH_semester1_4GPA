/*
** EPITECH PROJECT, 2019
** syntax_error
** File description:
** syntax error tmp
*/

#include "../include/bistromatic.h"
#include "../include/my.h"

void check_null(char const *str)
{
    if (str[0] == '\n') {
        my_putstr2(ERROR_MSG);
        exit (84);
    }
}

int is_operand2(char const c, char const *ops)
{
    for (int l = 0 ; ops[l] != '\0' ; l++)
        if (ops[l] == c)
            return (1);
    return (0);
}

int is_inbase(char const c, char const *base, char const *ops)
{
    for (int j = 0 ; base[j] != '\0' ; j++) {
        if (base[j] == c || is_operand2(c, ops) == 1)
            return (1);
    }
    return (0);
}

void unknow_digit(char const *str, char const *ops, char const *base)
{
    for (int i = 0 ; str[i] != '\0' ; i++) {
        if (is_inbase(str[i], base, ops) == 0) {
            my_putstr2(SYNTAX_ERROR_MSG);
            exit(84);
        }
    }
}

void synt_error(char const *str)
{
    int counter_parenthesis1 = 0;
    int counter_parenthesis2 = 0;

    check_null(str);
    for (int i = 0 ; str[i] != '\0' ; i++) {
        if (str[i] == '(')
            counter_parenthesis1 = counter_parenthesis1 + 1;
        else if (str[i] == ')')
            counter_parenthesis2 = counter_parenthesis2 + 1;
        if (counter_parenthesis1 < counter_parenthesis2) {
            my_putstr2(SYNTAX_ERROR_MSG);
            exit(84);
        }
    }
    if (counter_parenthesis1 != counter_parenthesis2) {
        my_putstr2(SYNTAX_ERROR_MSG);
        exit(84);
    }
}
