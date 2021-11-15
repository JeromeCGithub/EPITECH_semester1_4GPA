/*
** EPITECH PROJECT, 2019
** my_rev_str
** File description:
** swap letters
*/

int my_strlen(char *str);

char *my_revstr(char *str)
{
    int i = 0;
    int j = 0;
    char temp = ' ';

    j = my_strlen(str) - 1;
    while (i < j) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
    return (str);
}
