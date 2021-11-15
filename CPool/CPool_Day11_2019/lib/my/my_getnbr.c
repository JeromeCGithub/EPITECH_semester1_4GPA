/*
** EPITECH PROJECT, 2019
** my_getnbr
** File description:
** get a number in a string.
*/

int my_strlen(char const *str);

int is_negative(char const *str, int *j, long int *a)
{
    int p = 0;
    int r = 0;

    if (str == 0)
        return (-1);
    while (str[p] < '0' || str[p] > '9')
    {
        if (str[p] == '\0' && *a == 0)
            return (0);
        if (str[p] == '-')
            r++;
        p++;
        *j = *j + 1;
    }
    if (r % 2 == 1)
        return (1);
    if (r % 2 == 0)
        return (0);
    return (0);
}

int puissanc(int len)
{
    int number_up = 1;

    while (len != 0)
    {
        number_up *= 10;
        len--;
    }
    return (number_up);
}

int is_character(char const *str, int j)
{
    int h = 0;

    while (str[j] >= 48 && str[j] <= 57)
        j++;
    while (str[j] != '\0')
    {
        j++;
        h++;
    }
    return (h);
}

int my_getnbr(char const *str)
{
    int lenght = 0;
    int j = 0;
    long int a = 0;
    int z = 0;

    z = is_negative(str, &j, &a);
    if (z == -1)
        return (0);
    lenght = my_strlen(str) - j - is_character(str, j);
    while (str[j] >= 48 && str[j] <= 57 && str[j] != '\0')
    {
        lenght--;
        a += ((int)str[j] - 48) * puissanc(lenght);
        j++;
    }
    if (z == 1 && a <= 2147483648 && a > 0)
        return (a * (-1));
    else if (z == 0 && a <= 2147483647 && a > 0)
        return (a);
    return (0);
}
