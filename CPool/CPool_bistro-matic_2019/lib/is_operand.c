/*
** EPITECH PROJECT, 2019
** is_operand
** File description:
** return 1 if a char is an operand
*/

int is_operand(char c)
{
    if (c == '+' || c == '-' ||
        c == '*' || c == '/' || c == '%')
        return (1);
    return (0);
}
