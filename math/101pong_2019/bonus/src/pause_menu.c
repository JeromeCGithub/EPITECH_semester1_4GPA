/*
** EPITECH PROJECT, 2019
** pong
** File description:
** pause_menu
*/

#include "../include/my.h"

static void chose_button(sfRenderWindow *window, int *on_pause, int *i)
{
    if (sfKeyboard_isKeyPressed(sfKeyUp))
        *i = ((*i) + 1) % 2;
    if (sfKeyboard_isKeyPressed(sfKeyDown))
        *i = ((*i) + 1) % 2;
    if (sfKeyboard_isKeyPressed(sfKeyS))
        *i = ((*i) + 1) % 2;
    if (sfKeyboard_isKeyPressed(sfKeyZ))
        *i = ((*i) + 1) % 2;
    if (sfKeyboard_isKeyPressed(sfKeyEnter)) {
        (*i == 0) ? sfRenderWindow_close(window) : (0);
        (*i == 1) ? (*on_pause = 0) : (0);
    }
}

static void window_event_pause(sfRenderWindow *window, int *on_pause, int *i)
{
    sfEvent event;

    if (sfRenderWindow_pollEvent(window, &event)) {
        switch (event.type) {
        case sfEvtClosed:
            sfRenderWindow_close(window);
            break;
        case sfEvtKeyPressed:
            chose_button(window, on_pause, i);
            break;
        default:
            break;
        }
    }
}

void pause_menu(sfRenderWindow *window, back_t *back)
{
    sfTexture **texture = my_texture_create(2, "pack/pause_0.png");
    sfSprite *sprite = sfSprite_create();
    sfVector2i pos;
    int i = 0;
    int on_pause = 1;

    while (on_pause && sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        window_event_pause(window, &on_pause, &i);
        sfSprite_setTexture(sprite, texture[i], sfTrue);
        sfRenderWindow_drawSprite(window, back->sprite, NULL);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_display(window);
    }
    sfSprite_destroy(sprite);
    my_texture_destroy(2, texture);
}
