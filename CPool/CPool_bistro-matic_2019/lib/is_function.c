/*
** EPITECH PROJECT, 2019
** is_function
** File description:
** return 1 if the token is a function
*/

int is_function(char c)
{
    if (c == '*' || c == '/' || c == '%')
        return (1);
    return (0);
}
