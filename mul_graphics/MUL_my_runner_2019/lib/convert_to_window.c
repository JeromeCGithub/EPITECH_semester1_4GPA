/*
** EPITECH PROJECT, 2019
** my runner
** File description:
** convert
*/

#include <my.h>

float float_cv(sfRenderWindow *window, float nb, int indice)
{
    float tmp = nb * (-1);
    sfVector2u size = sfRenderWindow_getSize(window);

    size.y += 85;
    if (size.x == 1920)
        return (nb);
    else
        return (nb * powf(size.x / 1920.0, tmp + 1));
}

int int_cv(sfRenderWindow *window, int nb, int indice)
{
    sfVector2u size = sfRenderWindow_getSize(window);

    size.y += 85;
    return ((indice == 0) ? nb * size.x / 1920 : nb * size.y / 1080);
}

int int_pos_window(sfRenderWindow *window, int nb, int indice)
{
    sfVector2u size = sfRenderWindow_getSize(window);

    if (size.y == 995)
        size.y = 1080;
    return ((indice == 0) ? nb * size.x / 1920 : nb * size.y / 1080);
}

sfVector2f convert_vector2f(sfRenderWindow *window, float x, float y)
{
    sfVector2u size_win = sfRenderWindow_getSize(window);
    sfVector2f vector;

    vector.x = x * size_win.x / 1920;
    vector.y = y * size_win.y / 1080;
    return (vector);
}
