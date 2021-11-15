/*
** EPITECH PROJECT, 2019
** 101pong
** File description:
** main
*/

#include "../include/my.h"

int main(void)
{
    sfVideoMode mode = {WIDTH, HEIGHT, BPX};
    sfRenderWindow *window = sfRenderWindow_create(mode, "101pong",
                                                   sfResize | sfClose, NULL);
    sfRenderWindow_setKeyRepeatEnabled(window, 1);
    main_screen(window);
    sfRenderWindow_destroy(window);
    return (0);
}
