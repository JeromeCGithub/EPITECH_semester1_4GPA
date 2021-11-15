/*
** EPITECH PROJECT, 2019
** my_compute_square_root
** File description:
** Square root
*/

int my_compute_square_root(int nb)
{
    int i = 0;

    while (i * i < nb)
        i++;
    if (i * i == nb)
        return (i);
    return (0);
}
