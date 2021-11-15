/*
** EPITECH PROJECT, 2019
** Fir Tree
** File description:
** A Fir Tree.
*/

void my_putchar(char c);

int take_size(int size)
{
    int the_size = 7;
    int l = 6;
    int pair = 0;
    int modulo = 0;

    while (size > 1)
    {
        the_size = the_size + l;
        modulo = the_size % 2;
        if (modulo == 0)
            pair = 1;
        the_size = the_size + pair;
        l++;
        pair = 0;
        size--;
    }
    return (the_size);
}

void print_a_line(int **taille, int **size_space)
{
    int taille_needed = **taille;
    int i = 0;
    int size_space1 = **size_space;

    for (i = 0 ; i <= size_space1 ; i++)
        my_putchar(' ');
    while (taille_needed > 0)
    {
        my_putchar('*');
        taille_needed--;
    }
    my_putchar('\n');
    **size_space = **size_space - 1;
}

void print_a_block(int size_of_block, int *taille_line, int *size_space, int *h)
{
    int i = 0;

    while (size_of_block > 0)
    {
        print_a_line(&taille_line, &size_space);
        *taille_line = *taille_line + 2;
        size_of_block--;
        i++;
    }
    *size_space = *size_space + *h;
}

void print_trunk(int size)
{
    int size_spaces = 0;
    int i = 0;

    if (size <= 0)
        return;
    size_spaces = (take_size(size) / 2) - 1;
    for (i = 0 ; i <= size_spaces - (size / 2) ; i++)
        my_putchar(' ');
    if (size % 2 == 0)
        for (i = 0 ; i <= size ; i++)
            my_putchar('|');
    else
        for (i= 0 ; i < size ; i++)
            my_putchar('|');
    my_putchar('\n');
}

void tree(int size)
{
    int size_of_block = 4;
    int taille_line = 1;
    int i = 0;
    int j = 4;
    int h = 2;
    int size_space = (take_size(size) / 2) - 1;
    int size_origin = size;

    while (size > 0) {
        print_a_block(size_of_block, &taille_line, &size_space, &h);
        taille_line = taille_line - j;
        size_of_block++;
        size--;
        i++;
        if (i % 2 == 0 && i > 0) {
            j = j + 2;
            h++;
        }
    }
    for (i = 0 ; i < size_origin ; i++)
        print_trunk(size_origin);
}
