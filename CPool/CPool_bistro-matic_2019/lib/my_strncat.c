/*
** EPITECH PROJECT, 2019
** my_strncat
** File description:
** Concatenates 2 string at n character.
*/

int my_nblen(char *src)
{
    int var = 0;

    if (src[var] == '-')
        var++;
    while (src[var] <= '9' && src[var] >= '0')
        var++;
    return (var);
}

char *my_strncat(char *dest, char *src, int nb)
{
    int j = 0;
    int i = 0;

    for (j = 0 ; j < nb ; j++)
    {
        dest[i] = src[j];
        i++;
    }
    return (&dest[0]);
}
