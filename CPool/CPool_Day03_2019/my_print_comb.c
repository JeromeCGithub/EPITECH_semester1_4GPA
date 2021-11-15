/*
** EPITECH PROJECT, 2019
** my_print_comb
** File description:
** A function that displays some number.
*/

void my_putchar(char c);

void comma_space(void)
{
    int space = 32;
    int comma = 44;

    my_putchar(comma);
    my_putchar(space);
}

void display_number(int a, int b, int c)
{
    int space = 32;

    my_putchar(a);
    my_putchar(b);
    my_putchar(c);
    if (a != 55)
        comma_space();
}

void compare(int a, int b, int c)
{
    for (c = 48 ; c <= 57 ; c++)
    {
        if (a < b && b < c)
            display_number(a, b, c);
    }
}

int my_print_comb(void)
{
    int a = 0;
    int b = 0;
    int c = 0;

    for (a = 48 ; a <= 57 ; a++)
    {
        for (b = 48 ; b <= 57 ; b++)
        {
            compare(a, b, c);
        }
    }
    return (0);
}
