/*
** EPITECH PROJECT, 2019
** evalexpr
** File description:
** init output and op_stack for npi
*/

#include "include/my.h"

char *add0(char const *str, char *output, int *j)
{
    output[*j] = '0';
    (*j)++;
    if (str[1] == '-' || str[1] == '+') {
        output[*j] = ' ';
        (*j)++;
    }
    return (output);
}

char *add_operand(char *op_stack , char const *str, int *j, char *output)
{
    char temp;
    int i = 0;
    char c = *str;

    if (c == '(')
        output = add0(str, output, j);
    do {
        temp = op_stack[i];
        op_stack[i] = c;
        c = temp;
        i++;
    } while (op_stack[i - 1] != '\0');
    return (op_stack);
}

int len_op_stack(char const *str)
{
    int len = 0;

    for (int i = 0 ; str[i] != '\0' ; i++)
        if (is_operand(str[i]) || str[i] == '(' || str[i] == ')')
            len++;
    return (len);
}

int len_output(char const *str)
{
    int len = 0;
    int nb_parent = 0;

    for (int i = 0 ; str[i] != '\0' ; i++)
        if (is_operand(str[i]))
            len++;
    len = len * 2 + my_strlen(str) - nb_parent;
    return (len + 1);
}

char *my_memset(char *str, int len)
{
    for (int i = 0 ; i <= len ; i++)
        str[i] = '\0';
    return (str);
}
