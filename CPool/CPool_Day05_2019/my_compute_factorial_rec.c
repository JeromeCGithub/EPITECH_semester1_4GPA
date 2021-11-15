/*
** EPITECH PROJECT, 2019
** my_compute_factorial_rec
** File description:
** Do a factorial in recursive.
*/

int my_compute_factorial_rec(int nb)
{
    int result = 0;

    if (nb < 0 || nb > 12)
        return (0);
    else if (nb >= 1)
        return (nb * my_compute_factorial_rec(nb - 1));
    else
        return (1);
}
