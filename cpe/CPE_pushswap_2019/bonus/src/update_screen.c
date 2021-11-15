/*
** EPITECH PROJECT, 2020
** my pushswap
** File description:
** update screen
*/

#include <my.h>

void loop_final(sfRenderWindow *windowA, sfRenderWindow *windowB)
{
    sfEvent eventA;
    sfEvent eventB;

    while (sfRenderWindow_isOpen(windowA) || sfRenderWindow_isOpen(windowB)) {
        while (sfRenderWindow_pollEvent(windowA, &eventA))
            (eventA.type == sfEvtClosed) ? sfRenderWindow_close(windowA) : eventA;
        while (sfRenderWindow_pollEvent(windowB, &eventB))
            (eventB.type == sfEvtClosed) ? sfRenderWindow_close(windowB) : eventB;
    }
}

int find_high_nb(linked_list_t *list)
{
    int nb = 0;
    linked_list_t *the_list = list;

    while (the_list->next != list) {
        if (the_list->nb > nb)
            nb = the_list->nb;
        the_list = the_list->next;
    }
    return (nb);
}

void update_screen(linked_list_t **list, sfRenderWindow *windowA, sfRenderWindow *windowB)
{
    sfVector2f scale = {5, 600};
    sfVector2f position = {0, 0};
    sfColor color = {255, 255, 255, 255};
    linked_list_t *list_a = list[A]->prev;
    linked_list_t *list_b = list[B];

    if (!list_b && is_sorted(list[A])) {
        color.r = 0;
        color.g = 255;
        color.b = 0;
    }
    sfRenderWindow_clear(windowA, sfBlack);
    while (list_a && list_a->prev != list[A]->prev) {
        position.y = list_a->nb;
        sfRectangleShape_setFillColor(list_a->rect, color);
        sfRectangleShape_setSize(list_a->rect, scale);
        sfRectangleShape_setPosition(list_a->rect, position);
        sfRenderWindow_drawRectangleShape(windowA, list_a->rect, NULL);
        position.x += 10;
        list_a = list_a->prev;
    }
    sfRenderWindow_display(windowA);
    position.x = 0;
    sfRenderWindow_clear(windowB, sfBlack);
    while (list_b && list_b->prev != list[B]) {
        position.y = list_b->nb;
        sfRectangleShape_setSize(list_b->rect, scale);
        sfRectangleShape_setPosition(list_b->rect, position);
        sfRenderWindow_drawRectangleShape(windowB, list_b->rect, NULL);
        position.x += 10;
        list_b = list_b->prev;
    }
    sfRenderWindow_display(windowB);
}
