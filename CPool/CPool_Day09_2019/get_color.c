/*
** EPITECH PROJECT, 2019
** get_color
** File description:
** get the color
*/

int get_color(unsigned char red, unsigned char green, unsigned char blue)
{
    int nb = 0;

    nb = nb + red;
    nb = nb << 8;
    nb = nb + green;
    nb = nb << 8;
    nb = nb + blue;
    return (nb);
}
