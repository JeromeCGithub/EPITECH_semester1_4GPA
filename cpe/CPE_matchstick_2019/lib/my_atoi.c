/*
** EPITECH PROJECT, 2019
** my runner
** File description:
** my atoi
*/

int my_atoi(char const *str)
{
    int nb = 0;

    for (int i = 0 ; str[i] != '\0' ; i++)
        nb = nb * 10 + str[i] - '0';
    return (nb);
}
