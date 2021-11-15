/*
** EPITECH PROJECT, 2019
** my_compute_power_it
** File description:
** Power it
*/

int my_compute_power_it(int nb, int p)
{
    int i = 0;
    int nb_origin = nb;

    if (p == 0)
        return (1);
    else if (p < 0)
        return (0);
    for (i = p; i > 1 ; i--)
        nb *= nb_origin;
    return (nb);
}
