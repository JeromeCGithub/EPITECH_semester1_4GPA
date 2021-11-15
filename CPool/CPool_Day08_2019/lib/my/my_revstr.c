/*
** EPITECH PROJECT, 2019
** my_revstr
** File description:
** Reverse a string.
*/

int my_strlen2(char const *str)
{
    int z = 0;

    while (str[z] != '\0')
        z++;
    return (z);
}

char *my_revstr(char *str)
{
    int i = 0;
    int j = 0;
    char last = ' ';

    j = my_strlen2(str) - 1;
    while (i < j)
    {
        last = str[i];
        str[i] = str[j];
        i++;
        str[j] = last;
        j--;
    }
    return (str);
}
