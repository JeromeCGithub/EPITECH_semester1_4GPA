/*
** EPITECH PROJECT, 2019
** get number pimed
** File description:
** get a number pimped
*/

int is_negativee(char const *str, int *j)
{
    int p = 0;
    int r = 0;

    if (str == 0)
        return (-1);
    while (str[p] == '-' || str[p] == '+')
    {
        if (str[p] == '-')
            r++;
        p++;
        *j = *j + 1;
    }
    if (str[p] < '0' || str[p] > '9')
        return (-1);
    if (r % 2 == 1)
        return (1);
    return (0);
}

int the_length(char const *str, int j)
{
    int l = 0;

    while (str[j] <= '9' && str[j] >= '0')
    {
        j++;
        l++;
    }
    return (l);
}

int puissanca(int len)
{
    int number_up = 1;

    while (len != 0)
    {
        number_up *= 10;
        len--;
    }
    return (number_up);
}

int my_get_nbr_pimped(char const *str)
{
    int is_neg = 0;
    int j = 0;
    long int number = 0;
    int length = 0;

    is_neg = is_negativee(str, &j);
    if (is_neg == -1)
        return (0);
    length = the_length(str, j);
    while (str[j] >= '0' && str[j] <= '9')
    {
        length--;
        number += ((int)str[j] - 48) * puissanca(length);
        j++;
    }
    if (is_neg == 1 && number <= 2147483648 && number > 0)
        return (number * (-1));
    else if (is_neg == 0 && number <= 2147483647 && number > 0)
        return (number);
    return (0);
}
