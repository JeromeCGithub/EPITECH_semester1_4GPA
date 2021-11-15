/*
** EPITECH PROJECT, 2019
** my_str_isalpha
** File description:
** Is the string alpha.
*/

int my_str_isalpha(char const *str)
{
    int i = 0;

    for (i = 0 ; str[i] != '\0' ; i++)
    {
        if ((str[i] > 122 || str[i] < 97) && (str[i] < 65 || str[i] > 90))
            return (0);
    }
    return (1);
}
