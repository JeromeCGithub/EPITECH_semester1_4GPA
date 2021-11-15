
/*
** EPITECH PROJECT, 2019
** rush1-2
** File description:
** Rush 1 assignement 2
*/

void my_putchar(char c);

void print_star_only(int x, int y)
{
    int i = 0;
    int j = 0;

    for (i = 0 ; i < y ; i++)
    {
        for (j = 0 ; j < x ; j++)
            my_putchar('*');
        my_putchar('\n');
    }
}

void is_star_or_space(int x_place, int y_place, int x, int y)
{
    if (y_place == 0 || y_place == y - 1)
        my_putchar('*');
    else if (x_place != 0 && x_place < x - 1 && y_place > 0 && y_place < y - 1)
        my_putchar(' ');
    else
        my_putchar('*');
}

void is_slash_or_backslash(int x_place, int y_place, int x, int y)
{
    if (y_place == 0 && x_place == x - 1)
        my_putchar(92);
    else if (y_place == y - 1 && x_place == x - 1)
        my_putchar('/');
    else
        is_star_or_space(x_place, y_place, x, y);
}

void print_letter(int x_place, int y_place, int x, int y)
{
    if (y_place == 0 && x_place == 0)
        my_putchar('/');
    else if (x_place == 0 && y_place == y - 1)
        my_putchar(92);
    else
        is_slash_or_backslash(x_place, y_place, x, y);
}

void rush (int x, int y)
{
    int x_place = 0;
    int y_place = 0;

    if (x == 1 || y == 1)
    {
        print_star_only(x, y);
        return;
    }
    else if (x <= 0 || y <= 0)
    {
        write(2, "Invalid size\n", 13);
        return;
    }
    for (y_place = 0 ; y_place < y ; y_place++)
    {
        for (x_place = 0 ; x_place < x ; x_place++)
            print_letter(x_place, y_place, x, y);
        my_putchar('\n');
    }
}
