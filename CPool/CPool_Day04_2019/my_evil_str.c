/*
** EPITECH PROJECT, 2019
** my_evil_str
** File description:
** Evil dark str.
*/

int my_strlen(char const *str);

char *my_evil_str(char *str)
{
    int i = 0;
    int j = 0;
    char last = ' ';

    j = my_strlen(str) - 1;
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
