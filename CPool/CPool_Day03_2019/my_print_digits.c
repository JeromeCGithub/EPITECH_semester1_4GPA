/*
** EPITECH PROJECT, 2019
** my_print_digits
** File description:
** A function which display all digits in ascending order.
*/

void my_putchar(char c);

int my_print_digits(void)
{
    int i = 0;

    for (i = 48 ; i <= 57 ; i++)
        my_putchar(i);
    return (0);
}
