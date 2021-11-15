/*
** EPITECH PROJECT, 2019
** eval_expr
** File description:
** eval expressions
*/

#include <stdlib.h>
#include "include/my.h"

static void is_a_nb(int const i, int *j, char const *str, char *output)
{
    if (str[i] <= '9' && str[i] >= '0') {
        output[*j] = str[i];
        (*j)++;
        if (!(str[i + 1] <= '9' && str[i + 1] >= '0')) {
            output[*j] = ' ';
            (*j)++;
        }
    }
}

static char *fill_output(int *j, char const token, char *output, char *op_stack)
{
    for (; op_precedence(op_stack[0], token) &&
            token != '(' ; (*j)++) {
        output[*j] = op_stack[0];
        (*j)++;
        output[*j] = ' ';
        op_stack = &op_stack[1];
    }
    op_stack = add_operand(op_stack, &token, j, output);
    return (op_stack);
}

static char *parenthesis(char *op_stack, char *output, int *j)
{
    for (; op_stack[0] != '(' ; (*j)++) {
        output[*j] = op_stack[0];
        (*j)++;
        output[*j] = ' ';
        op_stack = &op_stack[1];
    }
    if (op_stack[0] == '(')
        op_stack = &op_stack[1];
    return (op_stack);
}

static void fill_left_stacks(char *op_stack, int j, char *output)
{
    for (; is_operand(op_stack[0]) ; j++) {
        output[j] = op_stack[0];
        j++;
        output[j] = ' ';
        op_stack = &op_stack[1];
    }
}

char *to_npi(char const *str)
{
    int j = 0;
    char *output;
    char *op_stack;

    output = malloc((len_output(str)) * sizeof(char));
    output = my_memset(output, len_output(str));
    op_stack = malloc((len_op_stack(str)) * sizeof(char));
    op_stack = my_memset(op_stack, len_op_stack(str));
    for (int i = 0 ; str[i] != '\0' ; i++) {
        is_a_nb(i, &j, str, output);
        if (is_operand(str[i]))
            op_stack = fill_output(&j, str[i], output, op_stack);
        if (str[i] == '(')
            op_stack = add_operand(op_stack, &str[i], &j, output);
        if (str[i] == ')')
            op_stack = parenthesis(op_stack, output, &j);
    }
    fill_left_stacks(op_stack, j, output);
    return (output);
}
