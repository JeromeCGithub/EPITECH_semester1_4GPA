/*
** EPITECH PROJECT, 2019
** my_put_nbr
** File description:
** Display number.
*/

void my_putchar(char c);

void my_putchar1(int nb)
{
    nb = nb + 48;
    my_putchar(nb);
}

int puissancee(int puissance)
{
    int nb = 1;

    while (puissance != 0)
    {
        nb = nb * 10;
        puissance--;
    }
    return (nb);
}

int count_digids(long int nb)
{
    int i = 0;

    while (1)
    {
        nb = nb / 10;
        if (nb == 0)
            return (i);
        i++;
    }
}

int my_put_nbr(int nb)
{
    long int nb_long = nb;
    long int new_nb = 0;
    long int last_nb = 0;
    int i = 0;
    int j = 0;

    if (nb_long < 0)
    {
        my_putchar('-');
        nb_long = nb_long * (-1);
    }
    last_nb = nb_long;
    new_nb = nb_long;
    for (i = count_digids(nb_long) ; i >= 0 ; i--)
    {
        j = puissancee(i);
        new_nb = last_nb / j;
        my_putchar1(new_nb);
        last_nb = last_nb % j;
    }
}
