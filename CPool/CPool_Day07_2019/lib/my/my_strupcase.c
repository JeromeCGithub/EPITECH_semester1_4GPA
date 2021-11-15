/*
** EPITECH PROJECT, 2019
** my_strupcase
** File description:
** All case with one more.
*/

char *my_strupcase(char *str)
{
    for (int i = 0 ; str[i] != '\0' ; i++) {
        if (str[i] <= 122 && str[i] >= 97)
            str[i] -= 32;
    }
    return (str);
}
