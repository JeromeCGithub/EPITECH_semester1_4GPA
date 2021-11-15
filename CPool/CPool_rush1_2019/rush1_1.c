
/*
** EPITECH PROJECT, 2019
** rush1-1
** File description:
** Rush 1 assignement 1
*/

void my_putchar(char c);

void is_dashorpipe(int x_place, int y_place, int x, int y)
{
    if (y_place == 0 || y_place == y - 1)
        my_putchar('-');
    else if (x_place != 0 && x_place < x - 1 && y_place > 0 && y_place < y - 1)
        my_putchar(' ');
    else
        my_putchar('|');
}

void is_oordash(int x_place, int y_place, int x, int y)
{
    if (y_place == 0 && x_place == x - 1)
        my_putchar('o');
    else if (y_place == y - 1 && x_place == x - 1)
        my_putchar('o');
    else
        is_dashorpipe(x_place, y_place, x, y);
}

void print_letter(int x_place, int y_place, int x, int y)
{
    if (y_place == 0 && x_place == 0)
        my_putchar('o');
    else if (x_place == 0 && y_place == y - 1)
        my_putchar('o');
    else
        is_oordash(x_place, y_place, x, y);
}

void rush (int x, int y)
{
    int x_place = 0;
    int y_place = 0;

    if (x <= 0 || y <= 0)
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
