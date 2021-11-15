/*
** EPITECH PROJECT, 2019
** pong
** File description:
** main_screen
*/

#include "../include/my.h"

static void chose_button_main(sfRenderWindow *window, int *i)
{
    if (sfKeyboard_isKeyPressed(sfKeyEscape))
        *i = 2;
    if (sfKeyboard_isKeyPressed(sfKeyUp))
        *i = ((*i) + 1) % 2;
    if (sfKeyboard_isKeyPressed(sfKeyDown))
        *i = ((*i) + 1) % 2;
    if (sfKeyboard_isKeyPressed(sfKeyEnter)) {
        (*i == 1) ? pong(window) : (0);
        (*i == 0) ? (sfRenderWindow_close(window)) : (0);
    }
}

static void window_event(sfRenderWindow *window, sfVector2i *pos, int *i)
{
    sfEvent event;

    if (sfRenderWindow_pollEvent(window, &event)) {
        switch (event.type) {
        case sfEvtClosed:
            sfRenderWindow_close(window);
            break;
        case sfEvtKeyPressed:
            chose_button_main(window, i);
            break;
        default:
            *pos = sfMouse_getPositionRenderWindow(window);
            break;
        }
    }
}

void main_screen(sfRenderWindow *window)
{
    sfTexture **texture = my_texture_create(3, "pack/accueil_0.png");
    sfSprite *sprite = sfSprite_create();
    sfVector2i pos;
    int i = 2;

    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        window_event(window, &pos, &i);
        sfSprite_setTexture(sprite, texture[i], sfTrue);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_display(window);
    }
    my_texture_destroy(3, texture);
}
