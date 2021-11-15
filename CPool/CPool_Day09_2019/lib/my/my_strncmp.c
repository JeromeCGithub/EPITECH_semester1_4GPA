/*
** EPITECH PROJECT, 2019
** my_strncmp
** File description:
** Compare 2 string under n.
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    while (s1[i] == s2[i] && i < n - 1)
    {
        if (s1[i] == '\0')
            return (0);
        i++;
    }
    if (s1[i] - s2[i] < 0)
        return (-1);
    else if (s1[i] - s2[i] > 0)
        return (1);
    else
        return (0);
}
