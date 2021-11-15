/*
** EPITECH PROJECT, 2019
** pong
** File description:
** no_winner
*/

#include "../include/my.h"

static void move_choice(sfRenderWindow *window, int *i, int *play)
{
    if (sfKeyboard_isKeyPressed(sfKeyLeft))
        *i = ((*i) + 1) % 2;
    if (sfKeyboard_isKeyPressed(sfKeyRight))
        *i = ((*i) + 1) % 2;
    if (sfKeyboard_isKeyPressed(sfKeyEnter)) {
        (*i == 1) ? (*play = 1) : (0);
        (*i == 0) ? sfRenderWindow_close(window) : (0);
    }
}

static void window_event_gameov(sfRenderWindow *window, int *i, int *play)
{
    sfEvent event;

    if (sfRenderWindow_pollEvent(window, &event)) {
        switch (event.type) {
        case sfEvtClosed:
            sfRenderWindow_close(window);
            break;
        case sfEvtKeyPressed:
            move_choice(window, i, play);
            break;
        default:
            break;
        }
    }
}

void game_over(sfRenderWindow *window, int winner, back_t *back)
{
    sfTexture **texture = my_texture_create(4, "pack/game_over_1.png");
    sfSprite *sprite = sfSprite_create();
    int play = 0;
    int i = 0;

    while (!play && sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        window_event_gameov(window, &i, &play);
        sfSprite_setTexture(sprite, texture[i + winner], sfTrue);
        sfRenderWindow_drawSprite(window, back->sprite, NULL);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_display(window);
    }
}
