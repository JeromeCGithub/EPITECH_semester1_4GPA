/*
** EPITECH PROJECT, 2019
** check square
** File description:
** check the square
*/

int check_b(char *str, int counter1, int counter2)
{
    for (int i = 0 ; str[i] != '\0' ; i++)
        if (str[i] != 'B' && str[i] != '\n')
            return (0);
    return (1);
}
