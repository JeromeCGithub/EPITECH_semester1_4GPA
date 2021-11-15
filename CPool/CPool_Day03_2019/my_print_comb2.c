/*
** EPITECH PROJECT, 2019
** my_print_comb2
** File description:
** Print comb number 2
*/

void my_putchar(char c);

int display_numberr(int a, int b, int c, int d)
{
    int space = 32;
    int comma = 44;

    my_putchar(a);
    my_putchar(b);
    my_putchar(space);
    my_putchar(c);
    my_putchar(d);
    if (a == 57 && b == 56 && c == 57 && d == 57)
        return (0);
    my_putchar(comma);
    my_putchar(space);
}

void comparee(int a, int b, int c, int d)
{
    if (a < c)
        display_numberr(a, b, c, d);
    else if (a == c && b < d)
        display_numberr(a, b, c, d);
}

void c_d_boucle(int a, int b, int c, int d)
{
    for (c = 48 ; c <= 57 ; c++)
    {
        for (d = 48 ; d <= 57 ; d++)
        {
            comparee(a, b, c, d);
        }
    }
}

int my_print_comb2(void)
{
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    int space = 32;
    int comma = 44;

    for (a = 48 ; a <= 57 ; a++)
    {
        for (b = 48 ; b <= 57 ; b++)
        {
            c_d_boucle(a, b, c, d);
        }
    }
    return (0);
}
