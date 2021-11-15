/*
** EPITECH PROJECT, 2019
** bistro-matic
** File description:
** my_memset
*/

char *my_memset(char *str, int len, char c)
{
    for (int i = 0 ; i < len ; i++)
        str[i] = c;
    str[len] = '\0';
    return (str);
}
