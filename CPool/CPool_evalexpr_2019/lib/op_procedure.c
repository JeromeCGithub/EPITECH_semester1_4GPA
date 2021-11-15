/*
** EPITECH PROJECT, 2019
** op_procedure
** File description:
** if the token have a greater precedence return 1
*/

#include "../include/my.h"

int op_precedence(char token, char first_stack)
{
    if (!(is_operand(first_stack) && is_operand(token)))
        return (0);
    if (token == '+' || token == '-')
        if (first_stack == '+' || first_stack == '-')
            return (1);
        else
            return (0);
    else if (token == '*' || token == '/' || token == '%')
        return (1);
    else
        return (0);
}
