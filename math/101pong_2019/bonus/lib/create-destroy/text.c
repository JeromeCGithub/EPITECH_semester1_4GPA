/*
** EPITECH PROJECT, 2019
** pong
** File description:
** text
*/

#include "../../include/my.h"

text_t *create_text(char const *str)
{
    text_t *text = malloc(sizeof(text_t));

    text->str = my_strdup(str);
    text->sftext = sfText_create();
    text->font = sfFont_createFromFile("pack/arial.ttf");
    text->pos.x = (float)WIDTH * 0.5 - 80;
    text->pos.y = 20;
    sfText_setString(text->sftext, text->str);
    sfText_setFont(text->sftext, text->font);
    sfText_setCharacterSize(text->sftext, 50);
    sfText_setPosition(text->sftext, text->pos);
    return (text);
}

void destroy_text(text_t *text)
{
    free(text->str);
    sfText_destroy(text->sftext);
    sfFont_destroy(text->font);
    free(text);
}
