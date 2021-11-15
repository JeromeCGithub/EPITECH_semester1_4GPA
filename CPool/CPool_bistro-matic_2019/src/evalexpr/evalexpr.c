/*
** EPITECH PROJECT, 2019
** evalexpr
** File description:
** main
*/

#include <stdlib.h>
#include "../../include/my.h"
#include "../../include/bistromatic.h"

char *move_char(char const *str, char *new_str, char c, int *i)
{
    char temp;

    do {
        temp = str[*i];
        new_str[*i] = c;
        c = temp;
        (*i)++;
    } while (str[*i - 1] != '\0');
    return (new_str);
}

char *add_parenthesis2(char const *str, char *new_str, int i)
{
    char c = ')';
    char temp;
    int compteur = 0;

    if (str[i] == '(') {
        i++;
        compteur++;
    }
    for (; (str[i] <= '9' && str[i] >= '0') || compteur ; i++) {
        if (str[i] == '(') {
            compteur++;
        }
        if (str[i] == ')') {
            compteur--;
        }
    }
    i++;
    new_str = move_char(new_str, new_str, ')', &i);
    new_str[i - 1] = '\0';
    return (new_str);
}

char *add_parenthesis(char const *str, int i, char *new_str)
{
    char temp;
    char c = '(';
    int j = 0;

    new_str = malloc(sizeof(char) * (my_strlen(str) + 2));
    test_malloc(new_str);
    for (; str[j] != '\0' ; j++)
        new_str[j] = str[j];
    j = i;
    new_str = move_char(str, new_str, '(', &j);
    i++;
    return (add_parenthesis2(str, new_str, i));
}

char *eval_expr(char const *base, char const *ops,
                char const *expr, unsigned int size)
{
    char *new_str;

    new_str = string_traitement(expr);
    if (expr[0] == '/' || expr[0] == '*' || expr[0] == '%' ||
        expr[my_strlen(expr) - 1] == '*' || expr[my_strlen(expr) - 1] == '/' ||
        expr[my_strlen(expr) - 1] == '-' || expr[my_strlen(expr) - 1] == '+'
        || expr[my_strlen(expr) - 1] == '%'){
        my_putstr(SYNTAX_ERROR_MSG);
        exit(84);
    }
    synt_error(expr);
    verif_expr(expr, ops);
    verif_string(expr);
    verif_base(base, ops);
    verif_op(ops);
    for (int i = 0 ; new_str[i] != '\0' ; i++)
        if (is_function(new_str[i]) &&
            (new_str[i + 1] == '+' || new_str[i + 1] == '-'))
            new_str = add_parenthesis(new_str, i + 1, new_str);
    return (calc(to_npi(new_str)));
}
