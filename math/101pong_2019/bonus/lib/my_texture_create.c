/*
** EPITECH PROJECT, 2019
** my_hunter
** File description:
** init
*/

#include "../include/my.h"

sfTexture **my_texture_create(int nb_sprite, char const *filepath)
{
    sfTexture **texture = malloc(sizeof(*texture) * nb_sprite);
    char *str = my_strdup(filepath);

    for (int i = 0; i < nb_sprite; i++, str[my_strlen(str) - 5]++)
        texture[i] = sfTexture_createFromFile(str, NULL);
    free(str);
    return (texture);
}
