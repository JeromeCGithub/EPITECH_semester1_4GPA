/*
** EPITECH PROJECT, 2019
** my_print_revalpha
** File description:
** A function which display alphabet in descending order.
*/

void my_putchar(char c);

int my_print_revalpha(void)
{
    int i = 0;

    for (i = 122 ; i >= 97 ; i--)
        my_putchar(i);
    return (0);
}
