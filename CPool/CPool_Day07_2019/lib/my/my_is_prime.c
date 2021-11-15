/*
** EPITECH PROJECT, 2019
** my_is_prime
** File description:
** Is prime in c.
*/

int my_is_prime(int nb)
{
    int i = 0;

    if (nb <= 0 || nb == 1)
        return (0);
    for (i = nb - 1 ; i > 1 ; i--)
    {
        if (nb % i == 0)
            return (0);
    }
    return (1);
}
