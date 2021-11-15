/*
** EPITECH PROJECT, 2019
** my_str_isprintable
** File description:
** Is my string printable.
*/

int my_str_isprintable(char const *str)
{
    for (int i = 0 ; str[i] != '\0' ; i++)
    {
        if (str[i] < 32 || str[i] > 126)
            return (0);
    }
    return (1);
}
