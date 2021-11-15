/*
** EPITECH PROJECT, 2019
** my_find_prime_sup
** File description:
** Find prime sup.
*/

int my_is_prime(int nb);

int my_find_prime_sup(int nb)
{
    int i = 0;
    int j = 0;

    j = my_is_prime(nb);
    if (j == 1)
        return (nb);
    while (i < 1)
    {
        i = my_is_prime(nb + 1);
        nb++;
    }
    return (nb);
}
