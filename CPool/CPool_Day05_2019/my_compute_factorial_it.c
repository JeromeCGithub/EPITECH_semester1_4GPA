/*
** EPITECH PROJECT, 2019
** my_compute_factorial_it
** File description:
** Factorial of the number.
*/

int my_compute_factorial_it(int nb)
{
    int i = 0;

    if (nb < 0)
        return (0);
    else if (nb == 0)
        return (1);
    else
        for (i = nb - 1 ; i > 0 ; i--)
        {
            if (nb < 0)
                return (0);
            nb *= i;
        }
    return (nb);
}
