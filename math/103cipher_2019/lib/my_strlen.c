/*
** EPITECH PROJECT, 2019
** 103cipher
** File description:
** my_strlen
*/

int my_strlen(char const *s)
{
    int i = 0;

    for (; s[i]; i++);
    return (i);
}
