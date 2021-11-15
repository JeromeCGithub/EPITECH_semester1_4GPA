/*
** EPITECH PROJECT, 2019
** my_isneg
** File description:
** A to know if the integer is positive or negative.
*/

void my_putchar(char c);

int my_isneg(int n)
{
    char negative = 'N';
    char positive = 'P';

    if (n < 0)
        my_putchar(negative);
    else
        my_putchar(positive);
    return (0);
}
