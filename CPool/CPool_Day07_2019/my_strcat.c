/*
** EPITECH PROJECT, 2019
** my_strcat
** File description:
** Concatenates 2 string.
*/

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int j = 0;

    while (dest[i] != '\0')
        i++;
    for (j = 0 ; src[j] != '\0' ; j++)
    {
        dest[i] = src[j];
        i++;
    }
    return (&dest[0]);
}
