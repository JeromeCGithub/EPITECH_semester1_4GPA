/*
** EPITECH PROJECT, 2019
** my_pushswap
** File description:
** main
*/

#include <my.h>

int main(int ac, char **av)
{
    sfVideoMode mode = {800, 600, 32};
    sfRenderWindow *windowA;
    sfRenderWindow *windowB;
   
    windowA = sfRenderWindow_create(mode, "List A", sfResize | sfClose, NULL);
    windowB = sfRenderWindow_create(mode, "List B", sfResize | sfClose, NULL);
    if(ac < 2)
        return (84);
    else if (ac < 3) {
        write(1, "\n", 1);
        return (0);
    }
    sfRenderWindow_setFramerateLimit(windowA, 60);
    sfRenderWindow_setFramerateLimit(windowB, 60);
    radix_s(ac, av, windowA, windowB);
    if (sfRenderWindow_isOpen(windowA))
        sfRenderWindow_close(windowA);
    if (sfRenderWindow_isOpen(windowB))
        sfRenderWindow_close(windowB);
    sfRenderWindow_destroy(windowA);
    return (0);
}
