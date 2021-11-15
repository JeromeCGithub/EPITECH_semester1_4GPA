/*
** EPITECH PROJECT, 2019
** my_str_isnum
** File description:
** Is my string a num only string.
*/

int my_str_isnum(char const *str)
{
    for (int i = 0 ; str[i] != '\0' ; i++)
    {
        if (str[i] < 48 || str[i] > 57)
            return (0);
    }
    return (1);
}
