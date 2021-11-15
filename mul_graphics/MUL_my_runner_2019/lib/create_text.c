/*
** EPITECH PROJECT, 2019
** my_hunter
** File description:
** create_text
*/

#include "../include/my.h"

sfText *create_text(char const *police, unsigned int taille,
                    sfVector2f position, char *contenue)
{
    sfFont *font = sfFont_createFromFile(police);
    sfText *text = sfText_create();

    sfText_setCharacterSize(text, taille);
    sfText_setPosition(text, position);
    sfText_setFont(text, font);
    sfText_setString(text, contenue);
    return (text);
}
