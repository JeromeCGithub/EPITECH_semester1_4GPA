/*
** EPITECH PROJECT, 2019
** my_print_alpha
** File description:
** A function which beginning with a and display the alphabet
*/

void my_putchar(char c);

int my_print_alpha(void)
{
    int i = 0;

    for (i = 97 ; i <= 122 ; i++)
        my_putchar(i);
    return (0);
}
