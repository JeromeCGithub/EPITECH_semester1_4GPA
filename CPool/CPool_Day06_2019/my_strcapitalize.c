/*
** EPITECH PROJECT, 2019
** my_strcapitalize
** File description:
** Put first letter of each word in uppercase.
*/

char *my_strlowcase2(char *str)
{
    for (int i = 0 ; str[i] != '\0' ; i++) {
        if (str[i] <= 'Z' && str[i] >= 'A')
            str[i] += 32;
    }
    return (str);
}

char *my_strcapitalize(char *str)
{
    my_strlowcase2(str);
    for (int i = 0 ; str[i] != '\0' ; i++)
    {
        if (str[i] <= 122 && str[i] >= 97 && i == 0)
            str[i] -= 32;
        else if (str[i] <= 122 && str[i] >= 97 &&
                 (str[i - 1] < 48 || str[i - 1] > 122))
            str[i] -= 32;
    }
    return (str);
}
